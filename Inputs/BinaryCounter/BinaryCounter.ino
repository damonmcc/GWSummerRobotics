/*
 * Binary Counter
 * 
 * Uses LEDs to show a binary value
 * 
 * Circuit:
 *  Momentary switch from pin 2 to ground
 *  LEDs on digital pins 3, 4, 5
 *  
 * https://playground.arduino.cc/Code/BitMath
 * https://www.arduino.cc/en/Tutorial/BitMask
 * https://github.com/thomasfredericks/Bounce2/wiki
 */

#include <Bounce2.h>
const int BUTTON_PIN = 2;
// Instantiate a Bounce object
Bounce debouncer = Bounce();
int ledState = LOW;

const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;

byte count = 0;
byte mask = 1;
int countMax = pow(2, 3);

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
//  After setting up the button, setup the Bounce instance :
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5); // interval in ms
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
//  Update the Bounce instance :
  debouncer.update(); 
//  Call code if Bounce fell (transition from HIGH to LOW) :
  if ( debouncer.fell() ){
    //    Toggle built-in LED state:
    ledState = !ledState;
    digitalWrite(LED_BUILTIN,ledState);
    addToCount();
  }
}

void addToCount(){
  /*
   * Increment count and display with 3 LEDs
   */
  count++;
  Serial.print("addToCount called, now: ");
  Serial.println(count, BIN);
//  First digit
  if(mask & count){
    digitalWrite(redPin, HIGH);
  } else{digitalWrite(redPin, LOW);}
  
//  Second digit
  if(mask & count>>1){
    digitalWrite(greenPin, HIGH);
  } else{digitalWrite(greenPin, LOW);}
  
//  Third digit
  if(mask & count>>2){
    digitalWrite(bluePin, HIGH);
  } else{digitalWrite(bluePin, LOW);}

  if(count > countMax - 1){ count = 0;}
}

