# Deneyap Hoparlör PAM8302A Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Hoparlör PAM8302A için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M29**, **mpv1.0**
- `MCU` PAM8302A
- `Ağırlık`
- `Modul Boyutları` 

## :closed_book:Dokümanlar
Deneyap Hoparlör PAM8302A

[PAM8302A](https://www.diodes.com/assets/Datasheets/PAM8302A.pdf)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Hoparlör PAM8302A
Bu Arduino kütüphanesi, Deneyap Hoparlör PAM8302A'yı kullanmanızı sağlar. Bu kütüphaneyi Deneyap Kart ve Deneyap Kart 1A'da kullanabilirsiniz.

Deneyap Mini için "MelodiCalma2" örneğini kullanın.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Hoparlör ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

|Hoparlör| Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     | Güç    | 3.3V    |
| GND      | Toprak |GND      |
|IN+  | Input   | DAC |
|OUT+ | Input   |herhangi bir GPIO pin|
|OUT- | Input   | GND |
|SD   |    |   |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/LICENSE) dosyasını inceleyin.