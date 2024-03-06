const int potPin = A0; 
const int ledPins[] = {D0, D1, D2, D3, D4, D5, D6, D7}; // Array of LED pins

void setup() {
  Serial.begin(115200); 
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT); 
    digitalWrite(ledPins[i], LOW); 
  }
}

void loop() {
  int sensorValue = analogRead(potPin); 

  if (sensorValue >= 25) {
    digitalWrite(ledPins[0], HIGH); // Turn on the first LED
  } else {
    digitalWrite(ledPins[0], LOW); // Turn off the first LED
  }

  for (int i = 1; i < 8; i++) {
      if (i <= sensorValue / 127) {
      digitalWrite(ledPins[i], HIGH); // Turn on LED
    } else {
      digitalWrite(ledPins[i], LOW); // Turn off LED
    }
  }

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
}
