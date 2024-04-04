void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial.begin(19200);  // 이번에는 19200 bps를 선택
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial에서 입력이 있다면 { 코드 블록 } 실행
  if (Serial.available()) {   // Serial 버퍼가 사용 가능한지? 외부에서 입력이 있어서 버퍼를 채웠는가?; 버퍼가 채워졌으면 true를 출력, 아니면 false
    char ch = Serial.read();  // Serial에서 버퍼에 채워진 입력을 한 바이트 읽기
    Serial.println(ch);
  }
}
