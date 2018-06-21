/*
  PokemonCenter

 Plays tune when any object is near ambient light sensor
 Circuit:
 * 8-ohm speaker on digital pin 8
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13
 * Photocell attached from VCC to pin 3
 
 by Damon McCullough
 based on: "Melody"
 by Tom Igoe
 http://www.arduino.cc/en/Tutorial/Tone
*/
 
#include "pitches.h"


// notes in Pokemon Center Theme:
int melodyPCT[] = {
  NOTE_A6, NOTE_A6,
  NOTE_A6, NOTE_F6, NOTE_D7
};
// note durations: 400 = quarter note, 800 = eighth note, etc.:
int noteDurationsPCT[] = {
  400, 400,
  800, 800, 400
};
const int lengthPCT = sizeof(melodyPCT) / sizeof(melodyPCT[0]);


void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  // read the photocell value into a variable
  int sensorVal = analogRead(A3);
  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal > 300) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    Serial.println(sensorVal);
    playMelody(melodyPCT, noteDurationsPCT, lengthPCT);
  }
  delay(10);
}


void playMelody(int melody[], int melodyDurations[], int melodyLength){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    // to calculate the note duration, take one second (or anything)
    // divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 120000 / melodyDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

