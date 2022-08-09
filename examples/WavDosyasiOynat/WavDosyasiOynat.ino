// ---------->>>>>>>>>> YUKLEME YAPILAMDAN DIKKAT EDILMESI GEREKEN HUSUS <<<<<<<<<<----------
// "Araclar->Partition Scheme->Huge APP" secilmeli //
// "Tools->Partition Scheme->Huge APP" secilmeli //
/*
 *   Hexa dönüştürülmüş .wav dosyasının oynatılması örneği,
 *
 *   Dönüştürülmüş .wav dosyası oynatılmaktadır. 
 *   
 *   DENEYAP MİNİ kartını desteklememektedir.
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
#include "SoundData.h"                                                // Dönüştürülmüş .wav dosyasının eklenmesi

Speaker Speaker(25,0);                                                // Speaker için class tanımlaması. DAC1(GPIO 25) pini ve timer seçimi

/*.wav dosyası nasıl hex dönüşür: https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/tree/master/examples/KelimeSoylet */ 
Wav StarWars(StarWarsWav);                                            //  Wav türünde dönüştürülen sample verisi

void setup() {
  StarWars.RepeatForever=false;                                       // Sample sonsuz oynatılması
  Speaker.Play(&StarWars);                                            // Oynatmak için ayarlanması
}


void loop() {
  Speaker.FillBuffer();                                               // Ses arabelleğini verilerle doldurulması
}
