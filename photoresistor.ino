// Photoresistor to control LED brightness
const int sensorPin = A0;

int ledPins[] = {3,5,6,9,10,11};
int numLeds = 6;

void setup() {
  Serial.begin(9600);

  for(int i=0;i<numLeds;i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int ldr = analogRead(sensorPin);
  Serial.println(ldr);

  int brightness = map(ldr, 0, 1023, 0, 255);
  brightness = constrain(brightness, 0, 255);

  for(int i=0;i<numLeds;i++){
    analogWrite(ledPins[i], brightness);
  }

  delay(50);
}
