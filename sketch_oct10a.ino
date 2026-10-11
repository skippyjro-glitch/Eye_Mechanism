#include <Servo.h>

Servo rightLeftServo;

#define left 180
#define right 90
#define middle 135
#define minMovement 30

//#define waitTime 2000
//#define moveSpeed 10

int currentPos = middle;

void setup() {
  rightLeftServo.attach(5);

  rightLeftServo.write(middle);
  delay(1000);

  randomSeed(analogRead(A0));
}

void loop() {
  int newPos;

  do{
    newPos=random(right, left+1);
  } while(abs(newPos-currentPos)<minMovement);

  int moveSpeed = random(5, 21);

  if(newPos>currentPos){
    for(int pos=currentPos; pos<=newPos; pos++){
      rightLeftServo.write(pos);
      delay(moveSpeed);
    }
  }
    else {
      for(int pos = currentPos; pos >= newPos; pos--){
        rightLeftServo.write(pos);
        delay(moveSpeed);
      }
    }

    currentPos=newPos;

    delay(random(500,3001));
}
