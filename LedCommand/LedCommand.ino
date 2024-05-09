#include "StringTok.h"

#define SERIAL_BPS (9600)
#define LED_RPORT (2)
#define LED_GPORT (3)
#define LED_BPORT (4)

void initLed() {
  pinMode(LED_RPORT, OUTPUT);  // 2번 포트를 출력으로 사용
  pinMode(LED_GPORT, OUTPUT);
  pinMode(LED_BPORT, OUTPUT);
  digitalWrite(LED_RPORT, LOW);  // 2번 포트 출력을 LOW(0V)로 설정
  digitalWrite(LED_GPORT, LOW);
  digitalWrite(LED_BPORT, LOW);
}

void turnLed(int nPort, bool bOn) {
  if (bOn) digitalWrite(nPort, HIGH);
  else digitalWrite(nPort, LOW);
}

void turnRed(bool bOn) {
  turnLed(LED_RPORT, bOn);
}

void turnGreen(bool bOn) {
  turnLed(LED_GPORT, bOn);
}

void turnBlue(bool bOn) {
  turnLed(LED_BPORT, bOn);
}

void turnRgb(bool bRed, bool bGreen, bool bBlue) {
  turnRed(bRed);
  turnGreen(bGreen);
  turnBlue(bBlue);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  initLed();
}

void ledCmd(const String& sInput) {
  // 토큰 추출
  StringTok stInput(sInput);
  String token;
  token = stInput.getToken().toString(); // 명령어
  if (token == "led3")
  {
      token = stInput.getToken().toString(); // 색깔: color
      Serial.println("입력한 색깔: " + token);
  }
  else Serial.println("잘못된 명령어!");
}

void loop() {
  // put your main code here, to run repeatedly:
  String sInput = input("명령어: ");
  Serial.println(sInput);
  ledCmd(sInput);
}
