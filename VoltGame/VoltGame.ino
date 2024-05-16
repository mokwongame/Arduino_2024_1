#define SERIAL_BPS (9600)
#define SEED_PORT (A1)

void initGame() {
  Serial.begin(SERIAL_BPS);
  // 난수 초기화
  int adc = analogRead(SEED_PORT);
  adc *= adc;
  randomSeed(adc);
}

void printVolt(int nVolt) {
  double volt = nVolt * 5. / 1023.;
  Serial.println(String(nVolt) + " => " + String(volt) + "V");
}

// 게임 시작: 난수 발생해서 맞출 전압을 출력
int startGame() {
  int nRand = random(30, 900);
  Serial.println("아래 전압을 맞추세요!");
  printVolt(nRand);
  return nRand;
}

void setup() {
  // put your setup code here, to run once:
  initGame();
}

void loop() {
  // put your main code here, to run repeatedly:
  int nRand = startGame();
  delay(1000);
}
