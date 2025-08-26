# Arduino Binary Counter

A binary counter with an up and down button. The counter is restricted to 0-15, and a warning light will be triggered when trying to go lower. Going higher than 15 resets the counter to 0. Holding down for 1.5s results in increase/decrease every 150ms that the button is held down.

[Watch demo here](https://youtu.be/zQHQdOjH8N4)

# How it was made
Tech: Arduino Uno, C++ (arduino library)
Components:
- 2x push button (increasing + decreasing counter)
- 4x red LED (counter LEDs)
- 1x yellow LED (warning light)
- 5x 330Ω resistor (LED current limiter))
- 2x 10kΩ resistor (pull-down resistor)

# Skills practiced
- C++ coding
- Adapting to a new library
- Basic wiring & electrical component knowledge

