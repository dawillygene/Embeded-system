#define blick 3
#define ldr A0
void setup() {
  Serial.begin(9600);
  pinMode(blick,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop() {
float ldr_reading=analogRead(ldr);
int p=(ldr_reading/1023)*5;
Serial.println(p);
delay(1000);
}
