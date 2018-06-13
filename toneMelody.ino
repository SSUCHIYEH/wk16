/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4,  NOTE_E4, NOTE_G4,0,NOTE_G3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,4,4,8,4,4,4,4
};

void setup() {
  // iterate over the notes of the melody:
  
  pinMode(12,OUTPUT);
}

void loop() {
  long currentTime,previousTime;
  boolean check;
 // tone(8,523,500);
previousTime = millis();
  
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    digitalWrite(12,HIGH);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    digitalWrite(12,LOW);
    delay(20);
  }
   delay(100);

 
}
