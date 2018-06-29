/*
 * Blink Without Delay
 * 
 * Blinks an LED without using delay() function.
 * This means that other code can run at the same time
 * without being interrupted.
 * 
 * Circuit:
 *  Built-in LED on pin 13
 *  
 * based on: Blink Without Delay
 * http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// Set pin number
const int ledPin =  LED_BUILTIN;

// Used to set the LED
int ledState = LOW;        

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
// Will store last time LED was updated
unsigned long previousMillis = 0;        

// Interval at which to blink (milliseconds)
long interval = 1000;


void setup() {
 pinMode(ledPin, OUTPUT);
}

void loop() {
//   Check to see if it's time to blink the LED; that is, if the
//   difference between the current time and last time you blinked
//   the LED is bigger than the interval at which you want to
//   blink the LED.
  unsigned long currentMillis = millis();
//  BONUS: Use a potentiometer (analog input) to set "interval"
//  HINT: Use map() function to convert analog reading into an interval range
//  www.arduino.cc/reference/en/language/functions/math/map/

  if (currentMillis - previousMillis >= interval) {
    //    Save the last time you blinked the LED
    previousMillis = currentMillis;
    //    If the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    //    Set the LED using ledState:
    digitalWrite(ledPin, ledState);
  }
}
