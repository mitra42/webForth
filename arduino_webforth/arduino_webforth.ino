#include "arduino_functions.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); // Initialize IO port TODO move to somewhere Forth wants it
  Serial.print(F("Starting: Space for, ")); Serial.print(RAMNAMEE - RAMCODEE), Serial.println(F("bytes for code and names"));
  IP = XT_COLD+CELLL; // This has a tight interaction with loop - which will look at next value and threadToken on it. (So this only works on a colon definition)
}

void loop() {
  threadtoken(IPnext());
}
