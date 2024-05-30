#define SERIAL_BPS (9600)
#define LED_RPORT (2)
#define LED_GPORT (3)
#define LED_BPORT (4)

#define BLUE_UP_PORT (6)
#define BLUE_DOWN_PORT (7)

// 예전 입력 저장할 전역 변수
int nBlueUpPrev;
int nBlueDownPrev;

// 에지 상태
enum EdgeType {
  ET_NONE,
  ET_RISE,
  ET_FALL
};

void initButton() {
  pinMode(BLUE_UP_PORT, INPUT_PULLUP);
  pinMode(BLUE_DOWN_PORT, INPUT_PULLUP);
  nBlueUpPrev = digitalRead(BLUE_UP_PORT);
  nBlueDownPrev = digitalRead(BLUE_DOWN_PORT);
}

// nInputPrev: 전역 변수중 하나
// int&: int 자료형의 원래 위치를 접근하는 reference
EdgeType getEdgeType(int nPort, int& nInputPrev) {
  EdgeType nType;
  int nInput = digitalRead(nPort);
  if (nInput != nInputPrev) {  // 에지가 있음
    if (nInput == HIGH)        // LOW -> HIGH: rise
      nType = ET_RISE;
    else nType = ET_FALL;  // HIGH -> LOW: fall
    nInputPrev = nInput;   // 현재 상태를 다시 저장
  } else nType = ET_NONE;
  return nType;
}

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  initLed();
  initButton();  // 버튼 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  // Blue up 상태 확인
  int nBlueUpEdge = getEdgeType(BLUE_UP_PORT, nBlueUpPrev);
  if (nBlueUpEdge == ET_FALL) {  // 버튼이 눌러짐
    turnBlue(true);              // LED on: 깃발 내린 상태
    Serial.println("blue up");
  }
  // Blue down 상태 확인
    int nBlueDownEdge = getEdgeType(BLUE_DOWN_PORT, nBlueDownPrev);
    if (nBlueDownEdge == ET_FALL) {  // 버튼이 눌러짐
    turnBlue(false);              // LED on: 깃발 내린 상태
    Serial.println("blue down");
  }
}
