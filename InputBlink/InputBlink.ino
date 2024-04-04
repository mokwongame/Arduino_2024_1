#define SERIAL_BPS (9600)

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = userInput();
  Serial.println(count);
  //delay(1000);
}
