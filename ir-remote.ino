#include <IRremote.h>  // use the IRRemote.h
const int irReceiverPin = 2;  //the SIG of receiver module attach to pin2
IRrecv irrecv(irReceiverPin); //Creates a variable of type IRrecv
decode_results results;    // define resultsas 
const int ledPIN =  3;
const int led13 =  13;
//int ledState = LOW;

void setup()
{
  pinMode(ledPIN, OUTPUT);
  pinMode(led13, OUTPUT);
  Serial.begin(9600);    //initialize serial,baudrate is 9600
  irrecv.enableIRIn();   // enable ir receiver module
}

void loop() 
{
  if (irrecv.decode(&results)) //if the ir receiver module receiver data
  {  
    if (results.value== 3772790473) {
      digitalWrite(ledPIN, HIGH);
       digitalWrite(led13, HIGH);
      } else if (results.value==3772786903) {
      digitalWrite(ledPIN, LOW);
       digitalWrite(led13, LOW);
    }
     Serial.print(results.value);
    //Serial.print("irCode: ");    //print "irCode: "        
    //Serial.print(results.value, HEX); //print the value in hexdecimal 
    //Serial.print(",  bits: ");  //print" , bits: "         
    //Serial.println(results.bits); //print the bits
    irrecv.resume();    // Receive the next value 
  }  
  delay(600); //delay 600ms
}
