/*
  Melodies

 Plays advanced melodies
 Circuit:
 * 8-ohm speaker on digital pin 8
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13 

 by Damon McCullough
 based on: "Melody"
 by Tom Igoe
 http://www.arduino.cc/en/Tutorial/Tone
*/
 
#include "pitches.h"


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
const int lengthHT = sizeof(melodyHT) / sizeof(melodyHT[0]);

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
const int lengthBHCT = sizeof(melodyBHCT) / sizeof(melodyBHCT[0]);

int melodiesArray[][50] = {melodyHT, melodyBHCT};
int durationsArray[][50] = {noteDurationsHT, noteDurationsBHCT};
int lengthssArray[][50] = {lengthHT, lengthBHCT};
int choiceNumber = 0;


void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);

  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    if (choiceNumber == 0){
      playMelody(melodyHT, noteDurationsHT, lengthHT);
    }
    if (choiceNumber == 1){
      playMelody(melodyBHCT, noteDurationsBHCT, lengthBHCT); 
    }
    if (choiceNumber < 2 ){
      choiceNumber++;
    }
    else{ 
      choiceNumber = 0;
    }
  }
}


void playMelody(int melody[], int melodyDurations[], int melodyLength){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    // to calculate the note duration, take one second (or anything)
    // divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 150000 / melodyDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

