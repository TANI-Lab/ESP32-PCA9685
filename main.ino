#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int servoChannel = 0; // サーボを接続したPCA9685のチャンネル
const int servoMin = 108;   // 500us相当
const int servoMax = 487;   // 2500us相当

// サーボを角度指定で動かす
void moveServo(int angle) {
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, servoMin, servoMax);
  pwm.setPWM(servoChannel, 0, pulse);
}

// イーズイン・イーズアウト付き移動
void smoothServoMove(int startAngle, int endAngle, int durationMs) {
  const int steps = 90; // 分解能（増やすほど滑らか）
  float stepTime = (float)durationMs / steps;

  for (int i = 0; i <= steps; i++) {
    float t = (float)i / steps;
    // sinカーブで滑らかに（0→1→0 のスピード変化）
    float eased = 0.5 - 0.5 * cos(t * PI);
    int angle = startAngle + (endAngle - startAngle) * eased;
    moveServo(angle);
    delay(stepTime);
  }
}

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50); // 50Hzサーボ駆動
  delay(10);
}

void loop() {
  smoothServoMove(0, 180, 1000);   // 1秒かけて0→180度（加速→等速→減速）
  delay(500);
  smoothServoMove(180, 0, 1000);   // 1秒かけて180→0度
  delay(500);
}
