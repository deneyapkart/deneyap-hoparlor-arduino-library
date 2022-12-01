/*
 *   MelodiCalma örneği,
 *
 *   Daha dün annemizin ninnisinin melodi verilerinin çalıştırılması örneği
 *   
 *   Bu örnek yalnızca Deneyap Kart ve Deneyap Kart 1A'yı kartını desteklemektedir.
 *   
 *   Hoparlör | Geliştirme Kartı
 *   IN+      | DAC1
 *   3V3      | 3.3V
 *   GND      | GND
 *   
 *   Bu örnek Deneyap Hoparlör için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-speaker-m29  <------
 *      ------>  https://github.com/deneyapkart/deneyap-hoparlor-arduino-library  <------
*/
#include <Deneyap_Hoparlor.h>                                        // Deneyap Hoparlör kutuphanesi eklenmesi

/*  Melodinin nota verileri -> https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/src/MusicDefinition.h
    Bu veriler ile istediğiniz melodileri oluşturabilirsiniz.*/
int8_t PROGMEM DahaDunAnnemizin[] = {
    NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, BEAT_2,
    NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, BEAT_2,
    NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, BEAT_2,
    NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, BEAT_2,
    NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, BEAT_2,
    NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, BEAT_4,
    NOTE_SILENCE, BEAT_5, SCORE_END};

Speaker Speaker(DAC1, 0);                                             // Speaker için class tanımlaması. (DAC1, 0): DAC pini ve timer seçimi

/*
 * INSTRUMENT_PIANO
 * INSTRUMENT_HARPSICHORD
 * INSTRUMENT_ORGAN
 * INSTRUMENT_SAXOPHONE
 */
MusicScore Music(DahaDunAnnemizin, TEMPO_ALLEGRO, INSTRUMENT_PIANO);  // melodi verileri, tempo, enstrüman

void setup() {
    Music.Repeat = 1;                                                 // Bir kere tekrarlanması
    Speaker.Play(&Music);
}

void loop() {
    Speaker.FillBuffer();                                             // Bu fonksiyon loop içinde olmalıdır
}
