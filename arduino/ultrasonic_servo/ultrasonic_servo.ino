#include <Servo.h>
#include "controller.h"

// Pin mapping is a reproducible EXAMPLE, not a readback of the original project.
constexpr byte kTrigPin = 9;
constexpr byte kEchoPin = 10;
constexpr byte kServoPin = 6;
constexpr unsigned long kEchoTimeoutMicroseconds = 30000UL;

Servo gateServo;

void setup() {
  pinMode(kTrigPin, OUTPUT);
  pinMode(kEchoPin, INPUT);
  digitalWrite(kTrigPin, LOW);
  gateServo.attach(kServoPin);
  gateServo.write(0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(kTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(kTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(kTrigPin, LOW);

  const unsigned long duration = pulseIn(kEchoPin, HIGH, kEchoTimeoutMicroseconds);
  const bool echoValid = duration > 0;
  // Round-trip ultrasound travel time: 0.0343 cm/microsecond / 2.
  const int distanceCm = echoValid ? static_cast<int>(duration * 0.0343 / 2.0) : 0;
  const int angle = targetServoAngle(distanceCm, echoValid);
  gateServo.write(angle);

  Serial.print("distance_cm=");
  if (echoValid) Serial.print(distanceCm);
  else Serial.print("NO_ECHO");
  Serial.print(";servo_deg=");
  Serial.println(angle);
  delay(150);
}
