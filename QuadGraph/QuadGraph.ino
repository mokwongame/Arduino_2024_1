// 변수 정의
int a = 1;
int b = 2;
int c = 3;

// 변수 선언
int x, y;

// 함수 정의
int quadFun() {
  return a * x * x + b * x + c;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  x = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  y = quadFun(); // quadFun() 호출
  Serial.println(y); // y를 Serial로 출력(ASCII)
  x++;
  delay(100); // delay를 100 msec로 설정
}