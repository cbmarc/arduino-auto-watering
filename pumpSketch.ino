// Pins definition
int moistureSensorPin = 0;
int pumpPin = 7;
int moistureActivationPin = 5;

// Constants
const int MOISTURE_SENSOR_DRY = 700;
const int PUMPING_TIME = 10000;
const int AWAIT_TIME = 20000;

// Variables
int moistureSensorValue;

void setup() {
  Serial.begin(9600);

  pinMode(pumpPin, OUTPUT);
  pinMode(moistureActivationPin, OUTPUT);
  
  digitalWrite(pumpPin, HIGH);
  digitalWrite(moistureActivationPin, LOW);

  delay(2000);
}

void loop() {
  moistureSensorValue = readMoistureSensor();
  if (moistureSensorValue >= MOISTURE_SENSOR_DRY) {
    // Dry
    startPumpingWater();
    delay(PUMPING_TIME);
    stopPumpingWater();
  }
  // Should not measure again for a while
  delay(AWAIT_TIME);
}

void startPumpingWater() {
  digitalWrite(pumpPin, LOW);
}

void stopPumpingWater() {
  digitalWrite(pumpPin, HIGH);
}

int readMoistureSensor() {
  int value;
  digitalWrite(moistureActivationPin, HIGH);
  delay(1000);
  value = analogRead(moistureSensorPin);
  delay(1000);
  digitalWrite(moistureActivationPin, LOW);
  return value;
}