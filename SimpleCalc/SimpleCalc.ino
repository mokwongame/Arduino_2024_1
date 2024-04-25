#include <SoftwareSerial.h>  // <...> 의미: IDE include 폴더 검색
#include "StringTok.h"       // "..." 의미: 현재 폴더 검색

#define SERIAL_BPS (9600)

#define BLUE_SERIAL_BPS (115200)
#define BLUE_RXD (10)
#define BLUE_TXD (11)

// 문자열 입력 받아 double을 반환
double calc(String& sInput) {
  return 0.;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
}

void loop() {
// 파이썬 input() 함수 활용
  String sInput = input("계산식 입력: ");
  Serial.println(sInput);
  double ans = calc(sInput);
  Serial.println("답 = " + String(ans)); // double인 ans를 String으로 type casting해서 출력
}

// 토큰 추출 연습
/*void loop() {
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
}*/
