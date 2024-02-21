#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// DHT11传感器的引脚和类型
#define DHTPIN A1  // 将2更改为DHT11传感器连接的实际GPIO引脚
#define DHTTYPE DHT11  // 使用的DHT传感器类型

DHT dht(DHTPIN, DHTTYPE);

// 土壤湿度传感器的引脚
#define SOIL_MOISTURE_PIN A2  // 将34更改为土壤湿度传感器连接的实际模拟引脚

void setup() {
  Serial.begin(9600); // 开始串口通信
  dht.begin(); // 初始化DHT11传感器
  pinMode(SOIL_MOISTURE_PIN, INPUT); // 设置土壤湿度传感器引脚为输入模式
}

void loop() {
  // 从DHT11读取温度和湿度
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // 从土壤湿度传感器读取湿度值
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // 打印读取到的数据到串口
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  delay(2000); // 每2秒读取一次数据
}
