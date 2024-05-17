#define PWR_PIN 20
#define RST_PIN 21
#define TIMEOUT 10000

String cacheString = "";
bool cacheStringComplete = false;
void setup() {
  delay(500);
  Serial.begin(9600);
  pinMode(PWR_PIN, OUTPUT);
  pinMode(RST_PIN, OUTPUT);
  delay(500);
  digitalWrite(PWR_PIN, 0);
  digitalWrite(RST_PIN, 0);
}

void loop() {
  if (cacheStringComplete) {
    cacheString = "";
    cacheStringComplete = false;
  }
}

void serialEvent() {
  if (inChar == '\n') {
    cacheStringComplete = true;
  }
}

//Relay Actions Section
void executeBootEvent(){
  delay(100);
  digitalWrite(PWR_PIN, 1);
  delay(300);
  digitalWrite(PWR_PIN, 0);
  delay(100);
}

void executeSoftRebootEvent(){
  delay(100);
  digitalWrite(RST_PIN, 1);
  delay(300);
  digitalWrite(RST_PIN, 0);
  delay(100);
}

void executeHardRebootEvent(){
  delay(100);
  digitalWrite(PWR_PIN, 1);
  delay(6000);
  digitalWrite(PWR_PIN, 0);
  delay(1000);
  digitalWrite(PWR_PIN, 1);
  delay(300);
  digitalWrite(PWR_PIN, 0);
  delay(100);
}
