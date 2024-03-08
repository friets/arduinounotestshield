/*
unotestshieldprego script by KumBaTechnologies
to test the analogue and digital pins of the Arduino Uno
and confirm they are working properly with LOW and HIGH
pinD0 and pinD1 are for serial monitoring
if the serial works than they are working correctly
pinD2 and forward sends to the next pinD3
which should return the HIGH or LOW
analogPins are to be sending and receiving digital signals
the pins are connected via a 10Kohm resistor to limit current
*/

byte incomingbyte;
int pinD2 = 2;
int pinD3 = 3;//arduino zero m0 has pin 2 and pin 4 mixed up
int pinD4 = 4; 
int pinD5 = 5; 
int pinD6 = 6; 
int pinD7 = 7; 
int pinD8 = 8; 
int pinD9 = 9; 
int pinD10 = 10;
int pinD11 = 11;
int pinD12 = 12;
int pinD13 = 13;
int pinA0 = A0;//14
int pinA1 = A1;//15
int pinA2 = A2;//16
int pinA3 = A3;//17
int pinA4 = A4;//18
int pinA5 = A5;//19
int pinnumber;
int val;
int error=false;
int i=0;

void setup()
{
//SerialUSB.begin(9600); for arduino zero m0
Serial.begin(9600);
while (!Serial) {
//while (!SerialUSB) { ?? for arduino zero m0
// wait for serial port to connect. Needed for native USB
}
 
}
void loop()
{
  for (pinnumber=2; pinnumber <=A4; pinnumber=pinnumber+2)
{
pinMode(pinnumber, INPUT);//2
pinMode(pinnumber+1, OUTPUT);//3
Serial.print("pin ");
Serial.print(pinnumber);
digitalWrite(pinnumber+1, LOW);//3
val=digitalRead(pinnumber);//2
MustBe0(pinnumber);//2
pinMode(pinnumber, INPUT);//2
pinMode(pinnumber+1, OUTPUT);//3
digitalWrite(pinnumber+1, HIGH);//3
val=digitalRead(pinnumber);//2
MustBe1(pinnumber);//2
Serial.println();

pinMode(pinnumber+1, INPUT);//3
pinMode(pinnumber, OUTPUT);//2
Serial.print("pin");
Serial.print(pinnumber+1);
digitalWrite(pinnumber, LOW);//2
val=digitalRead(pinnumber+1);//3
MustBe0(pinnumber+1);//3
pinMode(pinnumber+1, INPUT);//3
pinMode(pinnumber, OUTPUT);//2
digitalWrite(pinnumber, HIGH);//2
val=digitalRead(pinnumber+1);//3
MustBe1(pinnumber+1);//3
Serial.println();
}

if (error==true){
  Serial.println("board = defective!");
}
  else{
    Serial.println("board = OK!");
  }
Serial.println("to repeat press enter!");
while (Serial.available() == i) {}//will repeat after keypressed
i++;
}   
void MustBe0( int x )
{
// SerialUSB.println(x);
Serial.println();
Serial.println(x);
Serial.println(val);
delay(1000);
  
  if (val==LOW) {
   Serial.println("=ok");}
 else {
   error=true;
   Serial.println("=error");}
}
void MustBe1( int x )
{
// SerialUSB.println(x);
Serial.println(x);
Serial.println(val);
delay(1000);
  
  if (val==HIGH){
   Serial.println("=ok");}
 else {
   error=true;
   Serial.println("=error");}
}