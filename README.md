<div style="text-align:center" align="center">
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Main.png" alt="Give A Star logo" width="500"/>
</div>

<h3 style="text-align:center" align="center">A Star PCB Board based on the ESP32-S2 and D1 Mini to teach the basics of soldering</h3>

## Features
- Five Different LED Animations
- Change Animations by Clicking Button
- Teach the Basics of Soldering
- Great for Beginners

## Components
| Component | Purpose |
| --- | --- |
| **ESP32-S2** OR **ESP8266 D1 Mini** | Manage animations and code
| 128x64 SSH1106 OLED | Write a visual message to someone |
| Tactile Push Button | Change light animation |
| 6x LED | Display animations |
| 6x 100ohm Resistors | Manage voltage |

## Hardware Setup
**Top LED** 
| LED Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| VIN | 9 | D6 |
| GND | GND | GND |

**Right LED** 
| LED Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| VIN | 7 | D5 |
| GND | GND | GND |

**Bottom Right LED** 
| LED Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| VIN | 5 | D0 |
| GND | GND | GND |

**Left LED** 
| LED Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| VIN | 11 | D7 |
| GND | GND | GND |

**Bottom Left LED** 
| LED Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| VIN | 12 | D8 |
| GND | GND | GND |

**OLED SSH1106** 
| OLED Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| VCC | 3V3 | 3V3 |
| GND | GND | GND |
| SCK | 35 | D1 |
| SDA | 33 | D2 |

**Push Button** 
| Button Pin | ESP32-S2 Pin | D1 Mini Pin |
| --- | --- | --- |
| 1 | 3V3 | 3V3 |
| 2 | 16 | D4 |
| 2 | GND | GND |


## Breadboard
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Breadboard.png" alt="Give A Star schematic" width="700"/>

## Schematic
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Schematic.png" alt="Give A Star schematic" width="700"/>

## PCB Design
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Design_PCB.png" alt="Give A Star PCB Design" width="500"/>

<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Front_PCB.png" alt="Give A Star PCB Front" width="400"/><img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Back_PCB.png" alt="Give A Star PCB Back" width="400"/>

## Photos
<img src="https://github.com/angelina-tsuboi/Give-A-Star/blob/main/assets/Star_IMG_1.png" alt="Give A Star Photo 1" width="400" marginLeft="10"/>&nbsp;&nbsp;<img src="https://github.com/angelina-tsuboi/Give-A-Star/blob/main/assets/Star_IMG_2.png" alt="Give A Star Photo 2" width="415" height="446"/>

## Set up
- Arduino IDE with the following URL added under Preferences -> Additional board manager URL's: http://arduino.esp8266.com/stable/package_esp8266com_index.json (D1 Mini) OR https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json (ESP32-S2)

- ESP8266 boards added in Arduino IDE by going to Tools -> Boards -> Boards Manager, and installing ESP8266 by ESP8266 Community (D1 Mini)

- ESP32 boards added in Arduino IDE by going to Tools -> Boards -> Boards Manager, and installing ESP32 by Expressif Systems (ESP32-S2)

- Install Zip file from https://github.com/wonho-maker/Adafruit_SH1106 and unzip the file inside Arduino -> libraries

- Adafruit GFX library installed in Arduino IDE by going to Sketch -> Include Library -> Manage Libraries and installing "Adafruit GFX Library" by Adafruit

- Optional: Depending on which type of OLED screen you use, you might have to install this library [esp8266-oled-ssd1306](https://github.com/ThingPulse/esp8266-oled-ssd1306) or **SSD1306 by Adafruit:** Sketch -> Include Library -> Manage Libraries and installing "Adafruit GFX Library"
