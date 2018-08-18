// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <CAN.h> // the OBD2 library depends on the CAN library
#include <OBD2.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println(F("OBD2 Supported PIDs"));

  while (true) {
    Serial.print(F("Attempting to connect to OBD2 CAN bus ... "));

    if (!OBD2.begin()) {
      Serial.println(F("failed!"));

      delay(1000);
    } else {
      Serial.println(F("success"));
      break;
    }
  }

  Serial.println();

  // loop through PIDs 0 to 95, reading and printing the names of the supported PIDs
  for (int pid = 0; pid < 96; pid++) {
    if (OBD2.pidSupported(pid)) {
      Serial.println(OBD2.pidName(pid));
    }
  }
}

void loop() {
}

