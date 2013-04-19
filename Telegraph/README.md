#Telegraph

Telegraph library for Arduino.

##How to use

- Copy `Telegraph` folder to your Arduino libraries (Sketchbook location/libraries/).
- Relaunch Arduino.
- Include `<Telegraph.h>`.

##Example

```cpp
#include <Telegraph.h>

const unsigned int OUTPUT_PIN = 13;
const unsigned int DIT_LENGTH = 200;

Telegraph telegraph(OUTPUT_PIN, DIT_LENGTH);

void setup() {}

void loop() {
  telegraph.send_message("Hello world");
  delay(5000);
}
```