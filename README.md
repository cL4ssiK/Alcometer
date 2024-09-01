# Alcometer

## Description
In this project I tried to create an alcometer with a fun twist to be used at student gatherings. This alcometer uses MQ-3 sensor to measure the alcohol level from the breathing air. After reading is done, user can see the average reading from the screen. User also has an option to save the score. The device has only one push button, but the button has multiple functionalities depending which process is active.

I chose to create alcometer as my second embedded project, mainly because its simplicity. I wanted to pick something that I can handle, have some usage and learn about electronics and ways to develope embedded systems. During this project I learned how to use displays with Arduino, how to use EEPROM to store data, how to structure application that has multiple states and UI windows and how to code multiple functionalities for single button. I also learned how to use function pointers and lambdas in C++. I also deepened my understanding of memory allocation and C style arrays.
Electronics wise I learned how to use voltage regulator, and the necessary requirements of charging Li-OH battery safely. I also learned how to use transistor as switch to run only little current through an actual mechanical switch. I decided later that it is not practical in this project because current draw is little and voltage is low.

I tried two libraries, u2g8 and Adafruit GFX. I ended up choosing u2g2, because according to some unverified source from internet, it suits better for creating animations. This was important, because at this point I had gotten little carried away, and wanted to create loading animation for the time it takes the MQ-3 sensor to heat up. The disadvantage of this library is that it uses a lot of memory. Like 70+% of it. In this project it did not really matter though.

## Installation


## Usage


## Project setup
This section provides list of equipment used in project.

### Scematics


## Software


## Problems and challenges


## Credits
