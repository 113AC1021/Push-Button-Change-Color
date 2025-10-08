const int buttonPin = 2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int ledcolor = 0;
int buttonState = 0;
bool ButtonPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000;
bool ledColorOrder = true;

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(RledPin, OUTPUT);
pinMode(GledPin, OUTPUT);
pinMode(BledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH && !ButtonPressed){
    ledColorOrder = !ledColorOrder;
    ButtonPressed = true;
    //delay(100);
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if(ledColorOrder == true){
      ledcolor = ledcolor +1;
      if(ledcolor > 3)
      ledcolor = 0;
    }
    else{
      ledcolor = ledcolor - 1;
      if(ledcolor < 0)
        ledcolor = 3;
      }
    }

  if(ledcolor == 0){
    //red
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 1){
    //green
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 2) {
    //blue
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  } 
  else if(ledcolor == 3) {
    //white
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
}