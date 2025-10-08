const int buttonPin = 2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int buttonState = 0;
int ledState = LOW;
int ledcolor = 0;

bool ButtonPressed = false;

String currentcolor="led";

unsigned long previousMillis = 0; 
const long interval = 1000;

void setup() {
  // put your setup code here, to run once:
pinMode(RledPin, OUTPUT);
pinMode(GledPin, OUTPUT);
pinMode(BledPin, OUTPUT);
pinMode(buttonPin, INPUT);
Serial.begin(9600);//Baund rate setting
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  Serial.print("Current Color;");
  Serial.println(currentcolor);

  if(buttonState == HIGH){
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
    //delay(100);
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }

  if(ledcolor == 0){
    currentcolor="LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 1){
    //red
    currentcolor="Red";
      if (ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 2) {
    //green
    currentcolor="Green";
      if (ledState == LOW) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 3) {
    //blue
    currentcolor="Blue";
      if (ledState == LOW) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 4) {
    //Yellow
    currentcolor="Yellow";
      if (ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 5) {
    //purple
    currentcolor="Purple";
      if (ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 6) {
    //cyan
    currentcolor="Cyan";
      if (ledState == LOW) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 7) {
    //white
    currentcolor="White";
      if (ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 8){
    ledcolor = 0;
  }
}