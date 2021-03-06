/**
 * This is a simple Arduino project to implement a binary dice guessing game.
 *
 * How to play
 * -----------
 *
 * 1. There are three LEDs on the board representing the binary LED_BIT0, LED_BIT1, LED_BIT2, so it can display 0(000)-7(111).
 * 2. Click GUESS_BUTTON_PIN to select the number you want to guess, and show on LEDs.
 * 3. Click START_BUTTON_PIN to start random, if you guessed, the LED will blink.
 *
 * Used components
 * ---------------
 *
 * - Arduino UNO x 1
 * - Breadboard x 1
 * - LED x 3
 * - Pushbutton x 2
 * - Resistance 10kΩ x 2
 * - Resistance 1kΩ x 4
 *
 * Used library
 * ------------
 *
 * - [Bounce](http://playground.arduino.cc/code/bounce), Bounce is a library for Arduino (arduino.cc). It debounces digital inputs and more.
 */
#include <Bounce.h>

const int MIN_DICE = 1;
const int MAX_DICE = 7;

const unsigned int LED_BIT0 = 12;
const unsigned int LED_BIT1 = 11;
const unsigned int LED_BIT2 = 10;

const unsigned int START_BUTTON_PIN = 5;
const unsigned int GUESS_BUTTON_PIN = 7;

const unsigned int BAUD_RATE = 9600;

void setup()
{
  pinMode(LED_BIT0, OUTPUT);
  pinMode(LED_BIT1, OUTPUT);
  pinMode(LED_BIT2, OUTPUT);

  pinMode(START_BUTTON_PIN, INPUT);
  pinMode(GUESS_BUTTON_PIN, INPUT);

  randomSeed(analogRead(A0));

  Serial.begin(BAUD_RATE);
}

void loop()
{
  handleGuessButton();
  handleStartButton();
}

int guess = 0;

const unsigned int DEBOUNCE_DELAY = 20;

Bounce start_button(START_BUTTON_PIN, DEBOUNCE_DELAY);
Bounce guess_button(GUESS_BUTTON_PIN, DEBOUNCE_DELAY);

void handleGuessButton()
{
  if (guess_button.update())
  {
    if (guess_button.read() == HIGH)
    {
      guess = (guess % (MAX_DICE-1)) + 1;
      outputResult(guess);

      Serial.print("Guess: ");
      Serial.println(guess);
    }
  }
}

const unsigned int RESULT_DELAY = 2000;

void handleStartButton()
{
  if (start_button.update())
  {
    if (start_button.read() == HIGH)
    {
      const int result = random(MIN_DICE, MAX_DICE);
      outputResult(result);

      Serial.print("Result: ");
      Serial.println(result);

      if (guess > 0)
      {
        if (guess == result)
        {
          hooray();

          Serial.println("You win!");
        }
        else
          Serial.println("You lose!");

        delay(RESULT_DELAY);

        guess = 0;
      }
    }
  }
}

void outputResult(const long result)
{
  digitalWrite(LED_BIT0, result & B001);
  digitalWrite(LED_BIT1, result & B010);
  digitalWrite(LED_BIT2, result & B100);
}

const unsigned int FULL_RAY = 7;
const unsigned int NULL_RAY = 0;
const unsigned int COUNT_RAY = 3;
const unsigned int DELAY_RAY = 500;

void hooray()
{
  for (int i=0; i<COUNT_RAY; i++)
  {
    outputResult(FULL_RAY);
    delay(DELAY_RAY);
    outputResult(NULL_RAY);
    delay(DELAY_RAY);
  }
}
