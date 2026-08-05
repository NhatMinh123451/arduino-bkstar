#include <DHT.h>
const int DHTPIN = A3; // Đọc dữ liệu từ DHT22 ở chân A3 trên mạch Arduino
const int DHTTYPE = DHT22; // Khai báo loại cảm biến (DHT22)

DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
zzzzzzzzaaazzzz
  delay(2000); // Đọc lại cảm biến sau mỗi 2 giây
  }

