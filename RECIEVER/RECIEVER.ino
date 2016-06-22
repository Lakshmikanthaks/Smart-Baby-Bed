
#include <VirtualWire.h>

int babydetected = 13;
 
void setup()
{
    //Serial.begin(9600);	// Debugging only
    //Serial.println("setup");

    // Initialise the IO and ISR
    vw_setup(2000);	 // Bits per sec
    vw_set_rx_pin(2);    //Rx Data pin to Digital  Pin 2
    vw_rx_start();       // Start the receiver PLL running
    pinMode(babydetected, OUTPUT);
}

  void loop()
  {

    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

          if (vw_get_message(buf, &buflen)) // Non-blocking
            {
	               int i;
                       //digitalWrite(13, true); // Flash a light to show received good message
	               // Message with a good checksum received, dump it.
	               for (i = 0; i < buflen; i++)
	                   {
	                     Serial.print(buf[i]);//print received command
                             if(buf[i] == '1')//if button 1 is pressed.... i.e.forward buton
                                                        {
                                                          digitalWrite(babydetected,HIGH);
                                                        }
	                  }
  //digitalWrite(13, false);

           }//close if
   }//close loop

