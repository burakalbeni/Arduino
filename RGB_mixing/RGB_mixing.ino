int greenPin=9;
int bluePin=10;
int redPin=11;
int randomNumred;
int randomNumblue;
int randomNumgreen;
int delayT=300;
void setup(){  
Serial.begin(9600);
pinMode(bluePin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
}

void loop() {
  randomNumred=rand() % 255;
  randomNumgreen=rand() % 255;
  randomNumblue=rand() % 255;
  Serial.print("The value of red is: ");
  Serial.println(randomNumred);
  Serial.print("The value of green is: ");
  Serial.println(randomNumgreen);
  Serial.print("The value of blue is: ");
  Serial.println(randomNumblue);
  Serial.println("---------------------------");
  analogWrite(redPin,randomNumred);
  analogWrite(greenPin,randomNumgreen); 
  analogWrite(bluePin,randomNumblue);
  delay(delayT); 
} 
