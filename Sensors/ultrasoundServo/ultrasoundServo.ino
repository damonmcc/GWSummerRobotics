#include <Servo.h>

Servo servo1;
const int trigPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
long duration;

void setup() {
  servo1.attach(3);   
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  // The time between the transmission and reception of the signal
  // allows us to know the distance to an 
  // object. This is possible because we know the sound’s velocity in the air.
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  servo1.write(0);
  if(inches <= 10){
  servo1.write(90);
  }
  if (inches <= 5){
  servo1.write(180);
  }
  
  Serial.print(inches);
  //   Serial.print("in, ");
  //   Serial.print(cm);
  //   Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
