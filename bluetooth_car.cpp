#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor1(1); // Motor 1 on M1
AF_DCMotor motor2(2); // Motor 2 on M2

SoftwareSerial bluetooth(2, 3); // RX, TX

void setup() {
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() >= 2) {
    int command = bluetooth.read();
    int speed = bluetooth.read();

    // Forward
    if (command == 'F') {
      motor1.setSpeed(speed);
      motor2.setSpeed(speed);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    }
    // Backward
    else if (command == 'B') {
      motor1.setSpeed(speed);
      motor2.setSpeed(speed);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
    }
    // Left
    else if (command == 'L') {
      motor1.setSpeed(speed);
      motor1.run(FORWARD);
      motor2.setSpeed(speed);
      motor2.run(BACKWARD);
    }
    // Right
    else if (command == 'R') {
      motor1.setSpeed(speed);
      motor1.run(BACKWARD);
      motor2.setSpeed(speed);
      motor2.run(FORWARD);
    }
    // Stop
    else if (command == 'S') {
      motor1.setSpeed(0);
      motor2.setSpeed(0);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
  }
}
