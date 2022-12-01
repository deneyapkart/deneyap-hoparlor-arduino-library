/*
 *   MelodiCalma2 örneği,
 *   Daha dün annemizin ninnisinin melodi verilerinin çalsırılması örneği
 *
 *   Hoparlör | Geliştirme Kartı
 *   IN+      | D0 (herhangi bir GPIO pini)
 *   3v3      | 3.3V
 *   GND      | GND
 *
 *   Bu örnek Deneyap Hoparlör için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-speaker-m29  <------
 *      ------>  https://github.com/deneyapkart/deneyap-hoparlor-arduino-library  <------
*/
#include <Deneyap_Hoparlor.h>   // Deneyap Hoparlör kutuphanesi eklenmesi

#define SpeakerPin D2
#define Frequency 500

void setup() {
}

/*  Melodinin nota verileri -> https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/src/MusicDefinition.h
    Bu veriler ile istediğiniz melodileri oluşturabilirsiniz.*/
void loop() {
  tone(SpeakerPin, FNOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);

  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_C5, Frequency);
  noTone(SpeakerPin);

  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_D5, Frequency);
  noTone(SpeakerPin);

  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_D5, Frequency);
  noTone(SpeakerPin);  

  tone(SpeakerPin, FNOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_C5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_A5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_G5, Frequency);
  noTone(SpeakerPin);  

  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_F5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_E5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_D5, Frequency);
  noTone(SpeakerPin);
  tone(SpeakerPin, FNOTE_C5, Frequency);
  noTone(SpeakerPin);
}
