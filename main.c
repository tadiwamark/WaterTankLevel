m/*
 * Arthor: Tadiwanashe Nyaruwata
 * 28-10-2021
 */

#define TRIG_PIN 11
#define ECHO_PIN 12
#define LED_PIN_MAX1 3
#define LED_PIN_MAX2 4

int command = 'S';
int lastCommand = command;
bool forward = true;
long distance;

void setup() {
  // Set pins as outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, OUTPUT);

  pinMode(LED_PIN_MAX1, OUTPUT);
   pinMode(LED_PIN_MAX2, OUTPUT);

  // Initialize serial data communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  readDistanceInFront();

  // Save data if received
  if (Serial.available() > 0) {
    command = Serial.read();
    lastCommand = command;
  }
}


void readDistanceInFront() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  distance = 2 + (pulseIn(ECHO_PIN, HIGH) / 2) * 0.0343;
  if (distance > 90) {
    digitalWrite(LED_PIN_MAX1, HIGH);
    digitalWrite(LED_PIN_MAX2, LOW);
  } else{
    digitalWrite(LED_PIN_MAX1, HIGH);
    digitalWrite(LED_PIN_MAX2, LOW);
  }
  if (distance < 10){
    digitalWrite(LED_PIN_MAX2, HIGH);
    digitalWrite(LED_PIN_MAX1, LOW);
  } else {
    digitalWrite(LED_PIN_MAX1, HIGH);
    digitalWrite(LED_PIN_MAX2, LOW);
  }
  Serial.print(distance);
  Serial.print('#');
}