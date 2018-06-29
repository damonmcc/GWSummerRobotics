/*
 * Buttons
 * 
 * Reads buttons on digital pins
 * 
 * Circuit:
 *  Momentary switch attached from pin 2 to ground
 *  Built-in LED on pin 13
 *  
 * based on: Input Pullup Serial
 * http://www.arduino.cc/en/Tutorial/InputPullupSerial
 */

void setup() {
//  Configure digital pin #2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  
//  Configure digital pin #13 for output
  pinMode(13, OUTPUT);
  
//  BONUS: use serial communication to debug the code
//  Serial.begin(choose a baud rate);
}

void loop() {
//  Read the pushbutton value into a variable
  int sensorValue = digitalRead(2);
  
//  Print out the value of the pushbutton
//  Serial.println(variable with sensor value);

//  Keep in mind the pullup means the pushbutton's
//  logic is inverted. It goes HIGH when it's open,
//  and LOW when it's pressed. Turn on pin 13 when the
//  button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}



