#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BluetoothSerial.h"
BluetoothSerial ESP_BT; //class init
const int pin1 = 23;         // pin for output
const int pin2 = 22;         // pin for output
int ESPBT_incoming;
int direction; // 1 is left, 2 is both, 3 is right
int number_of__vibrations; // 1-9 how many times we repeat the vibration
int duration; //duration of delay each vibration

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_169");
}


void vibrate() {
  duration = ESPBT_incoming % 10 // last digit in number
  vibetime = ((ESPBT_incoming - duration) / 10) % 10 // middle digit in number
  direction = (((ESPBT_incoming - duration) / 10) - number_of__vibrations) / 10 // first digit in number  

if (direction = 1 ){                        
  for (int i = 0; i<number_of__vibrations;i++){
    analog.write(pin1,255);  
    delay(duration * 300);        
    analog.write(pin1,0);
    delay(300)
    }  
}else if (direction = 2){
  for (int i = 0; i<number_of__vibrations;i++){
    analog.write(pin1,255);  
    analog.write(pin2,255); 
    delay(duration * 300);
    analog.write(pin1,0);
    analog.write(pin2,0);
    delay(300)
    }  
}else if (direction = 3){
  for (int i = 0; i<number_of__vibrations;i++){
    analog.write(pin2,255);
    delay(duration * 300);
    analog.write(pin2,0);
    delay(300)
    }  
}
}

void loop() {
   if (ESP_BT.available())
  {
    ESPBT_incoming = ESP_BT.read();
  }
  vibrate();
}


/* 
void VibrateRightON(){
analog.write(pin1,255);  
}
void VibrateRightOFF(){
analog.write(pin1,0);  
}
void VibrateLeftON(){
analog.write(pin2,255);    
}
void VibrateLeftOFF(){
analog.write(pin2,0);  
}

*/

