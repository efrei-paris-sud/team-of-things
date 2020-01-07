// DEFFRADAS-TCHEUPI-WONG
// EFREI Paris M1
// IoT 2019/2020

// Usefull librairies for the DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Arduino.h"
// Using external librairies for the LoRa Module
#include "LoRa_E32.h"

// DS18B20 GPIO port number
const int bus = 4;     
const int ledPin = 5;
const int buzzer = 2;
LoRa_E32 e32(D32, D33);

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(bus);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode (ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
  sensors.begin();
  e32.begin(866E6);
  ResponseStatus rs = e32.sendMessage("LoRA device ON");
  // Error Check
  ResponseContainer rc = rs.getResponseDescription();
  if (rc.status.code!=1){
    rc.status.getResponseDescription();
    exit();
  }
}

void loop() {
  sensors.requestTemperatures(); 
  float temperature =sensors.getTempCByIndex(0)
  LoRa.beginPacket();
  LoRa.print(temperature);
  LoRa.endPacket();
  if(temperature > 6 || temperature < -3){
    for (int i=0; i <= 5; i++){    
      digitalWrite (ledPin, HIGH);  // turn on the LED
      tone(buzzer, 1000); // turn on the buzzer
      delay(500); // wait for 500 milliseconds
      digitalWrite (ledPin, LOW); // turn off the LED
      noTone(buzzer); // Stop the buzzer
      delay(500); // wait for 500 milliseconds
      LoRa.beginPacket();
      LoRa.print("!! ALERT !!");
      LoRa.print(temperature);
      LoRa.endPacket();
    }
  }
  delay(500); 
}
