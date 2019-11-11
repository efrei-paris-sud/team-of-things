const = int Variabler = 0;
const = int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  
}

void loop() {
  int reading = analogRead(Variabler);
  Serial.println(reading);
  delay(500);
  int change = map(reading, 0, 1023, 0, 255);
analogWrite(led, change);  
}
