int redPin=9;
int greenPin=6;
int bluePin=5;
int buttonlitPin=12;
int buttondimPin=11;
int lightValue=0;
int LEDState=0;
int buttonlitNew;
int buttondimNew;
int buttonlitOld=1;
int buttondimOld=1;
int delayT=250;
void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(buttondimPin,INPUT);
  pinMode(buttonlitPin,INPUT);
  Serial.begin(9600);

}

void loop() {
buttonlitNew=digitalRead(buttonlitPin);
buttondimNew=digitalRead(buttondimPin);
// THE CASE WHERE WE PUSH TO LİT 
  if(buttonlitOld==0 && buttonlitNew==1){
    if(LEDState==0){
        LEDState=1;
        lightValue++;
     }
      else{
        LEDState=0;
        lightValue++;
      }
  }
buttonlitOld=buttonlitNew;
//THE CASE WHERE WE PUSH TO DİM
  if(buttondimOld==0 && buttondimNew==1){
    if(LEDState==0){
        LEDState=1;
        lightValue--;
     }
      else{
        LEDState=0;
        lightValue--;
      }
  }
buttondimOld=buttondimNew;        
Serial.print("LighValue equals to ");
Serial.println(lightValue);
switch(lightValue){
  case 0: analogWrite(redPin,0);
          analogWrite(greenPin,0);
          analogWrite(bluePin,0);
  break;
  case 1: analogWrite(redPin,50);
          analogWrite(greenPin,50);
          analogWrite(bluePin,50);
  break;
  case 2: analogWrite(redPin,100);
          analogWrite(greenPin,100);
          analogWrite(bluePin,100);
  break;
  case 3: analogWrite(redPin,150);
          analogWrite(greenPin,150);
          analogWrite(bluePin,150);
  break;
  case 4: analogWrite(redPin,200);
          analogWrite(greenPin,200);
          analogWrite(bluePin,200);
  break;
  case 5: analogWrite(redPin,250);
          analogWrite(greenPin,250);
          analogWrite(bluePin,250);
  break;
}
if(lightValue>5)
lightValue=5;
if(lightValue<=0)
lightValue=0;
}
