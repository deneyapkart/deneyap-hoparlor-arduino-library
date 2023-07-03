/*
 *   MelodiCalma2 örneği,
 *   Daha dün annemizin ninnisinin melodi verilerinin çalsırılması örneği
 *
 *   Hoparlör | Geliştirme Kartı
 *   IN+      | D0 (herhangi bir GPIO pini)
 *   3v3      | 3.3V
 *   GND      | GND
*/
#include "pitches.h"

#define SpeakerPin D0
#define Frequency 500

void setup() {
}

/*  Melodinin nota verileri -> https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/src/MusicDefinition.h
    Bu veriler ile istediğiniz melodileri oluşturabilirsiniz.*/
void loop() {
  tone(SpeakerPin, NOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);

  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_C5, Frequency);
  noTone(SpeakerPin);

  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_D5, Frequency);
  noTone(SpeakerPin);

  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_D5, Frequency);
  noTone(SpeakerPin);  

  tone(SpeakerPin, NOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_G5, Frequency);
  noTone(SpeakerPin);  

  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, NOTE_C5, Frequency);
  noTone(SpeakerPin);
}
