// DEFFRADAS-TCHEUPI-WONG
// EFREI Paris M1
// IoT 2019/2020

// Usefull librairies for the DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>

// DS18B20 GPIO port number
const int bus = 4;     
const int ledPin = 5;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(bus);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode (ledPin, OUTPUT);
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  float temperature =sensors.getTempCByIndex(0);
  
      digitalWrite (ledPin, HIGH);  // turn on the LED
      delay(500); // wait for 500 milliseconds
      digitalWrite (ledPin, LOW); // turn off the LED

      delay(500); // wait for 500 milliseconds

}
