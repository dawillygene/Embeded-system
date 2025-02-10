#include <Servo.h>
Servo myservo;

void setup(){
  myservo.attach(3);
  myservo.write(90);// move servos to center position -> 90°
} 
void loop(){
  myservo.write(90);// move servos to center position -> 90°
  delay(1000);
    myservo.write(180);// move servos to center position -> 90°
    delay(1000);
      myservo.write(360);// move servos to center position -> 90°
      delay(2000);
}
