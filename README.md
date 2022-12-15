<div style="text-align:center" align="center">
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Main.png" alt="Give A Star logo" width="500"/>
</div>

<h3 style="text-align:center" align="center">A Star-Shaped PCB Board Gift based on the ESP32-S2 and D1 Mini to teach the basics of soldering</h3>

## Features
- Display a kind visual message to someone
- Five Different LED Animations
- Change Animations by Clicking Button
- Teach the Basics of Soldering

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


## Schematic
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Schematic.png" alt="Give A Star schematic" width="700"/>

## PCB Design
<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Design_PCB.png" alt="Give A Star PCB Design" width="500"/>


<img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Front_PCB.png" alt="Give A Star PCB Front" width="400"/><img src="https://github.com/angelina-tsuboi/give-a-star/blob/main/assets/Back_PCB.png" alt="Give A Star PCB Back" width="400"/>
