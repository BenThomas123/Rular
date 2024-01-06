#include <LiquidCrystal.h> 
#define SIZE 6
#define Piezo 7;
int Contrast = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int total = 0;
String a[] = {"head down", "close eyes", "deepBreath relax", "pause feelBetter", "keep going", "love you", "beleive in you", "go get em"};
int LEDS[] = {0, 1, 8, 9, 10, 13}; 
void setup(){
  analogWrite(6, Contrast);
lcd.begin(16, 2);
  for (int i = 0; i < SIZE; i++){
    pinMode(LEDS[i], OUTPUT);
  }
} 
void loop(){
  if (total % 4 == 0){
    int randomNumber1 = random(0, 7);
    int randomNumber2 = random(0, 7);
    tone(7, 432);
    lcd.setCursor(0, 0);
    lcd.print(a[randomNumber1]);
    lcd.setCursor(0, 1);
    lcd.print(a[randomNumber2]);
    on();
    lcd.clear();
  }
  else if (total % 4 == 1){
    int randomNumber1 = random(0, 7);
    int randomNumber2 = random(0, 7);
    tone(7, 528);
    lcd.setCursor(0, 0);
    lcd.print(a[randomNumber1]);
    lcd.setCursor(0, 1);
    lcd.print(a[randomNumber2]);
    onAndOff();
    lcd.clear();
  }
  else if (total % 4 == 2){
    int randomNumber1 = random(0, 7);
    int randomNumber2 = random(0, 7);
    tone(7, 639);
    lcd.setCursor(0, 0);
    lcd.print(a[randomNumber1]);
    lcd.setCursor(0, 1);
    lcd.print(a[randomNumber2]);
    order();
    lcd.clear();
  }
  else if (total % 4 == 3){
    int randomNumber1 = random(0, 7);
    int randomNumber2 = random(0, 7);
    tone(7, 741);
    lcd.setCursor(0, 0);
    lcd.print(a[randomNumber1]);
    lcd.setCursor(0, 1);
    lcd.print(a[randomNumber2]);
    randomNumber();
    lcd.clear();
  }
  total++;
}
void on(){
  for (int i = 0; i < SIZE; i++){
    digitalWrite(LEDS[i], HIGH);
  }
  delay(30000);
}
void order(){
  for (int i = 0; i <= SIZE; i++){
    digitalWrite(LEDS[i], HIGH);
    delay(300);
    digitalWrite(LEDS[i], LOW);
    delay(300);
  }
  delay(2000);
}
void randomNumber(){
  int randomNumber;
  int i = 1;
  while (i <= 20){
    randomNumber = random(0, 6);
    digitalWrite(LEDS[randomNumber], HIGH);
    delay(300);
    digitalWrite(LEDS[randomNumber], LOW);
    i++;
  }
}
void onAndOff(){
  for(int i = 0; i < 5; i++){
    for (int i = 0; i < SIZE; i++){
    digitalWrite(LEDS[i], HIGH);
    delay(300);
    digitalWrite(LEDS[i], LOW);
    delay(300);
    }
  }

}