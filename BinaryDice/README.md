This is a simple Arduino project to implement a binary dice guessing game.

#How to play

1. There are three LEDs on the board representing the binary **bit2**, **bit1**, **bit0**, so it can display **0**(000)-**7**(111).
2. Click **guess button** to select the number you want to guess, and show on LEDs.
3. Click **start button** to start random, if you guessed, the LED will blink.

#Used components

- Arduino UNO x 1
- Breadboard x 1
- LED x 3
- Pushbutton x 2
- Resistance 10kΩ x 2
- Resistance 1kΩ x 4

#Used library

- [Bounce](http://playground.arduino.cc/code/bounce) - Bounce is a library for Arduino (arduino.cc). It debounces digital inputs and more.

#Trello board [link](https://trello.com/c/lxMQclfW)


#Circuit diagram

![BinaryDice_bb](https://github.com/amowu/arduimo/blob/master/BinaryDice/doc/BinaryDice_bb.png?raw=true)

![BinaryDice_sch](https://github.com/amowu/arduimo/blob/master/BinaryDice/doc/BinaryDice_sch.png?raw=true)