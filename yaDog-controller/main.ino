#define PWR_PIN 20
#define RST_PIN 21
#define TIMEOUT 10000

String cacheString = "";
bool cacheStringComplete = false;
void setup() {
  delay(1000);
  Serial.begin(9600);
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

void executeBootEvent(){
  pass();
}

void executeRebootEvent(){
  pass();
}
