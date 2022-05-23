/*
 * Created by Martin Urigelj
 *
 * This example code is in the public domain
 *
 * This example increases counter value at a press of a button and prints it to Serial Monitor.
 * If we hold button pressed it counts faster
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

Button button(7); // create button object that attach to pin 7;

int cntr = 0;

void setup() {
  button.begin();
  
  Serial.begin(9600);
}

void loop() {
  button.loop();  // MUST call the loop() function first
  
  if(button.isPressed()){
    // short press increases counter for 1
    cntr++;
    Serial.println(cntr);
  }
  if (button.timePressed() > 400){
    // long hold increases counter for 10  every 0,5 s
    cntr += 10;
    
    Serial.println(cntr);
    delay(200);
  }
}
