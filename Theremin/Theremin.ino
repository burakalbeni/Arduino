#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=3;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


int trigPin=2;
int echoPin=4;
float pingTravelTime;
float distance;
float soundSpeed=0.0343;//In centimeters per microsecond
int dt=100; // Led display delay
int dts=0; //Sound delay;

int bluePin=9;
int greenPin=5;
int redPin=6;



//Lets define rgb values
 int redPinVal;
 int bluePinVal;
 int greenPinVal;
 
 int frequency; // Frequency of the sound created by passive buzzer
 int speakerPin=1; // Buzzer pin
 
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 100};
//            mid C  C#   D    D#   E    F    F#   G    G#   A  Frequencies of some notes

void setup() {
 
pinMode(speakerPin,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
 //Serial.begin(9600);
pinMode(bluePin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
lcd.begin(16,2);
    
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin,LOW);
  pingTravelTime=pulseIn(echoPin,HIGH);
  distance=pingTravelTime*soundSpeed/2;
  theremin();
}

void theremin(){       
      while(distance<=15){  
         redPinVal=255;
         greenPinVal=map(distance,0,15,0,100);
         bluePinVal=0;
         analogWrite(redPin,redPinVal); 
         analogWrite(greenPin,greenPinVal);
         analogWrite(bluePin,bluePinVal);
    digitalWrite(trigPin,LOW);
    delayMicroseconds(1);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(1);
    digitalWrite(trigPin,LOW);
    pingTravelTime=pulseIn(echoPin,HIGH);
    distance=pingTravelTime*soundSpeed/2;     
  lcd.setCursor(0,0);
  lcd.print("Distance= " );
  lcd.print(round(distance));
  lcd.setCursor(0,1);
  lcd.print("centimeters " );
  delay(dt);
  lcd.clear();
   frequency=map(distance, 0,60, 100,1000);
   tone(speakerPin,frequency);
  // delay(dts); 
   //noTone(speakerPin);
  /*Serial.print("The distance to the object is ");
  Serial.print(distance);
  Serial.println(" ");
  Serial.print("The value of the red is ");
  Serial.print(redPinVal);
  Serial.println(" ");
  Serial.print("The value of the green is ");
  Serial.print(greenPinVal);
  Serial.println(" ");
  Serial.print("The value of the blue is ");
  Serial.print(bluePinVal);
  Serial.println(" ");
*/      
      }
    while(distance>15 and distance<=30){
        greenPinVal=100;
        redPinVal=map(distance,15,30,255,0);
        bluePinVal=0;    
         analogWrite(redPin,redPinVal); 
         analogWrite(greenPin,greenPinVal);
         analogWrite(bluePin,bluePinVal);   
      digitalWrite(trigPin,LOW);
      delayMicroseconds(1);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(1);
      digitalWrite(trigPin,LOW);
      pingTravelTime=pulseIn(echoPin,HIGH);
      distance=pingTravelTime*soundSpeed/2;  
  lcd.setCursor(0,0);
  lcd.print("Distance= " );
  lcd.print(round(distance));
  lcd.setCursor(0,1);
  lcd.print("centimeters " );
  delay(dt);
  lcd.clear();
   frequency=map(distance, 0,60, 100,1000);
   tone(speakerPin,frequency);
   //delay(dts);
   //noTone(speakerPin);
   /*
  Serial.print("The distance to the object is ");
  Serial.print(distance);
  Serial.println(" ");
  Serial.print("The value of the red is ");
  Serial.print(redPinVal);
  Serial.println(" ");
  Serial.print("The value of the green is ");
  Serial.print(greenPinVal);
  Serial.println(" ");
  Serial.print("The value of the blue is ");
  Serial.print(bluePinVal);
  Serial.println(" ");
*/
    }
    while(distance>30 and distance<=45){  
        greenPinVal=100;
        redPinVal=0;
        bluePinVal=map(distance,30,45,0,255);
         analogWrite(redPin,redPinVal); 
         analogWrite(greenPin,greenPinVal);
         analogWrite(bluePin,bluePinVal);  
      digitalWrite(trigPin,LOW);
      delayMicroseconds(1);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(1);
      digitalWrite(trigPin,LOW);
      pingTravelTime=pulseIn(echoPin,HIGH);
      distance=pingTravelTime*soundSpeed/2;
  lcd.setCursor(0,0);
  lcd.print("Distance= " );
  lcd.print(round(distance));
  lcd.setCursor(0,1);
  lcd.print("centimeters " );
  delay(dt);
  lcd.clear();
   frequency=map(distance, 0,60, 100,1000);
   tone(speakerPin,frequency);
   //delay(dts);
   //noTone(speakerPin);
/*
  Serial.print("The distance to the object is ");
  Serial.print(distance);
  Serial.println(" ");
  Serial.print("The value of the red is ");
  Serial.print(redPinVal);
  Serial.println(" ");
  Serial.print("The value of the green is ");
  Serial.print(greenPinVal);
  Serial.println(" ");
  Serial.print("The value of the blue is ");
  Serial.print(bluePinVal);
  Serial.println(" ");
*/
    }
  while(distance>45 && distance<=60){  
        greenPinVal=map(distance, 45,60, 50,0);
        redPinVal=0;
        bluePinVal=255;
         analogWrite(redPin,redPinVal); 
         analogWrite(greenPin,greenPinVal);
         analogWrite(bluePin,bluePinVal);
      digitalWrite(trigPin,LOW);
      delayMicroseconds(1);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(1);
      digitalWrite(trigPin,LOW);
      pingTravelTime=pulseIn(echoPin,HIGH);
      distance=pingTravelTime*soundSpeed/2;
  lcd.setCursor(0,0);
  lcd.print("Distance= " );
  lcd.print(round(distance));
  lcd.setCursor(0,1);
  lcd.print("centimeters " );
  delay(dt);
  lcd.clear();
   frequency=map(distance, 0,60, 100,1000);
   tone(speakerPin,frequency);
   //delay(dts);
   //noTone(speakerPin);
  /*
  Serial.print("The distance to the object is ");
  Serial.print(distance);
  Serial.println(" ");
  Serial.print("The value of the red is ");
  Serial.print(redPinVal);
  Serial.println(" ");
  Serial.print("The value of the green is ");
  Serial.print(greenPinVal);
  Serial.println(" ");
  Serial.print("The value of the blue is ");
  Serial.print(bluePinVal);
  Serial.println(" ");
*/
    }
      while(distance>60){
       // greenPinVal=map(distance, 45,60, 100,0);
        //redPinVal=0;
        bluePinVal=255;
        // analogWrite(redPin,redPinVal); 
         //analogWrite(greenPin,greenPinVal);
         analogWrite(bluePin,bluePinVal);
      digitalWrite(trigPin,LOW);
      delayMicroseconds(1);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(1);
      digitalWrite(trigPin,LOW);
      pingTravelTime=pulseIn(echoPin,HIGH);
      distance=pingTravelTime*soundSpeed/2;
  lcd.setCursor(0,0);
  lcd.print("Distance= " );
  lcd.print(round(distance));
  lcd.setCursor(0,1);
  lcd.print("centimeters " );
  delay(dt);
  lcd.clear();
  frequency=map(distance, 0,60, 100,1000);
   //tone(speakerPin,0);
   //delay(dts);
   noTone(speakerPin);
  /*
  Serial.print("The distance to the object is ");
  Serial.print(distance);
  Serial.println(" ");
  Serial.print("The value of the red is ");
  Serial.print(redPinVal);
  Serial.println(" ");
  Serial.print("The value of the green is ");
  Serial.print(greenPinVal);
  Serial.println(" ");
  Serial.print("The value of the blue is ");
  Serial.print(bluePinVal);
  Serial.println(" ");
*/
    }

}
