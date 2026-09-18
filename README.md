# Arduino Fire Detection System

This project was built by my team for Gonzaga University's First-Year Design Challenge. We wanted to build a simple system that could detect a flame while also monitoring temperature and humidity.

The final prototype used an Arduino, a flame sensor, a DHT22 temperature and humidity sensor, and a 20x4 LCD inside a custom 3D-printed enclosure. Our project won first place in the competition.

## How It Works

The Arduino continuously reads the flame sensor and DHT22.

Temperature, humidity, and the current fire status are displayed on the LCD. If the flame sensor detects a flame, the display changes from `SAFE` to `FLAME ALERT`.

The same readings are also sent to the Serial Monitor, which was useful for testing the sensors and debugging the system.

## Hardware

- Arduino
- Flame sensor
- DHT22 temperature and humidity sensor
- 20x4 I2C LCD
- Custom 3D-printed enclosure
- Breadboard and jumper wires

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

The display is updated every two seconds.

### Libraries Used

- `Wire.h`
- `LiquidCrystal_I2C.h`
- `DHT.h`

## Project Result

The completed system was presented at our First-Year Design Challenge and won first place.

## Project Photo
<img width="630" height="800" alt="IMG_9904" src="https://github.com/user-attachments/assets/c3acaa76-59c0-45e2-b734-da5ab1cd4770" />
