
int outputSensor = 9;
int outputLed1 = 3;
int outputLed2 = 4;
int outputLed3 = 5;
int outputLed4 = 6;

int digitalPin = 2;
int analogPin = A0;
int digitalVal;
int analogVal;


void setup() {

  pinMode(outputSensor, OUTPUT);
  pinMode(outputLed1, OUTPUT);
  pinMode(outputLed2, OUTPUT);
  pinMode(outputLed3, OUTPUT);
  pinMode(outputLed4, OUTPUT);

  pinMode(digitalPin, INPUT);

  


  Serial.begin(9600);
}

void loop() {

  
  
  digitalWrite(outputLed1, HIGH);
  delay(100);
  digitalWrite(outputLed1, LOW);
  digitalWrite(outputLed2, HIGH);
  delay(100);
  digitalWrite(outputLed2, LOW);
  digitalWrite(outputLed3, HIGH);
  delay(100);
  digitalWrite(outputLed3, LOW);
  digitalWrite(outputLed4, HIGH);
  delay(100);
  digitalWrite(outputLed4, LOW);

  digitalVal = digitalRead(digitalPin);

  if(digitalVal == HIGH) {
    digitalWrite(outputSensor, HIGH);
  } else {
    digitalWrite(outputSensor, LOW);
  }

  analogVal = analogRead(analogPin);

  //Serial.println(analogVal);

}
