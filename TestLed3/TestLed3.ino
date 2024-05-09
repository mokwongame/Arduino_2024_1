void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);  // 2번 포트를 출력으로 사용
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, LOW);  // 2번 포트 출력을 LOW(0V)로 설정
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);  // HIGH는 5V 출력
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(1000);
}
