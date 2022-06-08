#include <LiquidCrystal.h> //Pantalla cristal incluída
LiquidCrystal lcd (2,3,4,5,6,7); //Pines de conexión

const int SENSOR = 0;
int sensorValue = (A0);

void setup() {
  lcd.begin(16,2);
  Serial.begin(2500);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
    
}

void loop() {
  sensorValue = analogRead(SENSOR);
  lcd.setCursor(0,0);
  lcd.print("Intensidad luz:");
  lcd.setCursor(0,1);
  lcd.print(sensorValue);
  lcd.print(" Lx ");
  Serial.print(sensorValue);
  if (sensorValue>700)
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
  else
   if (sensorValue<150)
     {
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
    }
  else
  {
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
  }
}
