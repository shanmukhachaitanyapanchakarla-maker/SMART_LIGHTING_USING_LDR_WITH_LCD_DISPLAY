//SMART LIGHTING USING LDR WITH LCD 


#include <Adafruit_LiquidCrystal.h>

const int ldr_pin = A0; // LDR sensor connected to Analog pin A0
const int ledPin = 4;   // LED or Relay connected to Digital pin 13
int threshold = 500;    // Light threshold (adjust based on your environment)

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ldr_pin, INPUT);
  
  Serial.begin(9600);  // Start serial monitor to read LDR values
 
  lcd_1.begin(16, 2);  // Initiating i2c lcd screen
  lcd_1.setBacklight(1);
  lcd_1.print("smart lighting");
  
}

void loop()
{
  int ldrValue = analogRead(ldr_pin); // Read the ADC value from ldr (0 to 1023)
  Serial.println(ldrValue); // Print value to Serial Monitor
  
  // if-else block
  // If it is dark (sensor value drops below threshold)
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH); // Turn the light ON
    Serial.println("light on!"); 
    lcd_1.setCursor(0, 1);
    lcd_1.print("LIGHT  ON");    // print on lcd
  } 
  // If it is bright  
  else {
    digitalWrite(ledPin, LOW);  // Turn the light OFF
    lcd_1.setCursor(0, 1);
    lcd_1.print("LIGHT OFF");   // print on lcd
  }
  
  delay(500);
}

  


 
