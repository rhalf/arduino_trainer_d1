#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial gsm(RX, TX);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.print("AT\r\n");
  delay(100);
  gsm.print("AT+CSQ\r\n");
  delay(100);
  gsm.print("ATD+639705786311;\r\n");
  delay(15000);
  gsm.print("ATH\r\n");
}
void loop() {
  // put your main code here, to run repeatedly:
  if (gsm.available())
    Serial.write(gsm.read());
  if (Serial.available())
    gsm.write(Serial.read());

}
