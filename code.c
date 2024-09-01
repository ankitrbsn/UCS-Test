#define trigPin 10
#define echoPin 13
#define soundSpeedInAir 331.5 // m/s at 0 degrees Celsius and 0%
humidity
float duration, distance;
float temperature = 25.7; // Temperature in degrees Celsius
float humidity = 59.0; // Relative humidity in percentage
void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
// Write a pulse to the HC-SR04 Trigger Pin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Measure the response from the HC-SR04 Echo Pin
duration = pulseIn(echoPin, HIGH);
// Calculate the speed of sound based on temperature and humidity
float soundSpeed = soundSpeedInAir + (0.606 * temperature) + (0.124
* humidity );
// Calculate the adjusted distance measurement
distance = (duration / 2) * (soundSpeed / 10000); // Convert to cm
and four decimal places
// Send results to Serial Monitor
Serial.print("Distance = ");
if (distance >= 400 || distance <= 2) {
Serial.println("Out of range");
} else {
Serial.print(distance, 5); // Display with four decimal places
Serial.println(" cm");
}
delay(12000);
}
