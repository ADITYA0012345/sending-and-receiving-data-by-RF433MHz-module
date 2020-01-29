#include <RH_ASK.h> 
#include <SPI.h> 
RH_ASK rf_driver;

void setup()
{
    rf_driver.init();
    Serial.begin(9600);
}

void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[7];
    uint8_t buflen = 7;
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char *)buf);        
    }
}

