//
//  NESController.h
//  NESController
//
//  Created by Angelo Di Paolo on 4/16/17.
//

#ifndef NESController_h
#define NESController_h

#define NES_A_BUTTON 0
#define NES_B_BUTTON 1
#define NES_SELECT_BUTTON 2
#define NES_START_BUTTON 3
#define NES_UP_BUTTON 4
#define NES_DOWN_BUTTON 5
#define NES_LEFT_BUTTON 6
#define NES_RIGHT_BUTTON 7

class NESController {
  public:
    NESController(int clockPin, int latchPin, int dataPin);
    /// Read the shift register state
    byte read();
    /// Returns true if a button is pressed
    bool isPressed(int button);
  private:
    int _latchPin;
    int _clockPin;
    int _dataPin;
    byte _state;
};

#endif
