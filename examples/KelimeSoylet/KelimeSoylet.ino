/*
 *   KelimeSoylet örneği,
 *
 *   Seri port ekranına yazılan rakama karşılık gelen Türkçe kelimeleri Deneyap Hoparlör ile çaldırmaktadır.
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
#include <Deneyap_Hoparlor.h>                     // Deneyap Hoparlör kutuphanesi eklenmesi
#include "SoundData.h"                            // Hex dönüştürülmüş .wav dosyasının eklenmesi

Speaker Speaker(DAC1, 0);                         // Speaker için class tanımlaması. (DAC1, 0): DAC pini ve timer seçimi
Sequence Sequence;

/* Kelime ses verileri */
Wav Sol(SolWav);
Wav Sag(SagWav);
Wav Geri(GeriWav);
Wav Ileri(IleriWav);
Wav Evet(EvetWav);
Wav Ac(AcWav);
Wav Yukari(YukariWav);
Wav Asagi(AsagiWav);
Wav Dur(DurWav);
Wav Baslat(BaslatWav);

void setup() {
    Serial.begin(115200);                         // Seri haberleşme başlatılması
}

void loop() {
    Speaker.FillBuffer();                         // Ses arabelleğini verilerle doldurulması

    if (Serial.available())
        PlayWords(Serial.readString().c_str());
}

/*Karakterin oynatılması fonksiyonu */
void PlayWords(char const *Words) {
    int WordChars = strlen(Words);
    Sequence.RemoveAllPlayItems();
    for (int i = 0; i < WordChars; i++)
        AddWordsToSequence(Words[i]);
    Speaker.Play(&Sequence);
    Serial.println(Words);
}

/* Yazılan Kelimenin wav verisinin eklenmesi fonksiyonu*/
void AddWordsToSequence(char TheWords) {
    switch (TheWords) {
    case '0' : Sequence.AddPlayItem(&Evet);break;
    case '1' : Sequence.AddPlayItem(&Ac);break;
    case '2' : Sequence.AddPlayItem(&Sag);break;
    case '3' : Sequence.AddPlayItem(&Geri);break;
    case '4' : Sequence.AddPlayItem(&Ileri);break;
    case '5' : Sequence.AddPlayItem(&Sol);break;
    case '6' : Sequence.AddPlayItem(&Yukari);break;
    case '7' : Sequence.AddPlayItem(&Asagi);break;
    case '8' : Sequence.AddPlayItem(&Dur);break;
    case '9' : Sequence.AddPlayItem(&Baslat);break;
    }
}
