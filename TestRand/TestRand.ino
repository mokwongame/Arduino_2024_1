// 난수 발생기
// 1. 초기값 설정: 시드(seed)
// 2. 난수 발생: random

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // 난수 초기화: 고정된 숫자가 입력
  //randomSeed(1004);
  // 난수 초기화: 알 수 없는 숫자로 입력
  int adc = analogRead(A0);
  adc *= adc;
  randomSeed(adc);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nRand = random(2, 10);  // 범위: 최소값(보통 0), 최대값(보통 난수 발생 개수) -> 최소값~최대값-1 -> 예) (0, 10) -> 0, 1, 2, ..., 9(=10-1)
  Serial.println(nRand);
  //int adc = analogRead(A0); // 아날로그 포트를 읽는 함수; 포트 이름은 A로 시작
  //adc *= adc;
  //Serial.println(adc);
  delay(1000);
}