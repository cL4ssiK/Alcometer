# Alcometer

## Description
In this project I tried to create an alcometer with a fun twist to be used at student gatherings. This alcometer uses MQ-3 sensor to measure the alcohol level from the breathing air. After reading is done, user can see the average reading on the screen. User also has an option to save the score and display it later. The device has only one push button, but the button has multiple functionalities depending which process is active.

I chose to create alcometer as my second embedded project, mainly because its simplicity. I wanted to pick something that I can handle, have some usage and learn about electronics and ways to develope embedded systems. During this project I learned how to use displays with Arduino, how to use EEPROM to store data, how to structure application that has multiple states and UI windows and how to code multiple functionalities for single button. I also learned how to use function pointers and lambdas in C++. I also deepened my understanding of memory allocation and C style arrays.
Electronics wise I learned how to use voltage regulator, and the necessary requirements of charging Li-OH battery safely. I also learned how to use transistor as switch to run only little current through an actual mechanical switch. I decided later that it is not practical in this project because current draw is little and voltage is low.

In the future I could improve this project by calibrating the sensor to show promilles, instead of "random" value from 0-1023. PushButton class could also be improved to work with any type of function signature. I tried using tuples but arduino does not seem to support them. Perhaps pair could be used, I'm not sure. That would make the PushButton class actually usable in other projects as well. Also changing clock speed to extend battery life could be done when it is not necessary to have the device functioning as fast as it can.

I tried two libraries, u2g8 and Adafruit GFX. I ended up choosing u2g2, because according to some unverified source from internet, it suits better for creating animations. This was important, because at this point I had gotten little carried away, and wanted to create loading animation for the time it takes the MQ-3 sensor to heat up. The disadvantage of this library is that it uses a lot of memory. Like 70+% of it. In this project it did not really matter though.

## Installation
1. Clone the project
   ```bash
   git clone https://github.com/cL4ssiK/Alcometer.git
   ```
2. Copy the PushButton folder and paste it into Arduiono/libraries
3. Install U8g2 library by oliver
   
## Usage
You can test the project with simple breadboard setup. For this ignore MT3608 chip and everything above it shown in wiring diagram.
1. Build the circuit shown in wiring diagram.
2. If you havent already copy the PushButton folder and paste it into Arduiono/libraries.
3. Open alcometer_and_scoreboard_v5.ino in arduino IDE.
4. Connect arduino to the computer via USB cable.
5. Press upload.

## Project setup
This section provides list of equipment used in project.

### Breadboard test
1. Arduino Nano 3 clone including
   - ATMega328p microcontroller
   - CH340C usb bus converter chip
2. MQ-3 alcohol sensor
3. 0,96" 128x64 SSD1306 I2C/IIC Oled display
5. Breadboard
6. 10kΩ Pull-down resistor for button
7. push button
8. male to male wires for connections
NOTE! You can use any arduino controller as long as the processor is at least ATMega328p. ATMega168 does not have enough memory for controlling the display.
      10kΩ Pull-down resistor is not necessary if you use build in resistor. For that you need to make some changes in the code though.

### Full build
1. Arduino Nano 3 clone including
   - ATMega328p microcontroller
   - CH340C usb bus converter chip
2. MQ-3 alcohol sensor
3. 0,96" 128x64 SSD1306 I2C/IIC Oled display
4. MT3608 boost converter circuit
5. 03926A Li-Ion battery charging circuit
6. 18650 3.7V Li-Ion battery
7. Battery holder
8. 10kΩ Pull-down resistor for button
9. Push button
10. On/off switch
11. Wires
NOTE! I used small plastic box (measurements) as casing that I had laying around. AlkometrinsuutiivisteellaV2.stl contains piece that can fit MQ-3 sensor in the bottom, and with rubber o-ring placed on the circular groove, top side fits to vape nozzle I hac laying around as well. The part is glued into hole drilled to the box. In the future I might just design printable case, but for now this will do.

### Scematics


## Software


## Problems and challenges


## Credits
