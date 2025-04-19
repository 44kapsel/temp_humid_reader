#include <RtcDS1302.h>
#include <ThreeWire.h>
#include <dht11.h>

// DHT11 setup
#define DHT11PIN 4
dht11 DHT11;

// DS1302 RTC setup
ThreeWire myWire(6, 7, 5); // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  Serial.begin(9600);
  delay(1000); // Time for Serial Monitor to initialize

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  Rtc.SetDateTime(compiled);

  Rtc.Begin();
}

void loop() {
  // Reading temperature and humidity from DHT11 sensor
  int chk = DHT11.read(DHT11PIN);
  
  float temperature = DHT11.temperature;
  float humidity = DHT11.humidity;

  // Getting current time from DS1302 module
  RtcDateTime now = Rtc.GetDateTime();

  // Displaying the results in Serial Monitor
  Serial.print("Date: ");
  Serial.print(now.Day());
  Serial.print('/');
  Serial.print(now.Month());
  Serial.print('/');
  Serial.print(now.Year());

  Serial.print(" Time: ");
  Serial.print(now.Hour());
  Serial.print(':');
  Serial.print(now.Minute());
  Serial.print(':');
  Serial.print(now.Second());

  Serial.print(" | Temperature: ");
  Serial.print(temperature);
  Serial.print("°C");

  Serial.print(" | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(10000); // 10-second interval between readings
}
