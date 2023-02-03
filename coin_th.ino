#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

#define _1BATH  3
#define _2BATH 4
#define _5BATH 5
#define _10BATH 6
#define PIEZO  8

int count_1BATH  = 0;
int count_2BATH = 0;
int count_5BATH = 0;
int count_10BATH = 0;

int curr_state_1BATH = HIGH;
int prev_state_1BATH = HIGH;
int curr_state_2BATH = HIGH;
int prev_state_2BATH = HIGH;
int curr_state_5BATH = HIGH;
int prev_state_5BATH = HIGH;
int curr_state_10BATH = HIGH;
int prev_state_10BATH = HIGH;

void intro() {
lcd.setCursor(2, 0);
lcd.print("COIN SORTING");
delay(2000);
lcd.clear();
}

void setup() {
lcd.init();
lcd.backlight();
intro();
lcd.setCursor(0, 0);
lcd.print("1  2  5  10THB");
}

void loop() {
lcd.setCursor(0, 1);
lcd.print(count_1BATH);
lcd.setCursor(3, 1);
lcd.print(count_2BATH);
lcd.setCursor(7, 1);
lcd.print(count_5BATH);
lcd.setCursor(11, 1);
lcd.print(count_10BATH);

curr_state_1BATH = digitalRead(_1BATH);
curr_state_2BATH = digitalRead(_2BATH);
curr_state_5BATH = digitalRead(_5BATH);
curr_state_10BATH = digitalRead(_10BATH);

if (curr_state_1BATH == LOW && prev_state_1BATH == HIGH) {
 count_1BATH++;
}
if (curr_state_2BATH == LOW && prev_state_2BATH == HIGH) {
 count_2BATH++;
}
if (curr_state_5BATH == LOW && prev_state_5BATH == HIGH) {
 count_5BATH++;
}
if (curr_state_10BATH == LOW && prev_state_10BATH == HIGH) {
 count_10BATH++;
}

prev_state_1BATH = curr_state_1BATH;
prev_state_2BATH = curr_state_2BATH;
prev_state_5BATH = curr_state_5BATH;
prev_state_10BATH = curr_state_10BATH;
}
