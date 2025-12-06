// Motor A
int pwmA = 5;
int in1A = 3;
int in2A = 4;

// Motor B
int pwmB = 6;
int in1B = 7;
int in2B = 8;

void setup() {
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
}

void loop() {

  // FORWARD
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  analogWrite(pwmA, 255);
  analogWrite(pwmB, 255);
  delay(2000);

  // BACKWARD
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);
  analogWrite(pwmA, 255);
  analogWrite(pwmB, 255);
  delay(2000);

}
