// Setup
const int soundSensor = A1;   
const int redPin = 3;         
const int greenPin = 5;       
const int bluePin = 6;        

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundValue = analogRead(soundSensor); // read sound
  Serial.println(soundValue);

  // Reset color
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  if (soundValue < 300) {
    digitalWrite(bluePin, HIGH);   // quiet means green
  }
  else if (soundValue < 600) {
    digitalWrite(greenPin, HIGH);  // medium means green
  }
  else {
    digitalWrite(redPin, HIGH);    // loud means red, which alerts the person
  }

  delay(100);
}

