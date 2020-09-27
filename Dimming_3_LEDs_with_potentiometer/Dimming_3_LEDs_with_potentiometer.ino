int myVoltPin=A2;
int readVal;
int input_readVal;
float V2;
int redPin=9;
int bluePin=10;
int greenPin=11;
void setup() {
Serial.begin(9600);
pinMode(myVoltPin,INPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(greenPin,OUTPUT);
}

void loop() {
readVal=analogRead(myVoltPin);
V2=(5./1023.)*readVal;
input_readVal=readVal/4; // readVal value is 1023 maximum but we can only give 255 as maximum for analog write
Serial.print("Potentiometer Voltage is ");
Serial.println(V2);
analogWrite(redPin,input_readVal);
analogWrite(bluePin,input_readVal);
analogWrite(greenPin,input_readVal);  
}
