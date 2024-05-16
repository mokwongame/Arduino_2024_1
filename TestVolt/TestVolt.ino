void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nVolt = analogRead(A0); // 아날로그 포트 A0에서 읽기(0~1023)
  double volt = nVolt*5./1023.; // 0~1023 => 0~5V
  Serial.println(String(nVolt) + " => " + String(volt) + "V");
  delay(1000);
}
