#define SERIAL_BPS (9600)
#define SEED_PORT (A0)

// 가위바위보 열거 상수 정의
enum HandType {
  HT_SCISSORS,
  HT_ROCK,
  HT_PAPER,  // 숫자가 0, 1, 2로 자동 배정
  HT_NONE
};

// 사용자 입력을 char로 반환
char
userInputChar() {
  while (!Serial.available())
    ;
  char ch = Serial.read();
  return ch;
}

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

void startGame() {
  Serial.println("시작하려면 아무 키나 입력하세요.");
  userInputChar();  // 반환값 무시
}

HandType getUserHand() {
  Serial.print("가위(S)바위(R)보(P) 선택: ");
  char ch = userInputChar();
  String str(ch); str.toUpperCase(); // 대문자 변환
  ch = str[0];
  Serial.println(ch);
  HandType nHand;
  switch (ch) {
    case 'S': nHand = HT_SCISSORS; break;
    case 'R': nHand = HT_ROCK; break;
    case 'P': nHand = HT_PAPER; break;
    default: nHand = HT_NONE; // 잘못 입력한 경우
  }
  return nHand;
}

void setup() {
  // put your setup code here, to run once:
  initGame();
  logo();
}

void loop() {
  // put your main code here, to run repeatedly:
  startGame();
  HandType nUserHand = getUserHand();
  Serial.println(nUserHand);
  //delay(1000);
}
