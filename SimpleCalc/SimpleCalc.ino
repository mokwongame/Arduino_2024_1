#include <SoftwareSerial.h>  // <...> 의미: IDE include 폴더 검색
#include "StringTok.h"       // "..." 의미: 현재 폴더 검색

#define SERIAL_BPS (9600)

#define BLUE_SERIAL_BPS (115200)
#define BLUE_RXD (10)
#define BLUE_TXD (11)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  String sInput = "10 + 20";
  Serial.println("계산식: " + sInput);
  // StringTok 정의
  StringTok stInput(sInput);           // String sInput으로 StringTok stInput을 초기화(인스턴스 생성 후 값 할당)
  Serial.println(stInput.toString());  // StringTok stInput의 문자열을 얻어서(toString) 출력
  StringTok stToken;                   // stToken 인스턴스 생성
  stToken = stInput.getToken();        // getToken()으로 토큰을 추출해서 stToken에 할당
  Serial.println("1번 토큰 = [" + stToken.toString() + "]");
  stToken = stInput.getToken();
  Serial.println("2번 토큰 = [" + stToken.toString() + "]");
  stToken = stInput.getToken();
  Serial.println("3번 토큰 = [" + stToken.toString() + "]");
  stToken = stInput.getToken();  // 더 이상 추출할 토큰이 없으면 null string = "" 반환
  Serial.println("4번 토큰 = [" + stToken.toString() + "]");
  delay(1000);
}
