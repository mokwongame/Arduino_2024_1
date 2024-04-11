#define SERIAL_BPS (9600)
#define PIN_LED (13)
#define LED_ON_TIME (200)   // in msec
#define LED_OFF_TIME (300)  // in msec

// int userInput() {
//   if (Serial.available()) {
//     char ch = Serial.read();
//     int i = String(ch).toInt();
//     return i;
//   }
//   return -1;
// }

int userInput() {
  while (!Serial.available())
    ;
  char ch = Serial.read();
  int i = String(ch).toInt();
  return i;
}

void blinkLed() {
  digitalWrite(PIN_LED, HIGH);  // 13번 디지털 포트에 HIGH 전압(5V) 출력
  delay(LED_ON_TIME);
  digitalWrite(PIN_LED, LOW);  // 13번 디지털 포트에 LOW 전압(0V, GND) 출력
  delay(LED_OFF_TIME);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  pinMode(PIN_LED, OUTPUT);    // 13번 디지털 포트를 출력으로 설정
  digitalWrite(PIN_LED, LOW);  // LED off로 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = userInput();
  Serial.println(count);
  for (int i = 0; i < count; i++)
    blinkLed();
  //delay(1000);
}
