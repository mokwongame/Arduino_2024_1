#define BUTTON_PORT (7)

int nInputPrev;  // 예전 입력

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(6, INPUT); // 위험해서 잘 사용하지 않음: 접지(GND)는 문제 없으나 5V는 위험함
  pinMode(BUTTON_PORT, INPUT_PULLUP);
  nInputPrev = digitalRead(BUTTON_PORT);  // 현재 상태 저장
}

void loop() {
  // put your main code here, to run repeatedly:
  int nInput = digitalRead(BUTTON_PORT);  // 평상시는 5V(HIGH); 버튼 누르면 0V(LOW); 푸시버튼에 접지를 연결한 상태
  // 스위치의 누른 상태를 확인(전압으로 확인)
  // String sInput = (nInput == HIGH) ? "open" : "closed";
  // // 버튼을 누르면 회로가 닫힘(closed); 떼면 회로가 열림(open)
  // Serial.println(sInput);
  // delay(1000);

  // 에지 검출: 빠른 응답 가능(마우스 클릭에도 사용)
  if (nInput != nInputPrev) {  // 에지가 있음
    bool bRise;
    if (nInput == HIGH)  // LOW -> HIGH: rise
      bRise = true;
    else bRise = false; // HIGH -> LOW: fall
    String sInput = (bRise) ? "upward" : "downward";
    Serial.println(sInput);
    nInputPrev = nInput; // 현재 상태를 다시 저장
  }
}
