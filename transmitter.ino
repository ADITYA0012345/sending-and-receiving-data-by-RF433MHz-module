#include <stdio.h>
#include <RH_ASK.h> 
#include <SPI.h> 
int dht, pulse;
RH_ASK rf_driver;

void setup()
{
   Serial.begin(9600);
   rf_driver.init();   
}

void loop()
{
    char msg[10];
    dht = analogRead(A0);
    sprintf(msg, "%d-dht", dht);
    rf_driver.send((uint8_t*)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(10);
    pulse = analogRead(A1);
    Serial.println(pulse);
    sprintf(msg, "%d-pul", pulse);
    rf_driver.send((uint8_t*)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
}

