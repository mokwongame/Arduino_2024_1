#include <SoftwareSerial.h> // SW로 Serial을 하나 더 생성

#define SERIAL_BPS (9600)
#define PIN_LED (13)
#define LED_ON_TIME (200)   // in msec
#define LED_OFF_TIME (300)  // in msec

#define BLUE_SERIAL_BPS (115200)
#define BLUE_RXD  (10)
#define BLUE_TXD  (11)

// 변수처럼 인스턴스(클래스를 실행시킨 결과물) 생성: 클래스는 SoftwareSerial 
SoftwareSerial blueSerial(BLUE_RXD, BLUE_TXD); // Rx, Tx 순으로 입력

int userInput() {
  while (!Serial.available())
    ;
  char ch = Serial.read();
  int i = String(ch).toInt();
  return i;
}

int blueInput() {
  while (!blueSerial.available())
    ;
  char ch = blueSerial.read();
  int i = String(ch).toInt();
  return i;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  blueSerial.begin(BLUE_SERIAL_BPS);
  Serial.println("블루투스 깜박이기 시작");
  blueSerial.println("Input the count of blinks.");
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = blueInput();
  Serial.println("깜박임 회수 = " + String(count));
}
