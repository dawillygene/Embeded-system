
// Include Arduino Wire library for I2C
#include <Wire.h>
// Include LCD display library for I2C
#include <LiquidCrystal_I2C.h>
// Include Keypad library
#include <Keypad.h>

// Length of password + 1 for null character
#define Password_Length 5
// Character to hold password input
char Data[Password_Length];
// Password
char Master[Password_Length] = "6985";

// Pin connected to lock relay input
int green = 13;
int red = 10;
// Counter for character entries
byte data_count = 0;

// Character to hold key input
char customKey;

// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'7', '4', '1', '*'},
  {'8', '5', '2', '0'},
  {'9', '6', '3', '#'},
  {'/', 'X', '-', '+'}
};

// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Create LCD object
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // Setup LCD with backlight and initialize
  lcd.backlight();
  lcd.init();
  Serial.begin(9600);
  // Set lockOutput as an OUTPUT pin
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {

  // Initialize LCD and print
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  Serial.println("Enter Password:");
  // Look for keypress
  customKey = customKeypad.getKey();
  if (customKey) {
    // Enter keypress into array and increment counter
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    Serial.println(Data[data_count]);
    data_count++;
  }

  // See if we have reached the password length
  if (data_count == Password_Length - 1) {
    lcd.clear();

    if (!strcmp(Data, Master)) {
      // Password is correct
      lcd.print("Correct");
      Serial.println("Correct");
      // Turn on relay for 5 seconds
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      delay(5000);
      digitalWrite(green, LOW);
    }
    else {
      // Password is incorrect
      lcd.print("Incorrect");
      Serial.println("Incorrect");
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      delay(1000);
      digitalWrite(red, LOW);
    }

    // Clear data and LCD display
    lcd.clear();
    clearData();
  }
}

void clearData() {
  // Go through array and clear data
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}
