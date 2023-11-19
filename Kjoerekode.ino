int leftMotorFront = 3;
int leftMotorBack = 11;
int rightMotorFront = 6;
int rightMotorBack = 5;

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
  digitalWrite(leftMotorFront, LOW);
  digitalWrite(leftMotorBack, LOW);
  digitalWrite(rightMotorFront, LOW);
  digitalWrite(rightMotorBack, LOW);

  // Adjust the motors based on the error
  if (error < -190) {
    turnLeft();
  } else if (error > 190) {
    turnRight();
  } else {
    // Move forward or backward
    digitalWrite(leftMotorFront, HIGH);
    digitalWrite(rightMotorFront, HIGH);
  }
}

void turnLeft() {
  digitalWrite(leftMotorBack, HIGH);
  digitalWrite(rightMotorFront, HIGH);
}

void turnRight() {
  digitalWrite(leftMotorFront, HIGH);
  digitalWrite(rightMotorBack, HIGH);

void turnDiagonally() {

}
void turnRotate() {

}

void turnScrollRight() {

}

void turnScrollLeft() {

}

void turnForward() {
  
}
}