/*
*****************************************************************************
@file         Deneyap_Hoparlor.h
@mainpage     Deneyap Speaker PAM8302A Arduino library header file
@version      v1.0.0
@date         August 09, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Speaker PAM8302A Arduino library
*****************************************************************************
*/

#pragma once
#include "MusicDefinition.h"

#define BUFFER_SIZE_DEFAULT 4000 // Size of buffer to store data to send to DAC. 3 bytes minimum!
                                 // 4000 bytes (Default) should allow for very slow main loops
                                 // that repeat only about every 100Hz, If your main loop is much faster
                                 // than this and the VAST majority will be you can safely reduce this size
                                 // without any issues down to an absolute minimum of 3 bytes
                                 // If you experience sound slowing down then you need to increase
                                 // Buffer memory. Which can be done in your code when you create the
                                 // DacAudio object
                                 // If your main loop is very very slow but you want to keep buffer
                                 // memory low then consider calling the DAC_Audio FillBuffer
                                 // routine more than once in you main loop. Although to be affective
                                 // they should not be called in quick succession but farther apart in
                                 // time on your main loop.
                                 // Use the routine MaxBufferUsage in your main loop to output the max
                                 // buffer memory (via serial monitor) that your loop is using, you can
                                 // then set you buffer memory very precisely
#define BytesPerSec 50000        // The rate at which bytes are sent to the DAC, note that the max
                                 // sample rate however is 44100Khz, this higher sampling rate allows
                                 // for samples to be increased in pitch. If a 44100 rate then the max
                                 // would be 3 x the pitch.

uint8_t SetVolume(uint8_t Volume); // returns the sound byte value adjusted for the volume passed

class Envelope; // forward ref for this class

class Filter_Class
{
  // base class for a filter, a filter is a device that manipulates the wave form
  // after it has been produced. Various are available inheriting from this class
public:
  virtual uint8_t FilterWave(uint8_t TheByte);
};

class FilterNoise : public Filter_Class
{
  // adds noise to a wave form, use min and max range to set lower and upper_bound
  // maximums for the noise. The value is added or removed from the passed in value
public:
  int8_t Min = -2; // These defaults have a range of 4 from -2 to +2
  int8_t Max = 2;

  FilterNoise(int8_t Min, int8_t Max);
  FilterNoise(int8_t AmountOfNoise);

  uint8_t FilterWave(uint8_t TheByte);
};

class PlayListItem
{
private:
protected:
public:
  // These are the linked list items for the sounds to play through the DAC:
  // Will be of use when multiple sounds can play at once using mixing
  PlayListItem *PreviousItem = nullptr;
  PlayListItem *NextItem = nullptr;
  Filter_Class *Filter = nullptr;

  bool Playing = false; // true if currently being played else false
  bool NewSound;        // When first set to play this will be true, once this
                        // sound has started sending bytes to the buffer it will be false
                        // Helps when setting NextFillPos (below) to initial value
  uint32_t PlayingTime; // Total playing time of this item in 1000's of a second
  uint32_t TimeElapsed; // Total playing time elapsed so far in 1000's of a second
  uint32_t TimeLeft;    // Total playing time left so far in 1000's of a second

  uint32_t NextFillPos; // Next fill position in buffer to fill, because we have
                        // a large buffer, all sounds need their individual fill positions
                        // because you could be playing one sound which has filled perhaps
                        // 2 seconds worth of buffer (but not yet played those 2 s)
                        // and then mix in another. In this situation the bytes from the new
                        // sound must be mixed at the current playing point. If you did
                        // not do this then your new sound would not start until about
                        // 2 seconds later and not when you intended.

  char Name[32];     // Name of this sound - optional, used mostly in debugging
  uint8_t LastValue; // Last value returned from NextByte function below
  uint8_t Volume = 127;    // volume 0 min, 127 max

  bool RepeatForever; // if true repeats forever, if true value for repeat below ignored
  uint16_t Repeat;    // Number of times to repeat, 1 to 65535
  uint16_t RepeatIdx; // internal use only, do not use, should put this in protected or
                      // private really and have an access function, do in future

  virtual uint8_t NextByte(); // to be overridden by any descendants
  virtual void Init();        // initialize any default values

  PlayListItem();
};

// The Main Wave class for sound samples
class Wav : public PlayListItem
{
private:
protected:
public:
  uint16_t SampleRate;
  uint32_t DataSize = 0; // The last integer part of count
  uint32_t DataStart;    // offset of the actual data.
  uint32_t DataIdx;
  const unsigned char *Data =nullptr;
  float IncreaseBy = 0;      // The amount to increase the counter by per call to "onTimer"
  float Count = 0;           // The counter counting up, we check this to see if we need to send
                             // a new byte to the buffer
  int32_t LastIntCount = -1; // The last integer part of count
  float SpeedUpCount = 0;    // The decimal part of the amount to increment the dataptr by for the
                             // next byte to send to the DAC. As we cannot move through data in
                             // partial amounts then we keep track of the decimal and when it
                             // "clicks over" to a new integer we increment the dataptr an extra
                             // "1" place.
  float Speed = 1.0;         // 1 is normal, less than 1 slower, more than 1 faster, i.e. 2
                             // is twice as fast, 0.5 half as fast., use the getter and setter
                             // functions to access. default is 1, normal speed

  // constructors
  Wav(const unsigned char *WavData);

  // functions
  uint8_t NextByte() override;
  void Init() override; // initialize any default values
};

// Envelope class for instruments to use, see www.xtronical.com for details
class EnvelopePart
{
  // Definition of a single part of a sound envelope

private:
  uint16_t Duration; // How long this part plays for in 1000's of a second

public:
  int8_t StartVolume = -1; // if 0-127 then this is volume to start this part at
  uint8_t TargetVolume;    // volume to reach in this part 0-127
  uint32_t RawDuration;    // duration ins 50,000's of a second
  bool Completed;

  EnvelopePart *PreviousPart =nullptr;
  EnvelopePart *NextPart =nullptr;

  // functions
  void SetDuration(uint16_t Duration);
  uint16_t GetDuration();
};

class Envelope
{
  // Envelope definition contains basically a linked list of Envelope parts
  // Using the envelope class you can have basic ADSR envelopes or more complex (or even simpler) ones
  // You can also have multiple envelopes per sound, so as one completes the next in list will start
  // This easily enables repeats of one envelope followed by a different one

public:
  EnvelopePart *FirstPart =nullptr;           // start of linked list of envelope parts
  EnvelopePart *LastPart =nullptr;            // start of linked list of envelope parts
  EnvelopePart *CurrentEnvelopePart =nullptr; // Current active envelope part

  Envelope *NextEnvelope =nullptr; // Next envelope of any
  uint8_t Repeats = 0;        // number of repeats
  uint8_t RepeatCounter;      // current repeat count used in code
  uint32_t DurationCounter;   // counts down until 0 for next envelope part
  float VolumeIncrement = 0;  // amount to increase volume by per sample
  float CurrentVolume = 0;
  bool EnvelopeCompleted; // Envelope completed

  Envelope();
  ~Envelope();
  void Init();
  EnvelopePart *AddPart(uint16_t Duration, uint16_t TargetVolume);                       // 0 to Max 127
  EnvelopePart *AddPart(uint16_t Duration, uint16_t StartVolume, uint16_t TargetVolume); // 0 to Max 127
  void InitEnvelopePart(EnvelopePart *EPart, uint8_t LastVolume);
  uint8_t NextByte(uint8_t ByteToPlay);
};

class Wave
{
  // Base wave class for all others to inherit from
  // Every Instrument must have a wave form class, by default if none specified
  // then uses square

protected:
  uint8_t CurrentByte = 255;
  float ChangeAmplitudeBy;
  float NextAmplitude;
  float CounterStartValue;
  float Counter;

public:
  uint16_t Frequency; // Note frequency
  virtual uint8_t NextByte();
  virtual void Init(int8_t Note);
};

class SquareWave : public Wave
{
  // Square wave class
public:
  uint8_t NextByte();
  void Init(int8_t Note);
};

class TriangleWave : public Wave
{
  // Square wave class
public:
  uint8_t NextByte();
  void Init(int8_t Note);
};

class SawToothWave : public Wave
{
  // Square wave class
public:
  uint8_t NextByte();
  void Init(int8_t Note);
};

class SineWave : public Wave
{
  // Square wave class
private:
  float AngleIncrement; // The amount the angle changes per sample
  float CurrentAngle;   // The angle of the current sample
public:
  uint8_t NextByte();
  void Init(int8_t Note);
};

// Instrument class, main class for producing sounds, from simple tones to more complex sounds
// on it's own it will only produce simple tones, but in combination with an
// envelope object it can be made to simulate more complex audio/ instruments
class Instrument_Class : public PlayListItem
{
  // max frequency depends on the type of wave being produced :
  // Square wave : 25Khz
  // Triangle :
  // Sawtooth :
  // Sine :
  // If you exceed the max then the max freq. will be used, no error returned

private:
  uint8_t CurrentByte;           // value currently being sent to DAC
  bool SoundCompleted;           // true when sound has completed - not the
  uint32_t SoundDurationCounter; // count down to 0 then stops sound,
  uint32_t DurationCounter;      // count down to 0 then marks as completed
  void ClearEnvelopes();

  // functions that set up instruments, called in the "SetInstrument" function below
  // must be private to stop calling directly and forgetting to clear any envelopes
  void SetDefaultInstrument();
  void SetPianoInstrument();
  void SetHarpsichordInstrument();
  void SetOrganInstrument();
  void SetSaxophoneInstrument();

public:
  int8_t Note = -1;              // as listed in MusicDefinitions.h
  uint32_t SoundDuration;        // Sound Duration, how long sound is heard
  uint32_t Duration;             // Duration before marked as completed
  uint16_t Frequency = 0;        // only used if you set an exact frequency, leave as 0 to use note
  Envelope *FirstEnvelope =nullptr;    // First envelope associated with this Instrument
  Envelope *CurrentEnvelope =nullptr;  // Current envelope in force
  Wave *WaveForm =nullptr;            // i.e. square, sawtooth, sine, triangle

  // Constructors
  Instrument_Class();
  Instrument_Class(int16_t InstrumentID);
  Instrument_Class(int16_t InstrumentID, uint8_t Volume);

  // functions
  uint8_t NextByte() override;
  void Init() override; // initialize any default values
  void SetNote(int8_t Note);
  void SetFrequency(uint16_t Freq);  // only if not using note property
  void SetDuration(uint32_t Length); // in millis
  void SetWaveForm(uint8_t WaveFormType);
  void SetInstrument(uint16_t Instrument);
  Envelope *AddEnvelope();
};

// Music Score class

class MusicScore : public PlayListItem
{
  // a class that handles basic musical scores (sheet music) to allow the play back of a single
  // musical score for 1 instrument, at present cannot handle chords

private:
  uint32_t ChangeNoteEvery;   // how often to change to a new note
                              // in 50,000's of a second (the internal
                              // sample rate sent to the DAC
                              // calculated from the tempo value below
  uint32_t ChangeNoteCounter; // countdown counter for the above
  uint16_t ScoreIdx;          // Index position of next note to play
public:
  Instrument_Class *Instrument=nullptr; // The instrument to use
  uint16_t Tempo;               // In Beats Per Min (as used in music)

  int8_t *Score =nullptr;  // the score itself, consists of the note
                     // and then optionally an alteration to the
                     // default duration. By default a note will
                     // play for 1 beat, if you pass a beat after
                     // note then it's the beat in 1/4 beats, i.e.
                     // 1 = 0.25 beat,2=0.5 beat, 3=0.75, 4=1 beat
                     // (the default) 5=1.25 beats etc. up to
                     // 126 (31.5 beats)
                     // The note should be passed as a negative value
                     // of the real index into the frequency array
                     // you do not need to worry about this if you
                     // use the preset defines in the Pitches.h
                     // file
                     // a value of -127 must be put at the end
                     // of the data to signify the end. Again use
                     // defines in Pitches.h

  // constructors
  MusicScore(int8_t *Score);
  MusicScore(int8_t *Score, uint16_t Tempo);
  MusicScore(int8_t *Score, uint16_t Tempo, Instrument_Class *Instrument);
  MusicScore(int8_t *Score, uint16_t Tempo, uint16_t InstrumentID);

  // override functions
  uint8_t NextByte() override;
  void Init() override;
  void SetInstrument(uint16_t InstrumentID);
};

// Sequence definitions

class SequenceItem_Class
{
  // An item that contains information about what to play and links to the next item
  // in the list of things to play
public:
  PlayListItem *PlayItem=nullptr;           // The item to play
  SequenceItem_Class *NextItem =nullptr;  // Next item to play
};

class Sequence : public PlayListItem
{
  // allows you to queue up many playlist items one after the other with minimum effort

private:
  SequenceItem_Class *CurrentItem=nullptr;  // current item playing from within the list
  SequenceItem_Class *FirstItem=nullptr;    // first play list item to play in linked list
  SequenceItem_Class *LastItem=nullptr;     // last play list item to play in linked list
  // the class itself is a playlist item
public:
  bool ClearAfterPlay=false;              // If true will clear the list of items after playing,
                              // ready for more new items
  uint8_t NextByte();
  void Init();
  void AddPlayItem(PlayListItem *PlayItem);
  void RemoveAllPlayItems(); // remove all play items
};

// the main class for using the DAC to play sounds
class Speaker
{

public:

  Speaker(uint8_t TheDacPin, uint8_t TimerNo);
  Speaker(uint8_t TheDacPin, uint8_t TimerNo, uint16_t PassedBufferSize);

    void FillBuffer();                    // Fills the buffer of values to send to the DAC, put in your
                                // main loop, see BUFFER_SIZE comments at top of code.
        uint8_t DacVolume = 100;                                // Audio Volume, Range is 0=Off to 100=Full Volume.  TEB Sep-16-2019
    uint8_t MixBytesToPlay();
    void Play(PlayListItem *Sound);
    void Play(PlayListItem *Sound,bool Mix);
    void StopAllSounds();
    bool AlreadyPlaying(PlayListItem *Item);
    void RemoveFromPlayList(PlayListItem *ItemToRemove);
    int BufferUsage();

    // debug
    void PrintPlayList();

};
