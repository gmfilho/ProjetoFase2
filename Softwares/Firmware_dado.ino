#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);

int redled = 3;
int greenled = 2;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 30;
// C++ code
//
void setup()
{
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  
}

void loop()
{
  int analogValue = analogRead(A0);
  int b = map(analogValue,0,1023,0,255);
  Serial.println(b);
  if(b>sensorThresh)
  {
    	digitalWrite(redled, HIGH);
    	digitalWrite(greenled, LOW);
    	tone(buzzer, 1000, 10000);
    	lcd.clear();
    	lcd.setCursor(0,1);
    	lcd.print("ALERTA");
    	delay(700);
    	lcd.setCursor(0,1);
    	lcd.print("NIVEL ALTO");
    	delay(700);
  	}
  	else 
  	{
    	digitalWrite(greenled, HIGH); 
    	digitalWrite(redled, LOW);
    	noTone(buzzer);
    	lcd.clear();
    	lcd.setCursor(0,0);
    	lcd.print("SEGURO");
    	delay(700);
    	lcd.clear();
    	lcd.setCursor(0,1);
    	lcd.print("NIVEL CORRETO");
    	delay(700);
  	}
}
