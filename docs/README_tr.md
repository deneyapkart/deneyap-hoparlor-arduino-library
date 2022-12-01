# Deneyap Hoparlör Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Hoparlör PAM8302A için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M29**, **mpv1.0**
- `MCU` PAM8302A
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 25,4 mm

## :closed_book:Dokümanlar
[Deneyap Hoparlör](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-module-deneyap-speaker-m29)

[Deneyap Hoparlör Şematik](https://cdn.deneyapkart.org/media/upload/userFormUpload/jK7N10tjlSvpvxTOBJTOzDI4mnhFc8Gt.pdf)

[Deneyap Hoparlör Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/oOS8e2k6AIGAZUH9mr5JS5CZf0Xf8JM1.pdf)

[PAM8302A-datasheet](https://www.diodes.com/assets/Datasheets/PAM8302A.pdf)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Hoparlör
Bu Arduino kütüphanesi, Deneyap Hoparlör'yı kullanmanızı sağlar. Bu kütüphaneyi Deneyap Kart ve Deneyap Kart 1A'da kullanabilirsiniz.
Diğer Deneyap Geliştirme Kartları için "MelodiCalma2" örneğini kullanın.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.1 - Örnek uygulama güncellendi

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Hoparlör ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

|Hoparlör| Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
|3.3V |3.3V Besleme Gerilimi| 3.3V    |
|GND  |Toprak|GND      |
|IN+  |Kuvvetlendirilmiş Hoparlör girişi| DAC |
|OUT+ |Hoparlör (+)|herhangi bir GPIO pin|
|OUT- |Hoparlör (-)| GND |
|SD   |Kapatma|Dijital pin|

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/LICENSE) dosyasını inceleyin.