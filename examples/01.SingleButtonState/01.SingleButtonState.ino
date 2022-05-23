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

Button button(7); // create Button object that attach to pin 7;

void setup() {
  button.begin();
  
  Serial.begin(9600);
}

void loop() {
  button.loop();  // MUST call the loop() function first

  int btnState = button.getState(); 
  Serial.println(btnState);
}
