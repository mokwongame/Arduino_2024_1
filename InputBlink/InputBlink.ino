#define SERIAL_BPS (9600)

int userInput()
{
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = userInput();
}
