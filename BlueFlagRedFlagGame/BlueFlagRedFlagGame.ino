#define SERIAL_BPS (9600)
#define LED_RPORT (2)
#define LED_GPORT (3)
#define LED_BPORT (4)

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
}

void loop() {
  // put your main code here, to run repeatedly:
  turnBlue(true);
  delay(1000);
  turnBlue(false);
  delay(1000);
}
