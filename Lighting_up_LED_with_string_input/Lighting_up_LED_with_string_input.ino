int redPin=6;
int greenPin=9;
int bluePin=10;
String ledName;
String msg="Which LED would you like lit";
String msg2="Lighting up ";
void setup() {
Serial.begin(9600);  
pinMode(bluePin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
}

void loop() {
  Serial.println(msg);
  while(Serial.available()==0){
          
  }
  ledName=Serial.readString();
  Serial.print(msg2);
  Serial.println(ledName);

  if(ledName=="blue"||ledName=="Blue"){
    analogWrite(bluePin,255);
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
  }  
  if(ledName=="green"||ledName=="Green"){
    analogWrite(bluePin,0);
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
  }  
  if(ledName=="red"||ledName=="Red"){
    analogWrite(bluePin,0);
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
  }  
} 
