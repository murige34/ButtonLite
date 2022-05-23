/*
 * Created by Martin Urigelj
 *
 * This example code is in the public domain
 *
 * In this example we got 3 buttons to set variable value that is displayed on Serial Monitor.
 * Short press on button: +/- 1
 * Long press on button:  +/- 10 counts automaticaly until release
 *
 *
 * Board connection: 
 * 
 *  Arduino pin 7|----| R = 1kOhm |----| tactile switch |----GND
 *  Arduino pin 6|----| R = 1kOhm |----| tactile switch |----GND
 *  Arduino pin 5|----| R = 1kOhm |----| tactile switch |----GND
 *  
 *  Resistor is not needed, but protects pin, if we accidentaly configure
 *  it as output and the switch is pressed
 */
 
#include <ButtonLite.h>

Button btnIncr(7); // create button object that attach to pin 7;
Button btnDecr(6); // create button object that attach to pin 6;
Button btnRst (5); // create button object that attach to pin 5;

int cntr = 0;

void setup(){
  btnIncr.begin();
  btnDecr.begin();
  btnRst.begin();
  
  Serial.begin(9600);
  Serial.println("Press the buttons to set the value (current = 0).");
}

void loop() {
  btnIncr.loop(); // MUST call the loop() function first,
  btnDecr.loop(); // for each button
  btnRst.loop();
  
  
  if(btnRst.isPressed()){
    cntr = 0;
    Serial.println(cntr);
  }
  else if(btnIncr.isPressed()){
    // short press increases counter for 1
    cntr++;
    Serial.println(cntr);
  }
  else if (btnIncr.timePressed() > 400){
    // long hold increases counter for 10  every 0,2 s
    cntr += 10;
    
    Serial.println(cntr);
    delay(200);
  }
  else if(btnDecr.isPressed()){
    // short press decreases counter for 1
    cntr--;
    Serial.println(cntr);
  }
  else if (btnDecr.timePressed() > 400){
    // long hold decreases counter for 10  every 0,2 s
    cntr -= 10;
    
    Serial.println(cntr);
    delay(200);
  }
}
