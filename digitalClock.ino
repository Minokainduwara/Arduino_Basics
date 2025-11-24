#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Time variables
int h = 12;
int m = 0;
int s = 0;

// Buttons
const int btnHour = A0;
const int btnMin  = A1;

unsigned long lastMillis = 0;

void setup() {
  lcd.begin(16,2);

  pinMode(btnHour, INPUT_PULLUP);
  pinMode(btnMin, INPUT_PULLUP);

  lcd.setCursor(0,0);
  lcd.print("Digital Clock");
  delay(1500);
  lcd.clear();
}

void loop() {

  // ---------- Time increase every 1 second ----------
  if (millis() - lastMillis >= 1000) {
    lastMillis = millis();
    s++;

    if (s >= 60) {
      s = 0;
      m++;
    }

    if (m >= 60) {
      m = 0;
      h++;
    }

    if (h >= 24) {
      h = 0;
    }
  }

  // ---------- Button for HOURS ----------
  if (digitalRead(btnHour) == LOW) {
    delay(200); // debounce
    h++;
    if (h >= 24) h = 0;
  }

  // ---------- Button for MINUTES ----------
  if (digitalRead(btnMin) == LOW) {
    delay(200); // debounce
    m++;
    if (m >= 60) m = 0;
  }

  // ---------- Display Time ----------
  lcd.setCursor(0,0);
  lcd.print("Time: ");

  if (h < 10) lcd.print("0");
  lcd.print(h);
  lcd.print(":");

  if (m < 10) lcd.print("0");
  lcd.print(m);
  lcd.print(":");

  if (s < 10) lcd.print("0");
  lcd.print(s);

  lcd.setCursor(0,1);
  lcd.print("Set Hr / Min ");
}
