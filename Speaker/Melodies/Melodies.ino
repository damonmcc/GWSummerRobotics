/*
  Melodies

 Plays melodies
 Circuit:
 * 8-ohm speaker on digital pin 8

 by Damon McCullough
 based on: "Melody"
 by Tom Igoe
 http://www.arduino.cc/en/Tutorial/Tone
*/
 
#include "pitches.h"

// notes in the melody: MUST be changed
// TODO: calculate in loop()
#define MY_SIZE 23

// default example melody
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// notes in Hedwig's Theme:
// source: https://pianoletternotes.blogspot.com/2015/11/hedwigs-theme-harry-potter.html
int melodyHT[] = {
  NOTE_B4,
  NOTE_E4, NOTE_G4, NOTE_FS4,
  NOTE_E4, NOTE_B4,
  NOTE_A4,
  NOTE_FS4,
  
  NOTE_E4, NOTE_G4, NOTE_FS4,
  NOTE_D4, NOTE_F4,
  NOTE_B3,

  
};
// note durations: 400 = quarter note, 800 = eighth note, etc.:
int noteDurationsHT[] = {
  800,
  570, 1600, 800,
  400, 800,
  264,
  264,
  
  570, 1600, 800,
  400, 800,
  264
};


// notes in Beverly Hills Cop Theme 
// source: https://tabs.ultimate-guitar.com/tab/misc_soundtrack/beverly_hills_cop_theme_tabs_7655
int melodyBHCT[] = {
  NOTE_A6, NOTE_C7, NOTE_A6,
  NOTE_A6, NOTE_D7, NOTE_A6, NOTE_G6,
  
  NOTE_A6, NOTE_E7, NOTE_A6,
  NOTE_A6, NOTE_F7, NOTE_E7, NOTE_C7,
  
  NOTE_A6, NOTE_E7, NOTE_A7,
  NOTE_A6, NOTE_FS6, NOTE_FS6,
  NOTE_E6, NOTE_B6, NOTE_A6
};
// note durations
int noteDurationsBHCT[] = {
  400, 570, 800,
  1600, 800, 800, 800,
  
  400, 570, 800,
  1600, 800, 800, 800,
  
  800, 800, 800,
  1600, 800, 1600,
  800, 800, 400
  
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < MY_SIZE; thisNote++) {

    // to calculate the note duration, take one second (or anything)
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //** 100000 ~= 1 second
    int noteDuration = 150000 / noteDurationsBHCT[thisNote];
    tone(8, melodyBHCT[thisNote], noteDuration);

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
