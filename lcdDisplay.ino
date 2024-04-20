// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  if(Serial.available() > 0){
    String msg = Serial.readString();

    lcd.clear();

    if(msg.length() <= 16){
      lcd.setCursor(0, 0);
      lcd.print(msg);
    }else if(msg.length() > 16 && msg.length() < 32){
      lcd.setCursor(0, 0);
      String firstMsgHalf = msg.substring(0, msg.length()/2);
      lcd.print(firstMsgHalf);
      lcd.setCursor(0, 1);
      String secondMsgHalf = msg.substring(msg.length()/2);
      lcd.print(secondMsgHalf);
    }else if(msg.length() > 32){
      lcd.setCursor(0, 0);
      lcd.print("MSG to long");
    }
  }
}