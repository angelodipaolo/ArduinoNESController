# NESController

An Arduino library for reading input data from a Nintendo Entertainment System controller.

## Usage

1. Create an an instance of `NESController` with the pin numbers for the `CLOCK`, `LATCH`, and `DATA` lines. See the [NES controller pinout](http://wiki.nesdev.com/w/index.php/Controller_port_pinout) for wiring information.
2. Call `read()` to read the current shift register data into a `byte`. Each button represents 1 bit in the byte ordered as A, B, SELECT, START, UP, DOWN, LEFT, RIGHT. A logical `0` represents a down press.
3. Use `isPressed(int button)` or bitwise operators to check input data.

```
#include <NESController.h>

const int CLOCK_PIN = 2;
const int LATCH_PIN = 3;
const int DATA_PIN = 4;

NESController controller = NESController(CLOCK_PIN, LATCH_PIN, DATA_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte state = controller.read();
  delay(100);

  if (controller.isPressed(NES_A_BUTTON)) {
    Serial.println("A");
  }
  if (controller.isPressed(NES_B_BUTTON)) {
    Serial.println("B");
  }
  if (controller.isPressed(NES_LEFT_BUTTON)) {
    Serial.println("LEFT");
  }
  if (controller.isPressed(NES_RIGHT_BUTTON)) {
    Serial.println("RIGHT");
  }
}
```