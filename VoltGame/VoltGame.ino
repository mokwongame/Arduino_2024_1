#define SERIAL_BPS (9600)
#define SEED_PORT (A1)
#define VOLT_PORT (A0)
#define ADC_MARGIN (10)

#define SHOW_VOLT_TIME (400)  // in msec
#define WAIT_TIME (1500)

unsigned long startTime;

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
  delay(WAIT_TIME);
  startTime = millis();  // 현재 시간 저장
  return nRand;
}

void setup() {
  // put your setup code here, to run once:
  initGame();
}

void loop() {
  // put your main code here, to run repeatedly:
  int nRand = startGame();
  bool bResult = false;
  while (!bResult) {  // bResult가 false인 동안(while) 반복
    // 전압 측정
    int nVolt = analogRead(VOLT_PORT);
    printVolt(nVolt);
    if (nVolt >= nRand - ADC_MARGIN && nVolt <= nRand + ADC_MARGIN) bResult = true;  // 성공
    if (bResult) break;                                                              // bResult가 true이면(if) 반복 깨기(break)
    delay(SHOW_VOLT_TIME);
  }
  unsigned long stopTime = millis();
  Serial.println("성공!!\n");
  double voltTime = (stopTime - startTime) * 1e-3;
  Serial.println("걸린 시간 = " + String(voltTime) + "초\n\n");
  delay(WAIT_TIME);
}
