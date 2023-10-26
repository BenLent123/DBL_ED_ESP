#include <stdio.h>
#include <stdlib.h>
#include "BluetoothSerial.h"
BluetoothSerial ESP_BT; //class init
const int pin1 = 23;         // pin for output
const int pin2 = 22;         // pin for output
int ESPBT_incoming;
int direction; // 0 is left, 1 is both, 2 is right
int number_of__vibrations; // 1-5 how many times we repeat the vibration
int duration; //duration of delay each vibration
void setup() {
  Serial.begin(115200);
  ESP_BT.begin("ESP32_169"); //name of ESP showing up on BT devices
}


void vibrate() {
  duration = ESPBT_incoming % 10; // 
  number_of__vibrations = ((ESPBT_incoming - duration) / 10) % 10; //
  direction = (((ESPBT_incoming - duration) / 10) - number_of__vibrations) / 10; // 

if (direction == 0 ){                        
  for (int i = 0; i<number_of__vibrations;i++){
    analogWrite(pin1,255); //vibrate motor connected to pin1
    delay(duration * 300);
    analogWrite(pin1,0); // stop vibrating motor connected to pin1
    delay(300);
    
    }   
}else if (direction == 1){
  for (int i = 0; i<number_of__vibrations;i++){
    analogWrite(pin1,255);  //vibrate motor connected to pin1
    analogWrite(pin2,255);  //vibrate motor connected to pin2
    delay(duration * 300);
    analogWrite(pin1,0); //stop vibrating motor connected to pin1
    analogWrite(pin2,0); //stop vibrating motor connected to pin2
    delay(300);
    
    }  
}else if (direction == 2){
  for (int i = 0; i<number_of__vibrations;i++){
    analogWrite(pin2,255); //vibrate motor connected to pin1
    delay(duration * 300);
    analogWrite(pin2,0); //stop vibrating motor connected to pin2
    delay(300);
    
    }  
}
}

void loop() {
   if (ESP_BT.available())
  {
    ESPBT_incoming = ESP_BT.read(); //read data incoming to ESP via bluetooth
    vibrate(); // call vibration
    Serial.print("duration");
    Serial.println(duration);
    Serial.print("num vibe");
    Serial.println(number_of__vibrations);          //ALL OF THIS IS JUST TO CHECK IF EVERYTHING IS FINE CAN BE DELETED!
    Serial.print("direction");
    Serial.println(direction);
    Serial.print("incoming");
    Serial.println(ESPBT_incoming);
  }
  
}
