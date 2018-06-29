/*
 * Analog Input
 * 
 * Reads an analog input, converts it to voltage, and prints
 * the result to the monitor and plotter in the Tools menu.
 * 
 * Circuit:
 *  Potentiometer connected to analog pin 0.
 *    Center pin goes to the analog pin.
 *    Side pins go to +5V and ground.
 *    
 * based on: ReadAnalogVoltage
 */

// Constants won't change
// Analog input pin that the potentiometer is attached to
const int analogInPin = A0;


void setup() {
  Serial.begin(9600);
}

void loop() {
//  Read the input on the chosen analog pin:
  int sensorValue = analogRead(analogInPin);
  
//  Convert the analog reading (which goes from 0 to 1023)
//  to the voltage range used in the circuit (0 to +5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
//  Print out the value you read:
  Serial.println(voltage, DEC);
}
