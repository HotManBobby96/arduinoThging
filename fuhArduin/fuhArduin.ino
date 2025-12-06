// defining the pins and what not
// Motor A
int pwmA = 5;
int in1A = 3;
int in2A = 4;

// Motor B
int pwmB = 6;
int in1B = 7;
int in2B = 8;

// Controlling the motors
void motorA(int speed) {
  if (speed >= 0) { // if greater than forwards
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(pwmA, speed);
  } else { // backward
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);
    analogWrite(pwmA, -speed);
  }
}

void motorB(int speed) {
  if (speed >= 0) {
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
    analogWrite(pwmB, speed);
  } else {
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
    analogWrite(pwmB, -speed);
  }
}

// Turning people
void turnHard(int direction, int speed, int duration) {
  // 1 = right -1 = left
  if (direction == 1) {
    motorA(speed);
    motorB(-speed);
  } else {
    motorA(-speed);
    motorB(speed);
  }
  delay(duration);
  stopMotors();
}

// direction: 1 = right, -1 = left
// difference = how much slower the inside wheel is
void turnSoft(int direction, int speed, int difference, int duration) {
  if(direction == 1) {
    motorA(speed);
    motorB(speed - difference);
  } else {
    motorA(speed - difference);
    motorB(speed);
  }
}

// stop function
void stopMotors() {
  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);
}

void setup() {
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
}

void loop() {

  motorA(255);
  motorB(255);
  delay(5000);

  motorA(-255);
  motorB(-255);
  delay(2000);

    turnHard(1, 200, 500); 


  turnSoft(-1, 200, 60, 1000); 

  stopMotors();

  while (1);

}
