#include <LiquidCrystal.h>
int Contrast = 60;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



int sensorPin = A0; // choose the input pin (for GAS sensor)  



int read_value; // variable for reading the gaspin status
int set = 50;  // we start, assuming Smoke detected

void setup(){ 
    analogWrite(6, 20);
  lcd.begin(16, 2);
pinMode(sensorPin, INPUT); // declare sensor as input


lcd.begin(16, 2);
lcd.print("WELCOME To");
delay(2000)
;lcd.clear();
lcd.print("  GAS Detector  ");
delay(2000);
lcd.clear();
}

void loop(){
read_value = (analogRead(sensorPin)); // read input value

read_value = read_value - 50;
if(read_value<0){read_value=0;}

lcd.setCursor(0, 0);
lcd.print("GAS Level: ");
lcd.print(read_value);
lcd.print("  ");

if(read_value>set){ // check if the Smoke variable is High
lcd.setCursor(0, 1);
lcd.print("Alert....!!!    ");    


delay(1000);
}

if(read_value<set){ // check if the Smoke variable is Low
lcd.setCursor(0, 1);
lcd.print(".....Normal.....");   


}
delay(100);
}
