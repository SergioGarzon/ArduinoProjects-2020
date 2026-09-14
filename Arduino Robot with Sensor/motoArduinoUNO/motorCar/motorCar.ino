int motorLeft = 8;
int motorLeft2 = 9;
int velocityLeftMotor = 10;

int motorRight = 6;
int motorRight2 = 7;
int velocityRightMotor = 5;

int triggerSensorIzq = 4;
int echoSensorIzq = 3;
int durationSensorIzq;
int distanceSensorIzq;

int triggerSensorRight = 12;
int echoSensorRight = 11;
int durationSensorRight;
int distanceSensorRight;


void setup() {
  
  pinMode(velocityLeftMotor, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorLeft2, OUTPUT);

  pinMode(motorRight, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(velocityRightMotor, OUTPUT);

  pinMode(triggerSensorIzq, OUTPUT);
  pinMode(echoSensorIzq, INPUT);

  pinMode(triggerSensorRight, OUTPUT);
  pinMode(echoSensorRight, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  digitalWrite(triggerSensorIzq, HIGH);
  delay(1);
  digitalWrite(triggerSensorIzq, LOW);
  durationSensorIzq = pulseIn(echoSensorIzq, HIGH);
  distanceSensorIzq = durationSensorIzq / 58.2;
  
  delay(200);

  if(distanceSensorIzq > 5) {
    analogWrite(velocityRightMotor, 100);
    digitalWrite(motorRight, LOW);
    digitalWrite(motorRight2, HIGH);
  } else {
    analogWrite(velocityRightMotor, 100);
    digitalWrite(motorRight, LOW);
    digitalWrite(motorRight2, LOW);
  }


  digitalWrite(triggerSensorRight, HIGH);
  delay(1);
  digitalWrite(triggerSensorRight, LOW);
  durationSensorRight = pulseIn(echoSensorRight, HIGH);
  distanceSensorRight = durationSensorRight / 58.2;
  
  delay(200);

  if(distanceSensorRight > 5) {
    analogWrite(velocityLeftMotor, 100);  //225 era la maxima creo
    digitalWrite(motorLeft, LOW);
    digitalWrite(motorLeft2, HIGH);
  } else {
    analogWrite(velocityLeftMotor, 100);  //225 era la maxima creo
    digitalWrite(motorLeft, LOW);
    digitalWrite(motorLeft2, LOW);
  }
  
  delay(100);
  
}
