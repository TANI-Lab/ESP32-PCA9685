# 🎮 MiuZei MS18 Servo Control with ESP32 & PCA9685

このプロジェクトでは、MiuZei社製のサーボモーター **MS18** を  
**ESP32** ＋ **PCA9685（16ch PWMモジュール）** を使って制御します。

加速・減速付きで0°→180°→0°の滑らかな動きを確認できるスケッチを提供しています。

---

## 🔧 構成

| 部品         | 型番・仕様                          |
|--------------|------------------------------------|
| サーボ       | MiuZei MS18 サーボモーター         |
| マイコン     | ESP32（Arduino IDE 対応）         |
| PWMモジュール | PCA9685（I2C接続 16ch PWM）       |
| 電源         | ESP32の5V出力（サーボ1個用）      |

---

## 📌 接続

| ESP32 GPIO | 接続先（PCA9685） |
|------------|-------------------|
| GPIO21     | SDA               |
| GPIO22     | SCL               |
| 5V         | VCC               |
| GND        | GND               |

- サーボモーターはPCA9685の **CH0** に接続  
- サーボのVCC/GNDもESP32の5V/GNDから供給（1個のみ使用時）

---

## 💻 使用ライブラリ

- [Adafruit PWM Servo Driver Library](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library)

Arduino IDEで以下のライブラリをインストールしてください：

