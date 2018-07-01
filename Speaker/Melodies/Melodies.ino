/*
 * Melodies
 * 
 * Plays a melodie using a sequence of notes
 * and durations for each
 * 
 * Circuit:
 *  8-ohm speaker on digital pin 8
 *    Longer pin goes to D8
 *    Shorter pin goes to GND
 *    
 *  based on: "Melody" by Tom Igoe
 *  http://www.arduino.cc/en/Tutorial/Tone
*/

// Include note frequency constants 
#include "pitches.h"

// Number of notes in the melody: MUST be changed if melody changes
#define MY_SIZE 23

// Default example melody
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Notes in "Hedwig's Theme"
// Source: https://pianoletternotes.blogspot.com/2015/11/hedwigs-theme-harry-potter.html
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
// Note durations: 400 = quarter note, 800 = eighth note, etc.:
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


// Notes in "Beverly Hills Cop Theme" 
// Source: https://tabs.ultimate-guitar.com/tab/misc_soundtrack/beverly_hills_cop_theme_tabs_7655
int melodyBHCT[] = {
  NOTE_A6, NOTE_C7, NOTE_A6,
  NOTE_A6, NOTE_D7, NOTE_A6, NOTE_G6,
  
  NOTE_A6, NOTE_E7, NOTE_A6,
  NOTE_A6, NOTE_F7, NOTE_E7, NOTE_C7,
  
  NOTE_A6, NOTE_E7, NOTE_A7,
  NOTE_A6, NOTE_FS6, NOTE_FS6,
  NOTE_E6, NOTE_B6, NOTE_A6
};
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
//  Iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < MY_SIZE; thisNote++) {
    //    To calculate the note duration:
    //      take one second (or any period of time),
    //      divide by the note type,
    //      e.g. quarter note = 1000/4, eighth note = 1000/8, etc.

    int noteDuration = 150000 / noteDurationsBHCT[thisNote];

    //    Use tone() command with pin#, note frequency, note duration
    //    https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
    tone(8, melodyBHCT[thisNote], noteDuration);

    //    To distinguish the notes, set a minimum time between them.
    //    Duration + 30% seems to work well.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    //    Stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // No need to repeat the melody.
}
