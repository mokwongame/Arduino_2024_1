void setup() {
  // put your setup code here, to run once:
  // 디지털 포트의 입력 혹은 출력 선택
  pinMode(13, OUTPUT); // 13번 디지털 포트를 출력으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); // 13번 디지털 포트에 HIGH 전압(5V) 출력
  delay(500);
  digitalWrite(13, LOW); // 13번 디지털 포트에 LOW 전압(0V, GND) 출력
  delay(500);
}
