# Deneyap Speaker PAM8302A Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Speaker PAM8302A

## :mag_right:Specifications 
- `Product ID` **M29**, **mpv1.0**
- `MCU` PAM8302A
- `Weight` 
- `Module Dimension`

## :closed_book:Documentation
Deneyap Speaker PAM8302A

[PAM8302A](https://www.diodes.com/assets/Datasheets/PAM8302A.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Speaker PAM8302A
This Arduino library allows you to use Deneyap Speaker PAM8302A. You can use this library in Deneyap Kart and Deneyap Kart 1A.

Use the example of "MelodiCalma2" for the Deneyap Mini. 

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Speaker and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|Speaker| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|IN+  | Input   | DAC |
|OUT+ | Input   | any GPIO pin |
|OUT- | Input   | GND |
|SD   |    |   |

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-hoparlor-arduino-library/blob/master/LICENSE) file for license information.

Based on XT_DAC_Audio Arduino Library. Changed to work with Deneyap Speaker PAM8302A.