#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
int babydetected = 8;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(8, INPUT);
  digitalWrite(8,HIGH);
}


void loop()
{
  if(digitalRead(babydetected) == LOW)
  //sending sms to first number//
  {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
   delay(1000);  // Delay of 1000 milli seconds or 1 second
   mySerial.println("AT+CMGS=\"+919845881560\"\r"); // Replace x with mobile number
   delay(1000);
   mySerial.println("PLS ATTEND NIE CRADLE");// The SMS text you want to send
   delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
   delay(60000);
   
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
   delay(1000);  // Delay of 1000 milli seconds or 1 second
   mySerial.println("AT+CMGS=\"+918105473206\"\r"); // Replace x with mobile number
   delay(1000);
   mySerial.println("PLS ATTEND NIE CRADLE");// The SMS text you want to send
   delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
   delay(60000);
  }
  
}


 

