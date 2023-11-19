int leftMotorFront = 3;
int leftMotorBack = 11;
int rightMotorFront = 6;
int rightMotorBack = 5;

int speed = 150;
int baseSpeed = speed; 

void setup() {
  Serial.begin(115200);
  pinMode(leftMotorFront, OUTPUT);
  pinMode(leftMotorBack, OUTPUT);
  pinMode(rightMotorFront, OUTPUT);
  pinMode(rightMotorBack, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int error = Serial.parseInt();
    Serial.print("Received Error: ");
    Serial.println(error);
    adjustMotors(error);
  }
}

void adjustMotors(int error) {
  // Stop all motors
  stopMotors();

  // Adjust the motors based on the error
  if (error < -190) {
    turnLeft();
  } else if (error > 190) {
    turnRight();
  } else {
    // Move forward or backward with the base speed
    moveForward();
  }
}

void moveForward() { // Figur 2: A
  setMotorSpeed(leftMotorFront, baseSpeed);
  setMotorSpeed(leftMotorBack, baseSpeed);
  setMotorSpeed(rightMotorFront, baseSpeed);
  setMotorSpeed(rightMotorBack, baseSpeed);
}

void turnLeft() { // Figur 2 D 
  setMotorSpeed(leftMotorBack, baseSpeed);
  setMotorSpeed(leftMotorBack, baseSpeed);
}

void turnRight() {
  setMotorSpeed(rightMotorFront, baseSpeed);
  setMotorSpeed(rightMotorBack, baseSpeed);
}

void turnRotateRight() { // Figure 2: e

  setMotorSpeed(leftMotorFront, -baseSpeed);
  setMotorSpeed(leftMotorBack, -baseSpeed);
  setMotorSpeed(rightMotorFront, baseSpeed);
  setMotorSpeed(rightMotorBack, baseSpeed);
}

void turnRotateLeft() { // Figure 2: e

  setMotorSpeed(leftMotorFront, baseSpeed);
  setMotorSpeed(leftMotorBack, baseSpeed);
  setMotorSpeed(rightMotorFront, -baseSpeed);
  setMotorSpeed(rightMotorBack, -baseSpeed);
}

void turnScrollRight() { // Figure 2: B

  setMotorSpeed(leftMotorFront, -baseSpeed);
  setMotorSpeed(leftMotorBack, baseSpeed);
  setMotorSpeed(rightMotorFront, baseSpeed);
  setMotorSpeed(rightMotorBack, -baseSpeed);
}

void turnScrollLeft() { // Figure 2: B 

  setMotorSpeed(leftMotorFront, baseSpeed);
  setMotorSpeed(leftMotorBack, -baseSpeed);
  setMotorSpeed(rightMotorFront, -baseSpeed);
  setMotorSpeed(rightMotorBack, baseSpeed);
}

void turnDiagonallyRight() { // Figure 2: c
  setMotorSpeed(leftMotorFront, baseSpeed);
  setMotorSpeed(rightMotorBack, baseSpeed);
}

void turnDiagonallyLeft() { // Figure 2: c
  setMotorSpeed(rightMotorFront, baseSpeed);
  setMotorSpeed(leftMotorBack, baseSpeed);
}

void turnSharpTurnRight() { //Figure 2: f
  setMotorSpeed(rightMotorFront, baseSpeed);
  setMotorSpeed(leftMotorFront, -baseSpeed);
}

void turnSharpTurnLeft() { //Figure 2: f
  setMotorSpeed(rightMotorFront, -baseSpeed);
  setMotorSpeed(leftMotorFront, baseSpeed);
}

void setMotorSpeed(int motorPin, int speed) {

  analogWrite(motorPin, speed);
}

void stopMotors() {
  digitalWrite(leftMotorFront, LOW);
  digitalWrite(leftMotorBack, LOW);
  digitalWrite(rightMotorFront, LOW);
  digitalWrite(rightMotorBack, LOW);
}