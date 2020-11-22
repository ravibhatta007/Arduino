/* YourDuinoStarter Example: nRF24L01 Receive Joystick values

 - WHAT IT DOES: Receives data from another transceiver with
   2 Analog values from a Joystick or 2 Potentiometers
   Displays received values on Serial Monitor
 - SEE the comments after "//" on each line below
 - CONNECTIONS: nRF24L01 Modules See:
 http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9   7
   4 - CSN to Arduino pin 10    8
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
   
 - V1.00 11/26/13
   Based on examples at http://www.bajdi.com/
   Questions: terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>


Servo myservo1;
Servo myservo2;
//Servo myservo;


/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   9
#define CSN_PIN 10


int Direction;
int LEFT=4;
int RIGHT=6; 
int STOP=0; 
int UP=2; 
int DOWN=8;
int UPLEFT=1;
int UPRIGHT=3;
int sensorxvalue;
int sensoryvalue;
// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[3];  // 2 element array holding Joystick readings

void setup()   /****** SETUP: RUNS ONCE ******/
{
   
  Serial.begin(9600);
  myservo1.attach(5);//left motor 
  myservo2.attach(6); //right motor
 
  
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
 // radio.setPALevel(RF24_PA_MIN);

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  if ( radio.available() )
  {
    Serial.println("Radio available");
     // Fetch the data payload
      radio.read( joystick, sizeof(joystick) );
      sensorxvalue = joystick[0];
      sensoryvalue = joystick[1];
      Serial.println(sensorxvalue);
      Serial.println(sensoryvalue);
            
    if((sensorxvalue>50) && (sensorxvalue<=90)) {
    if(sensoryvalue>100 && sensoryvalue<=150)
    Direction = STOP;
    else if(sensoryvalue<20 && sensoryvalue>=0)
    Direction = RIGHT;
    else if(sensoryvalue<=255 && sensoryvalue>230)
    Direction = LEFT;
  }
  else if(sensorxvalue>=0 && sensorxvalue<=40) {
    if(sensoryvalue>100 && sensoryvalue<=150)
    Direction = UP;
    else if(sensoryvalue>230 && sensoryvalue<=255)
    Direction = UPLEFT;
    else if(sensoryvalue<10 && sensoryvalue>=0)
    Direction = UPRIGHT;
  }
  else if(sensorxvalue>=230 && sensorxvalue<255 && sensoryvalue>=100 && sensoryvalue<150)
    Direction = DOWN;    
   
   //Serial.println(Direction);   

   switch(Direction)
{
case 0: Serial.println("STOP");
        myservo1.writeMicroseconds(1500);
        myservo2.writeMicroseconds(1500);
        break;
case 1: Serial.println("UPLEFT");
        myservo1.writeMicroseconds(1540);
        myservo2.writeMicroseconds(1290);
        break;         
case 2: Serial.println("UP");
        myservo1.writeMicroseconds(1700);
        myservo2.writeMicroseconds(1300);
        break;
case 3: Serial.println("UPRIGHT");
        myservo1.writeMicroseconds(1690);
        myservo2.writeMicroseconds(1470);
        break;         
case 4: Serial.println("LEFT");
        myservo1.writeMicroseconds(1490);
        myservo2.writeMicroseconds(1290);
        break;

case 6:Serial.println("RIGHT");
        myservo1.writeMicroseconds(1690);
        myservo2.writeMicroseconds(1495);
        break;

case 8:Serial.println("DOWN");
       myservo1.writeMicroseconds(1300);
       myservo2.writeMicroseconds(1700);
        break;
//Default: //Serial.print(sensorxvalue);
          //Serial.println(sensoryvalue);
          //break;
} 

    //delay(250);
    }
    else  
  
   {    
      Serial.println("No radio available");
       //myservo1.writeMicroseconds(1500);
       //myservo2.writeMicroseconds(1500);
       //delay(1000);
       //digitalWrite(LED, LOW);
  }

}
//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//NONE
//*********( THE END )***********
