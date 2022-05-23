/*
 * Created by Martin Urigelj
 *
 * This example code is in the public domain
 *
 * This example increases counter value at a press of a button and prints it to Serial Monitor.
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
  Serial.println("Push buton to increase counter, now counter = 0.");
}

void loop() {
  button.loop();  // MUST call the loop() function first
  
  if(button.isPressed()){
    cntr++;
    Serial.println(cntr);
  }
}
