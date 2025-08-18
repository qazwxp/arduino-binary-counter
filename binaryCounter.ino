//pin assignments
const int ledPins[4] = {5,4,3,2};
const int warningPin = 6;
const int plusButtonPin = 8;
const int minButtonPin = 7;

//misc variable declaration
int decCounter = 0;
bool down1 = false;
bool down2 = false;
int plusButtonState = 0;
int minButtonState = 0;
bool binCounter[4];
int temp = decCounter;
int index = 0;
const int holdTime = 1500;

bool plusHold = false;
unsigned long plusTime1;
unsigned long plusTime2;

bool minHold = false;
unsigned long minTime1;
unsigned long minTime2;

void setZero(){ //reset LEDs
  for (int i = 0; i < 4; i++) {
    binCounter[i] = 0;
  }
}

void updateCounter(){ //update LEDs based on decCounter
  setZero();

  temp = decCounter;
  index = 0;
  while (temp>0){
    binCounter[index] = temp%2;
    temp /= 2;
    index++;
  }
  for (int i = 0;i<4;i++){
    digitalWrite(ledPins[i], binCounter[i] ? HIGH : LOW);
  }
}

void minCounter(){
  if (decCounter<1){
    for(int i = 0; i<2; i++){
      digitalWrite(warningPin, HIGH);
      delay(50);
      digitalWrite(warningPin, LOW);
      delay(50);
    }
  }
  else{
    decCounter--;
  }
  updateCounter();
}

void plusCounter(){
  if (decCounter == 15){
      decCounter = 0;
    }
    else{
      decCounter++;
    }
    updateCounter();
}


void setup() {
  Serial.begin(9600);
  pinMode(plusButtonPin, INPUT);
  pinMode(minButtonPin, INPUT);
  for (int i = 0; i<4; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(warningPin, OUTPUT);
  setZero();
}

void loop() {
  Serial.print(decCounter);
  plusButtonState = digitalRead(plusButtonPin);
  minButtonState = digitalRead(minButtonPin);

  //increasing
  if (plusButtonState == HIGH) { // && down1==false
    minTime1 = 0;
    if (plusTime1 == 0){
      plusCounter();
      plusTime1 = millis();
    }
    plusTime2 = millis();
    
    if (plusTime2-plusTime1>= holdTime && (plusTime2-plusTime1)%125 <= 24){
      plusCounter();
    }
  }
  else{
    plusTime1 = 0;
  }

  // decreasing
  if (minButtonState == HIGH) { // && down1==false
    plusTime1 = 0;
    if (minTime1 == 0){
      minCounter();
      minTime1 = millis();
    }
    minTime2 = millis();
    
    if (minTime2-minTime1>= holdTime && (minTime2-minTime1)%200 <= 24){
      minCounter();
    }
  }
  else{
    minTime1 = 0;
  }
  delay(25);
}