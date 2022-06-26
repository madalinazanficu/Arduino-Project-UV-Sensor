#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

#define UV_SENSOR A0
#define BUZZER 3

// Creez obiectul ecran de 16 caractere pe 2 linii la adresa 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Declar variabilele utilizate
float uv_init = 0;
float uv_transf =0;

void setup()
{
  // Initializare buzzer
  pinMode(BUZZER, OUTPUT);
  
  // Pornire LCD
  lcd.init();

  tone(BUZZER, 1000, 1500);

  // Afisare informatii ecran.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Cel mai tare");
  lcd.setCursor(3,1);
  lcd.print("proiect AD");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Madalina");
  lcd.setCursor(9, 1);
  lcd.print("Zanficu");
  delay(3500);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Senzor");
  lcd.setCursor(7, 1);
  lcd.print("UV");
  delay(3000);
}

void loop()
{
  // Citesc valoarea UV
  uv_init = analogRead(UV_SENSOR);
  uv_transf = uv_init / 100;

  // Scriu pe ecran
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel UV: ");
  lcd.setCursor(10, 0);
  lcd.print(uv_transf);

  if (uv_transf <= 2) {
    noTone(BUZZER);
    lcd.setCursor(6, 1);
    lcd.print("MIC");
  }

  if (uv_transf >= 3 && uv_transf <= 5) {
    noTone(BUZZER);
    lcd.setCursor(6, 1);
    lcd.print("MEDIU");
  }

  if (uv_transf >= 6 && uv_transf <= 7) {
    noTone(BUZZER);
    lcd.setCursor(6, 1);
    lcd.print("MARE");
  }
  if (uv_transf >= 8 && uv_transf <= 10) {
    noTone(BUZZER);
    lcd.setCursor(2, 1);
    lcd.print("FOARTE MARE");
  }

  if (uv_transf >= 11) {
    tone(BUZZER, 2000);
    lcd.setCursor(6, 1);
    lcd.print("EXTREM");
  }

  delay(1000);
}
