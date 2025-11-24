// One LED and Push Button

int buttonPin = 2;
int ledPin = 9;
void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  }

  if (buttonState == HIGH) {
    digitalWrite(ledPin, LOW);
  }
}