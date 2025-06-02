// Define pin connections
const int soilMoisturePin = A0; // Analog pin for soil moisture sensor
const int pumpPin = 8;         // Digital pin for water pump relay
const int ledPin = 13;         // Built-in LED pin

// Moisture threshold
int moistureThreshold = 500;

void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  int moistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureValue);
  
  if (moistureValue < moistureThreshold) {
    // Turn on the pump
    digitalWrite(pumpPin, HIGH);
    digitalWrite(ledPin, HIGH); // LED ON
    Serial.println("Watering the plant...");
  } else {
    // Turn off the pump
    digitalWrite(pumpPin, LOW);
    digitalWrite(ledPin, LOW); // LED OFF
    Serial.println("No watering needed.");
  }

  delay(2000); // Wait for 2 seconds before next reading
}
