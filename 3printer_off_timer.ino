const int input = 1;
const int output = 0;
const int led = 4;
long sekunda = 999;
int timeout = 300;
unsigned long aktualniMillis = 0;
unsigned long minulyMillis = 0;
unsigned long aktualniLedMillis = 0;
unsigned long minulyLedMillis = 0;
int aktualniCas = 0;
int inputState = 0;
int relayState = 1;
int ledState = 1;
int minulyState = 0;

void setup() {
  pinMode(input, INPUT);
  pinMode(output, OUTPUT);
  pinMode(led, OUTPUT);}

void loop() {
  aktualniMillis = millis();
  if((aktualniMillis - minulyMillis) > sekunda){
    minulyMillis = aktualniMillis;
    aktualniCas = aktualniCas + 1;} 
  inputState = digitalRead(input);
  if((inputState != minulyState) && (relayState == 1)){
    aktualniCas = 0;}
  minulyState = inputState;

  if(aktualniCas > timeout){
    relayState = LOW;}
  else {
    relayState = HIGH;}
  
  if((aktualniCas > 10) && (aktualniCas < timeout)){
    aktualniLedMillis = millis();
  if(aktualniLedMillis - minulyLedMillis > 500){
    minulyLedMillis = aktualniLedMillis;
    if(ledState == LOW){
      ledState = HIGH;}
    else {
      ledState = LOW;}
   }
  }
  else if(aktualniCas > timeout){
    ledState = LOW;}
  else {
    ledState = HIGH;}
    
  digitalWrite(output, relayState);
  digitalWrite(led, ledState);
}
