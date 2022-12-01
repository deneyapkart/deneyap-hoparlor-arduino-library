# Deneyap Speaker Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Speaker PAM8302A

## :mag_right:Specifications 
- `Product ID` **M29**, **mpv1.0**
- `MCU` PAM8302A
- `Weight` 
- `Module Dimension` 25,4 mm x 25,4 mm

## :closed_book:Documentation
[Deneyap Speaker](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-module-deneyap-speaker-m29)

[Deneyap Speaker Shematic](https://cdn.deneyapkart.org/media/upload/userFormUpload/jK7N10tjlSvpvxTOBJTOzDI4mnhFc8Gt.pdf)

[Deneyap Speaker Mechanical Drawing](https://cdn.deneyapkart.org/media/upload/userFormUpload/oOS8e2k6AIGAZUH9mr5JS5CZf0Xf8JM1.pdf)

[PAM8302A-datasheet](https://www.diodes.com/assets/Datasheets/PAM8302A.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Speaker
This Arduino library allows you to use Deneyap Speaker . You can use this library in Deneyap Kart and Deneyap Kart 1A.
Use the example of "MelodiCalma2" for the other Deneyap development boards. 

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.1 - updated sketches

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Speaker and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|Speaker| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|IN+  |Amplified Speaker Input pin|DAC&GPIO pin|
|OUT+ |Speaker (+)| any GPIO pin |
|OUT- |Speaker (-)| GND |
|SD   |Closed|Digital pin|

## :bookmark_tabs:License Information
Based on XT_DAC_Audio Arduino Library. Changed to work with Deneyap Speaker PAM8302A.

Please review the [LICENSE](https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/LICENSE) file for license information.
