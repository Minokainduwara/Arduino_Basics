// 4 digit 7 segment display

#include <SevSeg.h>

SevSeg sevseg;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5}; // Pins connected to the digit control
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pins connected to segments a-g and dp

  bool resistorsOnSegments = false; // 'true' means resistors are on segment pins
  byte hardwareConfig = COMMON_CATHODE; // Change to COMMON_ANODE if using common anode display
  bool updateWithDelays = false; // No delays in the display update
  bool leadingZeros = false; // Do not show leading zeros

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90); // Set brightness (0-100)
}

void loop() {
  sevseg.setNumber(3141,3); // Displays '3.141'
  sevseg.refreshDisplay();
 
}
