// Define IR sensor pin and LED pin
int irSensorPin = 2;
int ledPin = 13;

// Set count threshold
int countThreshold = 10;

// Initialize count variable
int count = 1;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set IR sensor pin as input
  pinMode(irSensorPin, INPUT);

  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read IR sensor value
  int irSensorValue = digitalRead(irSensorPin);

  // Check if object has passed by IR sensor
  if (irSensorValue == LOW) {
    // Increment count
    count++;

    // Print count to serial monitor
    Serial.print("Count: ");
    Serial.println(count);

    // Check if count threshold has been reached
    if (count%2==0) {
      // Turn on LED
      digitalWrite(ledPin,LOW);
    }
    else{
      digitalWrite(ledPin, HIGH);
      }
  }

  // Delay to prevent rapid counting
  delay(1000);
}
