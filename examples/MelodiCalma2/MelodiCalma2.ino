/*
 *   Melodi çalma 2 örneği,
 *
 *   Daha dün annemizin ninnisinin melodi verilerinin çalsırılması örneği
 *   Notalar -> https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/libraries/00_Tone/src/pitches.h
 *   
 *   Hoparlör | Geliştirme Kartı
 *   IN+      | Herhangi bir GPIO pini
 *   3V3      | 3.3V
 *   GND      | GND
 *
 *   Bu örnek Deneyap Hoparlör için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-hoparlor-arduino-library  <------
 *
 */
 
#include <Tone32.h>

#define SpeakerPin A0
#define Frequency 500

void setup() {}

void loop() {
  tone(SpeakerPin, NOTE_C5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_C5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_A5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_A5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);

  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_D5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_D5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_C5, Frequency, 0);
  noTone(SpeakerPin, 0);

  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_D5, Frequency, 0);
  noTone(SpeakerPin, 0);

  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_D5, Frequency, 0);
  noTone(SpeakerPin, 0);  

  tone(SpeakerPin, NOTE_C5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_C5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_A5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_A5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_G5, Frequency, 0);
  noTone(SpeakerPin, 0);  

  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_F5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_E5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_D5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_D5, Frequency, 0);
  noTone(SpeakerPin, 0);
  tone(SpeakerPin, NOTE_C5, Frequency, 0);
  noTone(SpeakerPin, 0);
}
