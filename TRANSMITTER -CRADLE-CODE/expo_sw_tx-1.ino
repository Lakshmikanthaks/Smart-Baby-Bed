#include <VirtualWire.h>
int babydetected = 8;
void setup()
{
    Serial.begin(9600);	  // Debugging only
    Serial.println("setup");
    vw_setup(2000);	 // Bits per sec
    vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
    pinMode(8, INPUT);
    digitalWrite(8,HIGH);    
}//close setup

void loop()
{ 
  Serial.println("cradle on, waiting for 10minutes");
  //delay (600000);
  char *msg2;
  if(digitalRead(babydetected) == LOW)//if the baby is kept and limit switches are closed
  {  
   Serial.println("babydedtected");
     for (int count = 0; count < 10; count++) 
         {
           char *msg2 = "1";//send 1 to the receiver
           vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
           vw_wait_tx(); // Wait until the whole message is gone
           Serial.println("message transmitted waiting for 30seconds");
           delay (30000);
         }//end of for loop  
  }//end of if
  
}//close of void loop
  
