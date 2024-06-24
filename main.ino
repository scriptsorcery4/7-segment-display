const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8}; // Pins connected to the segments (a-g)

// Segment configurations for numbers 0-9
const byte digitPatterns[10] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Removes any whitespace from the start and end of the string

    if (command.length() == 1 && isDigit(command[0])) {
      int digit = command.toInt();
      displayDigit(digit);
      Serial.print("Displaying: ");
      Serial.println(digit);
    } else {
      Serial.println("Invalid command. Please enter a single digit (0-9).");
    }
  }
}

void displayDigit(int digit) {
  byte pattern = digitPatterns[digit];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(pattern, i));
  }
}
