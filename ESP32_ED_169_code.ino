#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BluetoothSerial.h"
//global variables
BluetoothSerial ESP_BT; //class init
const int pin1 = 34;         // pin for output
const int pin2 = 23;         // pin for output
int i = 0;
long long number = 0;
int digits[10] = { '\0' };
int direc;
int vibtime;
char dura[8] = { 0 };
//////////////////////////

void setup() {
  //attach pins and setup
  Serial.begin(19200);
  ESP_BT.begin("ESP32_169");
}

void update() {
  i = 0;
  while (number != 0) {
    digits[i] = number % 10;
    number = number / 10;
    i++;
  }

  int reversedigits[i];
  for (int j = 0; j < 10; j++) {
    reversedigits[j] = digits[i - j - 1];
  }

  direc = reversedigits[0];
  vibetime = reversedigits[1];
  for (int z = 2; z < i; z++) {
    char temp[2];
    sprintf(temp, "%d", reversedigits[z]);
    strcat(dura, temp);
  }
}

void vibrate() {
//1 is left 2 is both 3 is right
if (direc = 1 ){                        
  for (int i = 0; i<vibetime;i++){
    analog.write(pin1,255);  //pin 1 //left
    delay(200);            // --> might change into delay dura // not tested yet
    }  
}else if (direc = 2){
  for (int i = 0; i<vibetime;i++){
    analog.write(pin2,255);
    analog.write(pin1,255);
    delay(200);  // pin1 and 2
    }  
}else if (direc = 3){
  for (int i = 0; i<vibetime;i++){
    analog.write(pin2,255);
    delay(200);  // pin 2 //right
    }  
}else{  // case anything else 
  break();
  } 
}
// main loop we repeat
void loop() {
  if (ESP_BT.available())
  {
    number = ESP_BT.read();
  }
  update();
  if (direc != 0){
  vibrate();
  }
}
