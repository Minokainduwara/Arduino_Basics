// 7 Segment Display 0 - 9


byte pin[] = {2, 3, 4, 5, 6, 7, 8}; // Arduino pins connected to segments a-g

// Number encoding for 0-9 (common cathode)
int number[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  for (byte i = 0; i < 7; i++) {
    pinMode(pin[i], OUTPUT); // set all pins as outputs
  }
}

void loop() {
  for (int num = 0; num < 10; num++) {      // loop through numbers 0-9
    for (int seg = 0; seg < 7; seg++) {
      digitalWrite(pin[seg], number[num][seg]); // light up segments
    }
    delay(500); // display each number for 0.5 seconds
  }
}
