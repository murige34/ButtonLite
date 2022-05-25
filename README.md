# ButtonLite Library for Arduino

Simple Arduino library for push buttons, tactile switches and other mechanical contacts that need debouncing for stable readings. It is simple to use and uses less RAM than other similar libraries.

__ButtonLite__ stands for __low RAM consumption__

----------------------------
* Uses the internal pull-up resistor to avoid the floating value
* Supports debounce to eliminate the chattering phenomenon
* Supports the pressed and released events
* Supports timing of press (to detect long presses)
* Easy to use with multiple buttons
* All functions are non-blocking

Available Examples
----------------------------
* 01.SingleButtonState
* 02.SingleButtonEvents
* 03.SingleButtonCounter
* 04.SingleButtonAll
* 05.SingleButtonCounterAdvanced
* 06.MultipleButtons

Available Functions
----------------------------
* begin()
* setDebounceTime()
* getState()
* isPressed()
* isReleased()
* timePressed()
* __loop()__
