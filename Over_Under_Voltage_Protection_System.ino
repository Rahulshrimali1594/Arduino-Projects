//connect AC Voltage pin to Analog pin 0 of arduino uno//
//reley pin to Digital pin 7 //

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Pins for the LCD

const int voltageSensorPin = A0;  // Pin for the AC voltage sensor
const int relayPin = 7;           // Pin for the relay

const float overVoltageThreshold = 250.0;   // Define your over-voltage threshold (in volts)
const float underVoltageThreshold = 180.0;  // Define your under-voltage threshold (in volts)

void setup() 
{
  lcd.begin(16, 2);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float voltage = getVoltage();
  
  if (voltage > overVoltageThreshold || voltage < underVoltageThreshold) 
  {
    lcd.setCursor(0, 0);
    lcd.print("Voltage Alert!");
    lcd.setCursor(0, 1);
    lcd.print("Voltage: ");
    lcd.print(voltage);
    lcd.print("V");

    // Activate relay to disconnect power
    digitalWrite(relayPin, HIGH);
  }
   else 
   {
    lcd.clear();
    // Deactivate relay if voltage is within safe range
    digitalWrite(relayPin, LOW);
  }
  delay(1000);
}

float getVoltage() 
{
  int sensorValue = analogRead(voltageSensorPin);
  float voltage = sensorValue * (5.0 / 1023.0) * (250.0 / 5.0); // Convert analog reading to voltage
  return voltage;
}
