#include <SoftwareSerial.h>  // <...> 의미: IDE include 폴더 검색
#include "StringTok.h"       // "..." 의미: 현재 폴더 검색

#define SERIAL_BPS (9600)

#define BLUE_SERIAL_BPS (115200)
#define BLUE_RXD (10)
#define BLUE_TXD (11)

SoftwareSerial blueSerial(BLUE_RXD, BLUE_TXD);

// 입력이 double인 나머지 함수
double remainder(double x, double y) {
  return (int)x % (int)y;
}

// 연산자 op에 따라 계산해서 double을 반환: x op y
double calcOp(char op, double x, double y) {
  double ans = 0.;
  switch (op) {
    case '+': ans = x + y; break;
    case '*': ans = x * y; break;
    case '%': ans = remainder(x, y); break;
  }
  return ans;
}

// 문자열 입력 받아 double을 반환
// String&: String 자료형의 레퍼런스(&); 레퍼런스는 그 변수(인스턴스)에 접근할 수 있는 권한
double calc(const String& sInput) {  // sInput은 변수이지만 원본을 바꿀 수 있는 권한(reference) 있음; const 붙인 효과: 접근해서 읽을 수 있지만 쓰기는 불가능(const는 상수 의미)
  StringTok stInput(sInput);
  StringTok stToken;              // stToken 인스턴스 생성
  stToken = stInput.getToken();   // 숫자를 뜻하는 문자열
  double x = stToken.toDouble();  // StringTok을 double로 type casting
  stToken = stInput.getToken();   // 연산자
  char op = stToken[0];           // String -> char
  stToken = stInput.getToken();   // 숫자를 뜻하는 문자열
  double y = stToken.toDouble();
  //Serial.println("추출한 토큰: " + String(x) + op + String(y)); // 디버깅 코드
  double ans = calcOp(op, x, y);
  return ans;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  blueSerial.begin(BLUE_SERIAL_BPS);
}

// Bluetooth(SoftwareSerial)용 단순 계산기
void loop() {
  // 파이썬 input() 함수 활용
  String sInput = input(blueSerial, "계산식 입력: ");
  Serial.println(sInput);
  double ans = calc(sInput);
  Serial.println("답 = " + String(ans));  // double인 ans를 String으로 type casting해서 출력
  blueSerial.println("답 = " + String(ans)); // SoftwareSerial에 출력
}

// Serial용 단순 계산기
/*void loop() {
  // 파이썬 input() 함수 활용
  String sInput = input("계산식 입력: ");
  Serial.println(sInput);
  double ans = calc(sInput);
  Serial.println("답 = " + String(ans));  // double인 ans를 String으로 type casting해서 출력
}*/

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
