const int ledPinBlinkSlow = 3;
const int ledPinBlinkFast = 5;
const int ledPinBlinkMicrosMid = 6;
const int ledPinBlinkMicrosFast = 9;
const int ledPinBlinkMicrosVeryFast = 10;

int ledStateBlinkSlow = LOW;  
int ledStateBlinkFast = LOW;
int ledStateBlinkMicrosMid = LOW;
int ledStateBlinkMicrosFast = LOW;
int ledStateBlinkMicrosVeryFast = LOW;

unsigned long previousMillisSlow = 0; 
unsigned long previousMillisFast = 0;

unsigned long previousMicrosMid = 0;
unsigned long previousMicrosFast = 0;
unsigned long previousMicrosVeryFast = 0;

const long intervalSlow = 10;
const long intervalFast = 1;
const long intervalMicrosMid = 500;
const long intervalMicrosFast = 100; 
const long intervalMicrosVeryFast = 50;

void setup() {
  pinMode(ledPinBlinkSlow, OUTPUT);
  pinMode(ledPinBlinkFast, OUTPUT);
  pinMode(ledPinBlinkMicrosMid, OUTPUT);
  pinMode(ledPinBlinkMicrosFast, OUTPUT);
  pinMode(ledPinBlinkMicrosVeryFast, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();

  if (currentMillis - previousMillisSlow >= intervalSlow) {
    previousMillisSlow = currentMillis;
    ledStateBlinkSlow = !ledStateBlinkSlow;
  }

  if (currentMillis - previousMillisFast >= intervalFast) {
    previousMillisFast = currentMillis;
    ledStateBlinkFast = !ledStateBlinkFast;
  }

  if (currentMicros - previousMicrosMid >= intervalMicrosMid) {
    previousMicrosMid = currentMicros;
    ledStateBlinkMicrosMid = !ledStateBlinkMicrosMid;
  }

  if (currentMicros - previousMicrosFast >= intervalMicrosFast) {
    previousMicrosFast = currentMicros;
    ledStateBlinkMicrosFast = !ledStateBlinkMicrosFast;
  }

  if (currentMicros - previousMicrosVeryFast >= intervalMicrosVeryFast) {
    previousMicrosVeryFast = currentMicros;
    ledStateBlinkMicrosVeryFast = !ledStateBlinkMicrosVeryFast;
  }

  digitalWrite(ledPinBlinkSlow, ledStateBlinkSlow);
  digitalWrite(ledPinBlinkFast, ledStateBlinkFast);
  digitalWrite(ledPinBlinkMicrosMid, ledStateBlinkMicrosMid);
  digitalWrite(ledPinBlinkMicrosFast, ledStateBlinkMicrosFast);
  digitalWrite(ledPinBlinkMicrosVeryFast, ledStateBlinkMicrosVeryFast); 
}
