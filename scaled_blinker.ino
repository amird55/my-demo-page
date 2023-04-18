/*
הנורה מהבהבת בקצב התאים לרמת הסיבוב של הפוטנציומטר
אין להשתמש בפקןדת DELAY
*/
int prdArr[5]={4000,2000,1200,400,150};
#define ledAnalog 9
#define pinLed 6
bool isLedOn;
unsigned long lastToggleTime;

void setup() {
  pinMode(ledAnalog,OUTPUT);
  pinMode(pinLed,OUTPUT);
  ledOff();
  lastToggleTime=millis();
}

void loop() {
  analogWrite(ledAnalog,50);
  int potz_val=map(analogRead(A0),0,1023,0,4);
  int prd = prdArr[potz_val];
  if(millis()-lastToggleTime > prd){
      toggleLed();
  }
}
void toggleLed(){
  lastToggleTime=millis();
  if(isLedOn){
    ledOff();
  } else {
    ledOn();
  }
}
void ledOn(){
  digitalWrite(pinLed,HIGH);
  isLedOn=true;
}
void ledOff(){
  digitalWrite(pinLed,LOW);
  isLedOn=false;
}
