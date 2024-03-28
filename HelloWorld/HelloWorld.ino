void setup() {
  // put your setup code here, to run once:
  // Serial: 시리얼 통신 클래스의 인스턴스(정의된 변수)
  Serial.begin(9600); //. 의미: 클래스의 멤버 접근 방법; begin(): 시리얼 통신 시작 함수
  // 9600 의미: 시리얼 통신의 속도(bps: bit(baud) per second); Serial Monitor의 속도와 동일해야 함
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello, world!"); // println(): print line; 입력을 문자열로 출력(ASCII)한 후에 Enter(new line) 추가
  Serial.println("안녕, 세계야!");
  delay(1000); // delay(): 1000 밀리초 동안 지연(정지)
}
