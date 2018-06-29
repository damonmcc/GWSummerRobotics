/*
 * BuiltInLED
 * 
 * Uses built-in LED and delay function to blink
 * 
 * Circuit:
 *  Built-in LED on pin 13
 */

void setup() {
//  Configure digital pin #13 for output
//  Could also use pin LED_BUILTIN
  pinMode(13, OUTPUT);
}

void loop() {
//  Turn LED on for 1000 milliseconds
  digitalWrite(13, HIGH);
  delay(1000);
  
//  Turn LED off for 1000 milliseconds
  digitalWrite(13, LOW);
  delay(1000);
}



