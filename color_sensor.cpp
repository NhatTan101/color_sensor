#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Khởi tạo đối tượng TCS34725
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  // Bắt đầu giao tiếp với cảm biến
  if (tcs.begin()) {
    Serial.println("TCS34725 found!");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // Nếu không tìm thấy cảm biến, dừng lại ở đây
  }
}

void loop() {
  uint16_t r, g, b, c;
  float red, green, blue;

  // Đọc giá trị màu sắc từ cảm biến
  tcs.getRawData(&r, &g, &b, &c);

  // Chuyển đổi giá trị raw thành giá trị màu thực tế
  red = r / (float)c * 255.0;
  green = g / (float)c * 255.0;
  blue = b / (float)c * 255.0;

  // Hiển thị giá trị màu sắc
  Serial.print("Red: "); Serial.print(red); Serial.print(" ");
  Serial.print("Green: "); Serial.print(green); Serial.print(" ");
  Serial.print("Blue: "); Serial.print(blue); Serial.print(" ");
  Serial.print("Clear: "); Serial.print(c); Serial.println(" ");

  // Đợi 1 giây trước khi đọc lại
  delay(1000);
}