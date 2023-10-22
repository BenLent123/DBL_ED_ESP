#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BluetoothSerial.h"
//global variables
BluetoothSerial ESP_BT; //class init
const int pin1 = 34;         // pin for output
const int pin2 = 23;         // pin for output
const int freq = 1000;  //freq
const int resolution = 8;
int dutycycle = 127;  // on and off ratio
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
if (direc = 1){
for (int i = 0; i<vibetime;i++){
  analog.write(pin1,255);  //pin 1 //right
      }  
}else if (direc = 2){
  for (int i = 0; i<vibetime;i++){
   analog.write(pin2,255);  // pin 2 //left
        }  
}else{
  break();
  } 
}

void main() {
  if (ESP_BT.available())
  {
    number = ESP_BT.read();
  }
  update();
  if (direc != 0){
    vibrate();
  }
}
