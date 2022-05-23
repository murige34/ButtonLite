/*
 * Created by Martin Urigelj
 *
 * This example code is in the public domain
 *
 * This example reads the state of a button and print it to Serial Monitor.
 *
 *
 * Board connection: 
 * 
 *  Arduino pin 7|----| R = 1kOhm |----| tactile switch |----GND
 *  
 *  Resistor is not needed, but protects pin, if we accidentaly configure
 *  it as output and the switch is pressed
 */

#include <ButtonLite.h>

Button button(7, 20); // create button object that attach to pin 7, with debounce time 20 ms

void setup() {
  button.begin();
  button.setDebounceTime(25); // we can change debounce time[ms] (most used range 10 - 50 ms)
  
  Serial.begin(9600);
}

void loop() {
  button.loop();  // MUST call the loop() function first

  // check if button was pressed (event)
  if(button.isPressed()){
    Serial.println("The button was pressed.");
  }
    
  // check if button was released (event)
  if(button.isReleased()){
    Serial.println("The button was released.");
  }

  // check for how long button was pressed (state)
  if(button.getState()){
    Serial.print("The button is pressed for ");
    // to save RAM 16 bit variable is used (counts only up to 60000 ms) !!!
    Serial.print(button.timePressed());
    Serial.println(" ms");
  }
}
