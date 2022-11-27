#include <Servo.h>

Servo myservo;
int pos = 0;
int led = 6;

int trigPinLid = 2;
int echoPinLid = 3;
int distanceLid;
long durationLid; 

int trigPinCap = 4;
int echoPinCap = 5;
int distanceCap;
long durationCap; 

long startTime = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  DDRD = B01010100;




  Serial.begin(9600);

}

void loop() {

  while(sonarCapacity() <= 20){
    //led turn on
    Serial.println("The bin is full init mate");
  }

  if(sonarLid() <= 20){
    servoOpen();

    while(sonarLid() <= 20){

      if(sonarLid() > 20){
        break;
      }
      
    }
    servoClose();
  }

}

void servoOpen(){
  
  Serial.println("The lid is opening...");  
  for (pos = 0; pos <= 100; pos += 1){ // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position
  }


}

void servoClose(){
  
  Serial.println("The lid is closing...");
  for (pos; pos >= 0; pos -= 1){ // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}


int sonarLid(){

  digitalWrite(trigPinLid, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds

  digitalWrite(trigPinLid, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPinLid, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds

  durationLid = pulseIn(echoPinLid, HIGH);
  // Calculating the distance
  distanceLid = durationLid * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.println(distanceLid);

  return distanceLid;
}

int sonarCapacity(){

  digitalWrite(trigPinCap, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds

  digitalWrite(trigPinCap, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPinCap, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationCap = pulseIn(echoPinCap, HIGH);

  // Calculating the distance
  distanceCap = durationCap * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return 21;//distanceCap;

}