/*
  Melodies

 Plays advanced melodies
 Circuit:
 * 8-ohm speaker on digital pin 8
 
 created 19 Jun 2018
 modified 19 Jun 2018
 by Damon McCullough
 based on: "Melody"
 by Tom Igoe
 http://www.arduino.cc/en/Tutorial/Tone
 */
 
#include "pitches.h"

// notes in the melody:
#define MY_SIZE 14
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// notes in Hedwig's Theme:
int melodyHT[] = {
  NOTE_B4,
  NOTE_E4, NOTE_G4, NOTE_FS4,
  NOTE_E4,
  NOTE_B4,
  NOTE_A4, NOTE_FS4,
  NOTE_E4, NOTE_G4, NOTE_FS4,
  NOTE_D4,
  NOTE_F4, NOTE_B4,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  800,
  570, 1600, 800,
  400, 800,
  264,
  264,
  
  264,
  570, 1600, 800,
  400, 800,
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < MY_SIZE; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 200000 / noteDurations[thisNote];
    tone(8, melodyHT[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
