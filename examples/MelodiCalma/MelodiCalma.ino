/*
 *   Melodi çalma örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Daha dün annemizin ninnisinin melodi verilerinin çalsırılması örneği
 *   
 *   Bu örnek DENEYAP MİNİ kartını desteklememektedir.
 *   
 *   Hoparlör | Geliştirme Kartı
 *   IN+      | DAC1
 *   3V3      | 3.3V
 *   GND      | GND
 *
 *   Bu örnek Deneyap Hoparlör için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-hoparlor-arduino-library  <------
 *
 */

#include <Deneyap_Hoparlor.h>                                         // Deneyap_Hoparlor kutuphanesi eklenmesi

/* Melodinin nota verileri. Bu verileri istediğiniz melodi ile değiştirebilinir
   Notalar -> https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/src/MusicDefinitions.h */
int8_t PROGMEM DahaDunAnnemizin[] = {
    NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, BEAT_2,
    NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, BEAT_2,
    NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, BEAT_2,
    NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, BEAT_2,
    NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, BEAT_2,
    NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, BEAT_4,
    NOTE_SILENCE, BEAT_5, SCORE_END};

Speaker Speaker(25, 0);                                               // Speaker için class tanımlaması. DAC1(GPIO 25) pini ve timer seçimi

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
