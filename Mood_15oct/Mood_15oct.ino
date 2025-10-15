const int buttonPin = 2;
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

int mood = 0;
const int neutralMood = 10;
int buttonState = 0;
bool ButtonPressed = false;
unsigned long touchedTimer = 0;
unsigned long reducedTimer = 0;
const long unTouchInterval = 5000;
const long reducedInterval = 1000;

unsigned long previousMillis = 0;
int fadingDirection = 1;

//the setup routine runs once when you press reset:
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);


  //initialize the mood state
  mood = neutralMood;
}

//the loop routine runs over and over again forever:
void loop() {

showLEDState(mood);

//check if the button is pressed or not
buttonState = digitalRead(buttonPin);

//if the button is clicked
if(buttonState == HIGH && !ButtonPressed){
//increase the mood
mood = mood + 1;
if(mood > 20) mood = 20;
//update the touched timer
touchedTimer = millis();
ButtonPressed = true;
  }
if(buttonState == LOW && ButtonPressed){
  ButtonPressed = false;
  }

  unsigned long currentTimer = millis();
  if(currentTimer - touchedTimer > unTouchInterval){
    //reduce the point
    if(currentTimer - reducedTimer > reducedInterval){
      mood = mood - 1;
      if(mood < 0) mood = 0;
      reducedTimer = currentTimer;
    }
  }
}
  void showLEDState(int state){
    float brightnessInterval = 255 / 10.0;
    if(state >= neutralMood){
      analogWrite(RledPin, 0);
      analogWrite(GledPin, 255 - brightnessInterval * (state - neutralMood));
      analogWrite(BledPin, brightnessInterval * (state - neutralMood));
    }
    else{
      analogWrite(RledPin, brightnessInterval * (neutralMood - state));
      analogWrite(GledPin, 255 - brightnessInterval * (neutralMood - state));
      analogWrite(BledPin, 0);
  }
}
