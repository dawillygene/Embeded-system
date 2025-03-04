const int buttonPin1 = 2, buttonPin2 = 3;  // the number of the pushbutton pins
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int button1_State = 0, button2_State = 0;  // variable for reading the pushbuttons status
int count_value =0;
int prestate =0;
void setup() {
  // initialize the LED pin as an output
  //LED flashes during both increment and decrement of counter
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton
  button1_State = digitalRead(buttonPin1);
  button2_State = digitalRead(buttonPin2);
  // counter increment if the pushbutton 1 is pressed.
  if (button1_State == HIGH && prestate == 0) {
    count_value++;
      Serial.println(count_value);
    // turn LED on
    
