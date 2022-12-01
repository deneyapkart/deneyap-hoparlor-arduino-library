// ---------->>>>>>>>>> YUKLEME YAPILAMDAN DIKKAT EDILMESI GEREKEN HUSUS <<<<<<<<<<----------
// "Araclar->Partition Scheme->Huge APP" secilmeli //
// "Tools->Partition Scheme->Huge APP" secilmeli //
/*
 *   WavDosyasiOynat örneği,
 *
 *   Dönüştürülmüş .wav dosyası oynatılmaktadır. 
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
#include <Deneyap_Hoparlor.h>                                         // Deneyap Hoparlör kutuphanesi eklenmesi
#include "SoundData.h"                                                // Dönüştürülmüş .wav dosyasının eklenmesi

Speaker Speaker(DAC1, 0);                                             // Speaker için class tanımlaması. (DAC1, 0): DAC pini ve timer seçimi

Wav StarWars(StarWarsWav);                                            //  Wav türünde dönüştürülen sample verisi

void setup() {
  StarWars.RepeatForever=false;                                       // Sample sonsuz oynatılması
  Speaker.Play(&StarWars);                                            // Oynatılan dosyanın yazılması
}


void loop() {
  Speaker.FillBuffer();                                               // Ses arabelleğini verilerle doldurulması
}
