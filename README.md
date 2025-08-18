# Arduino Binary Counter

[Watch demo here](https://youtu.be/zQHQdOjH8N4)

Components:
- arduino uno
- 2x push button (increasing + decreasing counter)
- 4x red LED (counter LEDs)
- 1x yellow LED (warning light)
- 5x 330Ω resistor (LED current limiter))
- 2x 10kΩ resistor (pull-down resistor)

Features:
- counter is restricted to 0-15. Trying to go lower will trigger the warning light. Going higher will reset the counter to zero
- holding down for 1.5s results in an increase/decrease every 150ms
