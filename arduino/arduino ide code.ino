const int motorPin1 = 10;
const int motorPin2 = 9;
const int motorPin3 = 3;
const int motorPin4 = 4;
const int ENA = 11;
const int ENB = 5;

int motorSpeed = 60;
char data;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();

    switch (data) {
      case 'W':
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin4, HIGH);
        break;
      case 'S':
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin4, LOW);
        break;
      case 'A':
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin4, LOW);
        break;
      case 'D':
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin4, HIGH);
        break;
      case 'X':
        motorSpeed = motorSpeed + 10;
        if (motorSpeed > 255) motorSpeed = 255;
        break;
      case 'C':
        motorSpeed = motorSpeed - 10;
        if (motorSpeed < 0) motorSpeed = 0;
        break;
      case 'V':
        motorSpeed = 0;
        if (motorSpeed < 0) motorSpeed = 0;
        break;
      default:
        motorSpeed = 0;
        break;
    }

    analogWrite(ENA, motorSpeed);
    analogWrite(ENB, motorSpeed);
  }
}