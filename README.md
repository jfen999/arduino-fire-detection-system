# Arduino Fire Detection System

This project was built for Gonzaga University's First-Year Design Challenge. Our goal was to create a system that could detect a flame while also monitoring temperature and humidity.

The final prototype used an Arduino, a flame sensor, a DHT22 temperature and humidity sensor, and a 20x4 LCD. The electronics were housed in a custom enclosure modeled in SolidWorks and 3D printed using glow-in-the-dark filament. Our project won first place in the competition.

## How It Works

The Arduino continuously reads the flame sensor and DHT22.

Temperature, humidity, and the current fire status are displayed on the LCD. If the flame sensor detects a flame, the display changes from `SAFE` to `FLAME ALERT`.

The sensor readings are also sent to the Serial Monitor, which was useful while testing and debugging the system.

## Hardware

- Arduino
- Flame sensor
- DHT22 temperature and humidity sensor
- 20x4 I2C LCD
- Breadboard and jumper wires

## Enclosure

The system was housed in a custom enclosure modeled in SolidWorks and 3D printed using glow-in-the-dark filament.

## Connections

| Component | Arduino Pin |
| --- | --- |
| Flame sensor digital output | D7 |
| DHT22 data | D2 |
| LCD SDA | A4 |
| LCD SCL | A5 |

The LCD communicates over I2C using address `0x27`.

## Software

The system was programmed in Arduino C/C++.

The main loop:

1. Reads the flame sensor.
2. Reads temperature and humidity from the DHT22.
3. Updates the LCD with the current measurements.
4. Displays either `SAFE` or `FLAME ALERT`.
5. Prints the sensor readings to the Serial Monitor.

The display and sensor readings update every two seconds.

### Libraries Used

- `Wire.h`
- `LiquidCrystal_I2C.h`
- `DHT.h`

## CAD

The SolidWorks enclosure file is included in this repository.

## Project Result

The completed system was presented at Gonzaga University's First-Year Design Challenge and won first place.

## Project Photo
<img width="620" height="740" alt="IMG_9904" src="https://github.com/user-attachments/assets/66a0fb2f-5fbb-47d0-91a6-f23a33bfc49b" />
