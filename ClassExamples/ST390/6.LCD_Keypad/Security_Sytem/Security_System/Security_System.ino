#include<LiquidCrystal.h>
int rs=9 , e=10, d4=11,d5=12,d6=13,d7=A5;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 

int R1=2,R2=3,R3=4,R4=5;
int C1=6,C2=7,C3=8 ;
void setup() {
  pinMode(R1,OUTPUT) ; pinMode(R2,OUTPUT) ; 
  pinMode(R3,OUTPUT) ; pinMode(R4,OUTPUT) ; 
  pinMode(C1,INPUT) ; pinMode(C2,INPUT) ; 
  pinMode(C3,INPUT) ;
  lcd.begin(16,2);
  lcd.print("Security System");
  lcd.setCursor(0,1); lcd.blink();
}
int valc1, valc2, valc3; int num1=0,n=0; int apass=157;
int count=1; boolean isUserValid=false;
void loop() {
  //make R1 as High and rest all rows LOW
  digitalWrite(R1,LOW); digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  digitalWrite(C1,HIGH); digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  valc1 = digitalRead(C1);
  valc2 = digitalRead(C2); valc3 = digitalRead(C3);
  //check for each column
  if ( valc1 == LOW) { lcd.print("*"); n=10*n+1; delay(300);  }
  if ( valc2 == LOW) {lcd.print ("*"); n=10*n+2; delay(300);}
  if ( valc3 == LOW) {lcd.print ("*"); n=10*n+3; delay(300);}
  
  digitalWrite(R1,HIGH);digitalWrite(R2,LOW);
  digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  //check for each column
  if (digitalRead(C1) == LOW) { lcd.print("*");n=10*n+4; delay(300);}
  if (digitalRead(C2) == LOW) { lcd.print("*");n=10*n+5; delay(300);}
  if (digitalRead(C3) == LOW) { lcd.print("*");n=10*n+6; delay(300);}
   
  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);digitalWrite(R4,HIGH);
  //check for each column
  if (digitalRead(C1) == LOW) { lcd.print("*"); n=10*n+7;  delay(300);}
  if (digitalRead(C2) == LOW) { lcd.print("*");n=10*n+8; delay(300);}
  if (digitalRead(C3) == LOW) { lcd.print("*");n=10*n+9; delay(300);}

  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);digitalWrite(R4,LOW);
  //check for each column
  if (digitalRead(C1) == LOW) { 
    n=0;
    lcd.clear();
    lcd.print("Security System");
    lcd.setCursor(0,1);
  }
  if (digitalRead(C2) == LOW) { lcd.print("*");n=10*n+0; delay(300);}
  if (digitalRead(C3) == LOW) { /////validate the entered password
    
    num1=n;
    if (num1 == apass){
      lcd.clear();
      lcd.print("Password correct");
      lcd.setCursor(0,1); lcd.print("Welcome");
      isUserValid=true; 
    }else {
      lcd.clear();
      lcd.print("Password Incorrect");
      lcd.setCursor(0,1);
    }
    n=0;
    delay(300);
    if (isUserValid==false){
      count++;
      if (count >=4){
        lcd.clear();
        lcd.print("System Locked ");
        while(1); // while (count>=4) {}
      }
    }
    
  }
}
