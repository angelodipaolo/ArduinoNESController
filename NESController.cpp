//
//  NESController.cpp
//  NESController
//
//  Created by Angelo Di Paolo on 4/16/17.
//

#include <stdint.h>
#include "Arduino.h"
#include "NESController.h"

/// Order that each button state bit is sent after sending latch signal
const int buttons [8] = {NES_A_BUTTON, NES_B_BUTTON, NES_SELECT_BUTTON, NES_START_BUTTON, NES_UP_BUTTON, NES_DOWN_BUTTON, NES_LEFT_BUTTON, NES_RIGHT_BUTTON};

NESController::NESController(int clockPin, int latchPin, int dataPin) {
  _latchPin = latchPin;
  _clockPin = clockPin;
  _dataPin = dataPin;

  pinMode(dataPin, INPUT);

  pinMode(latchPin, OUTPUT);
  digitalWrite(latchPin, LOW);

  pinMode(clockPin, OUTPUT);
  digitalWrite(clockPin, LOW);
}

byte NESController::read() {
  int state = 255;

  digitalWrite(_latchPin, HIGH);
  digitalWrite(_latchPin, LOW);

  if (digitalRead(_dataPin) == LOW) {
    bitClear(state, buttons[0]);
  }

  for (int i=1; i < 8; ++i) {
    int button = buttons[i];
    
    digitalWrite(_clockPin, HIGH);
    digitalWrite(_clockPin, LOW);

    if (digitalRead(_dataPin) == LOW) {
      bitClear(state, button);
    }
  }

  _state = state;
  return state;
}

bool NESController::isPressed(int button) {
  return bitRead(_state, button) == 0;
}
