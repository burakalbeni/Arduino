int lightPin=A1;
int greenPin=8;
int redPin=9;
int lightVal;
int dv=250;
void setup(){
  pinMode(lightPin,INPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
lightVal=analogRead(lightPin);
Serial.println(lightVal);
if(lightVal<450){
  digitalWrite(redPin,HIGH);
}
else
  digitalWrite(redPin,LOW);
if(lightVal>450){
  digitalWrite(greenPin,HIGH);
}
else  
  digitalWrite(greenPin,LOW);
delay(dv);  
}
