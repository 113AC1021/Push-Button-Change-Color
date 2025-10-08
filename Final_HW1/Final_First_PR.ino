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

unsigned long lastClickTime = 0;
int clickCount = 0;
const unsigned long clickInterval = 1000;

bool holding = false;
unsigned long lastFlashTime = 0;

bool serialBlink = false;
unsigned long serialBlinkStart = 0;
const unsigned long serialBlinkDuration = 5000;
bool serialLedState = false;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (Serial.available() > 0) {
    String input = Serial.readString();
    input.trim();

    if (input.equalsIgnoreCase("red")) ledcolor = 1;
    else if (input.equalsIgnoreCase("green")) ledcolor = 2;
    else if (input.equalsIgnoreCase("blue")) ledcolor = 3;
    else if (input.equalsIgnoreCase("yellow")) ledcolor = 4;
    else if (input.equalsIgnoreCase("purple")) ledcolor = 5;
    else if (input.equalsIgnoreCase("cyan")) ledcolor = 6;
    else if (input.equalsIgnoreCase("white")) ledcolor = 7;
    else if (input.equalsIgnoreCase("off") || input.equalsIgnoreCase("no color")) ledcolor = 0;

    serialBlink = true;
    serialBlinkStart = currentMillis;
    serialLedState = true;
  }

  buttonState = digitalRead(buttonPin);

  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  if (!serialBlink) {
    if (buttonState == HIGH && !ButtonPressed) {
      ButtonPressed = true;
      clickCount++;
      lastClickTime = currentMillis;
    }
    if (buttonState == LOW && ButtonPressed) {
      ButtonPressed = false;
    }

    if (currentMillis - lastClickTime > clickInterval && clickCount > 0 && !holding) {
      if (clickCount == 1) ledcolor = 1;
      else if (clickCount == 2) ledcolor = 2;
      else if (clickCount == 3) ledcolor = 4;
      else if (clickCount == 4) ledcolor = 3;
      else if (clickCount == 5) ledcolor = 5;
      else if (clickCount == 6) ledcolor = 6;
      else if (clickCount == 7) ledcolor = 7;
      else if (clickCount >= 8) ledcolor = 0;
      clickCount = 0;
    }

    if (buttonState == HIGH && (currentMillis - lastClickTime > 400)) {
      holding = true;
    } 
    if (buttonState == LOW) {
      holding = false;
    }
  }

  if (holding && !serialBlink) {
    if (currentMillis - lastFlashTime > random(1, 10)) {
      lastFlashTime = currentMillis;
      ledcolor = random(1, 7);
      showColor(true);
    }
    return;
  }

  if (serialBlink) {
    if (currentMillis - serialBlinkStart >= serialBlinkDuration) {
      serialBlink = false;
      serialLedState = true;
    } else {
      if ((currentMillis / 250) % 2 == 0) serialLedState = true;
      else serialLedState = false;
    }
    showColor(serialLedState);
    return;
  }

  if (!serialBlink) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      ledState = !ledState;
    }
    showColor(ledState == LOW);
  }
}

void showColor(bool on) {
  if (ledcolor == 0) {
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) {
    currentcolor = "Red";
    digitalWrite(RledPin, on ? LOW : HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 2) {
    currentcolor = "Green";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, on ? LOW : HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 3) {
    currentcolor = "Blue";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, on ? LOW : HIGH);
  }
  else if (ledcolor == 4) {
    currentcolor = "Yellow";
    digitalWrite(RledPin, on ? LOW : HIGH);
    digitalWrite(GledPin, on ? LOW : HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 5) {
    currentcolor = "Purple";
    digitalWrite(RledPin, on ? LOW : HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, on ? LOW : HIGH);
  }
  else if (ledcolor == 6) {
    currentcolor = "Cyan";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, on ? LOW : HIGH);
    digitalWrite(BledPin, on ? LOW : HIGH);
  }
  else if (ledcolor == 7) {
    currentcolor = "White";
    digitalWrite(RledPin, on ? LOW : HIGH);
    digitalWrite(GledPin, on ? LOW : HIGH);
    digitalWrite(BledPin, on ? LOW : HIGH);
  }
}