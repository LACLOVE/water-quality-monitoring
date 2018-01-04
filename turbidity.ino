#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
float num[10]={0,0,0,0,0,0,0,0,0,0}; 
void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
}
void loop() {
  for(int i=0;i<10;i++){
        int sensorValue = analogRead(A0);
        float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
        num[i]=voltage;
  }
  float voltage_avr=(num[1]+num[2]+num[3]+num[4]+num[5]+num[6]+num[7]+num[8]+num[9]+num[10])/10;
//  int sensorValue = analogRead(A0);
//  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage_avr); 
  lcd.clear();//LCD清屏
  // 定位光标在LCD第0行、第0列
  lcd.setCursor(0, 0);
  lcd.print("voltage:");
  lcd.print(voltage_avr);
  delay(500);
}
