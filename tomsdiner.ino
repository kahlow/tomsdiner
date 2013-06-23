#include "pitches.h"
#include "hardware_versions.h"

// notes in the melody:
int melody[] = { NOTE_D5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_G5 };

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int notePosition = 0;        // current note

void setup() {
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  digitalWrite(BUZZER1, LOW); 
  digitalWrite(BUZZER2, LOW);
  
  randomSeed(millis()); 
}

void loop() {
  buttonState = digitalRead(BUTTON_RED);
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      digitalWrite(LED_RED, HIGH);
      tone(BUZZER1, melody[notePosition], 500);
      
      if (notePosition <= 6) {
        notePosition++;
      } else {
        notePosition = 0;
      }
      
      delay(10); // prevent double tap
    } else {
      digitalWrite(LED_RED, LOW);
      noTone(BUZZER1);
    }
  }
  
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;
}
