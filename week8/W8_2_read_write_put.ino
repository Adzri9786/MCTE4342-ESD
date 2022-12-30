#include <EEPROM.h>

void setup() {
  // Set the value to be written to the EEPROM memory
  int value = 123;

  // Write the value to the EEPROM memory
  EEPROM.write(0, value); /*function takes two arguments: the location in the EEPROM memory to write to (specified as an integer),
  and the value to write (specified as a byte, char, int, or long).*/

    // Read the value from the first location in the EEPROM memory
  int value2 = EEPROM.read(0);

  // Print the value to the serial monitor
  Serial.begin(9600);
  Serial.println(value2);

  // Set the value to be written to the EEPROM memory
  float value3 = 3.14;

  // Write the value to the EEPROM memory
  EEPROM.put(0, value3);
}

void loop() {
  // The value has already been written to the EEPROM memory in the setup function,
  // so there is nothing to do in the loop function
}
