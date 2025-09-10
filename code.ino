#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,  16, 2);
int sensorPin=A1;
int phPin=A0;
//int sdaPin=A4;
//int sclPin=A5;
int sensorData;
float ph;
float Value=0;
void setup()
{  
   Serial.begin(9600);   
   lcd.init();
   lcd.begin(16,2);
   lcd.backlight();
   pinMode(sensorPin,INPUT); 
   pinMode(phPin,INPUT);
   delay(1000);                        
 }
void loop()
{
    sensorData = analogRead(sensorPin);   
    Value= analogRead(phPin);
    Serial.print(" gas lvl | pH ");
    
    ph=(Value*0.01028);
    Serial.println(ph+4.5); 
    Serial.print(" | ");
    Serial.print(sensorData);
    lcd.clear();  
    lcd.setCursor(0,0); //Defining positon to write from first row,first column .
    lcd.print(" pH : "); //You can write 16 Characters per line .
    lcd.print(ph+4.5);
    delay(1000);//Delay used to give a dynamic effect
    lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
    lcd.print("H2 : ");
    lcd.print(sensorData);
    lcd.print(" ppm");
    delay(2000); 
    lcd.clear();//Clean the screen
    lcd.setCursor(0,0); 
    lcd.print(" BIOELECTRICAL");
    lcd.setCursor(0,1);
    lcd.print("   INNOVATORS ");
//    delay(8000); 
    delay(2000);                                
}
