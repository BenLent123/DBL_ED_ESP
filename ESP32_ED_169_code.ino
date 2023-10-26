#include <stdio.h>
#include <stdlib.h>
#include "BluetoothSerial.h"
BluetoothSerial ESP_BT; //class init
const int pin1 = 23;         // pin for output
const int pin2 = 22;         // pin for output
int ESPBT_incoming;
int direction; // 0 is left, 1 is both, 2 is right
int number_of__vibrations; // 1-9 how many times we repeat the vibration
int duration; //duration of delay each vibration
void setup() {
  Serial.begin(115200);
  ESP_BT.begin("ESP32_169");

}


void vibrate() {
  duration = ESPBT_incoming % 10; // 
  number_of__vibrations = ((ESPBT_incoming - duration) / 10) % 10; //
  direction = (((ESPBT_incoming - duration) / 10) - number_of__vibrations) / 10; // 

if (direction == 0 ){                        
  for (int i = 0; i<number_of__vibrations;i++){
    analogWrite(pin1,255);
    delay(duration * 300);
    analogWrite(pin1,0);
    delay(300);
    
    }   
}else if (direction == 1){
  for (int i = 0; i<number_of__vibrations;i++){
    analogWrite(pin1,255);  
    analogWrite(pin2,255); 
    delay(duration * 300);
    analogWrite(pin1,0);
    analogWrite(pin2,0);
    delay(300);
    
    }  
}else if (direction == 2){
  for (int i = 0; i<number_of__vibrations;i++){
    analogWrite(pin2,255);
    delay(duration * 300);
    analogWrite(pin2,0);
    delay(300);
    
    }  
}
}

void loop() {
   if (ESP_BT.available())
  {
    ESPBT_incoming = ESP_BT.read();
    vibrate();
    Serial.print("duration");
    Serial.println(duration);
    Serial.print("num vibe");
    Serial.println(number_of__vibrations);
    Serial.print("direction");
    Serial.println(direction);
    Serial.print("incoming");
    Serial.println(ESPBT_incoming);
  }
  
}
