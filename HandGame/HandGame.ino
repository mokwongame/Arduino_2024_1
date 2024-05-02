#define SERIAL_BPS (9600)
#define SEED_PORT (A0)

// 초기 화면
void logo() {
  Serial.println("===");
  Serial.println("가위바위보 게임 by Cho");
  Serial.println("===");
}

// 게임 초기화
void initGame() {
  Serial.begin(SERIAL_BPS);
  // 난수 초기화
  int adc = analogRead(SEED_PORT);
  adc *= adc;
  randomSeed(adc);
}

void setup() {
  // put your setup code here, to run once:
  initGame();
  logo();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
