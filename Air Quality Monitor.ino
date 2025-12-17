#include <LiquidCrystal_I2C.h>
#include <dht.h>        // Include library
#define outPin 4        // Defines pin number to which the sensor is connected
int sensor = A1&&A0;
char degree=223;
dht DHT;                // Creates a DHT object

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
	Serial.begin(9600);
  pinMode(sensor, INPUT);
  lcd.backlight();// turn on lcd backlight
  lcd.init();
  lcd.init();
}

void loop() {
  int aqi = analogRead(sensor);
	int readData = DHT.read11(outPin);

	int t = DHT.temperature;        // Read temperature
	int h = DHT.humidity;           // Read humidity
  lcd.clear();
  if(aqi < 500){
  lcd.setCursor(0,0);
  lcd.print("AQI:");
  lcd.print(aqi, DEC);
  lcd.print("PPM");
  lcd.setCursor(0,1);
	lcd.print("Tem=");
	lcd.print(t);
	lcd.print(degree);
  lcd.print("C");
  lcd.setCursor(9,1);
	lcd.print("Hum=");
	lcd.print(h);
	lcd.print("%");
  lcd.setCursor(11,0);
  lcd.print("GOOD");
} else if(aqi > 500 && aqi <= 1000){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AQI:");
  lcd.print(aqi, DEC);
  lcd.print("PPM");
  lcd.setCursor(0,1);
	lcd.print("Tem=");
	lcd.print(t);
	lcd.print(degree);
  lcd.print("C");
  lcd.setCursor(9,1);
	lcd.print("Hum=");
	lcd.print(h);
	lcd.print("%");
  lcd.setCursor(11,0);
  lcd.print("POOR");
} else if(aqi > 1000){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AQI:");
  lcd.print(aqi, DEC);
  lcd.print("PPM");
  lcd.setCursor(0,1);
	lcd.print("Tem=");
	lcd.print(t);
	lcd.print(degree);
  lcd.print("C");
  lcd.setCursor(9,1);
	lcd.print("Hum=");
	lcd.print(h);
	lcd.print("%");
  lcd.setCursor(11,0);
  lcd.print("TOXIC");
}
delay(2000); // wait two seconds
}