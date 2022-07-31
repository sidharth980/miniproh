#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial HC06(3, 4); 

#define sep A1
#define mor A0


int x=0,y=0; // Uptime value reader for Morse
int val;
int morseLocator = 0;
bool q,p;
char morse[5];
char morse2[5];
char letter[100];
int letterlocator = 0;
char str[25];
char morsestr[][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",

"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",

".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." , "!"

};



// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void LCD_print(char []);


void LCD_print(char input[])
{
  if(strlen(input)>16)
  {
  char i1[17];
   memcpy(i1, input+strlen(input)-16, 16);
   i1[16] = '\0';
   lcd.print(i1);
  }else
  {
    lcd.setCursor(0,0);
    lcd.print(input);
  }
}

void LCD_morse(char input[])
{
 lcd.setCursor(4, 1);
  if(strlen(input) == 6)
    lcd.print("    ");
  else
    lcd.print(input);
}

char alph[] = "abcdefghijklmnopqrstuvwxyz";


char retAlph(char arr[]){
int lp = 0;
for(lp = 0;lp<26;lp++){
int re = strcmp(morsestr[lp],arr);
  if(re==0||re==-127)
    return alph[lp];
}
return ' ';
}


void setup() {

    Serial.begin(9600);
    lcd.begin(16, 2);
    HC06.begin(9600);
}


void loop(){
//Read and assign boolean valuor morse
delay(50); // Frequency
val = analogRead(mor); // Read analogue pin 0
//Assign q = mor with boolean
Serial.println(val);
if (val>=400)
q = 1;
else
q = 0;
//Read and assign boolean value for seperator
val = analogRead(sep); // read seperator pin
//assign p = seperator with boolean
Serial.println(val);
if (val>=100)
p = 1;
else
p = 0;
// iterate mor = x
if (q == 1)
x++;
// iterate serperator with y
if (p==1)
y++;
// Assign . and -
if (q == 0){
    if(x!=0){
      if(y!=0){
        x = 0;
        y = 0; 
        if (letterlocator !=0)
          letterlocator -= 1;
        letter[letterlocator] = '\0';
        lcd.clear();
        LCD_print(letter);
        }
      else{
      Serial.println(x);
        if(x<5){
          morse[morseLocator] = '.';
        }
        else{
          morse[morseLocator] = '-';}
        morseLocator++;
        x = 0;
        LCD_morse(morse);
        if(morseLocator==5){
            morseLocator = 0;
            memset(morse, 0, sizeof(morse));
        }
        }
    }
}
Serial.println(morse);

// Read Seperator
if (p == 0){
    if(y!=0){
        if(y<5){
            letter[letterlocator] = retAlph(morse);
            letterlocator++;
            morseLocator = 0;
            y = 0;
            LCD_morse("    ");
            memset(morse, 0, sizeof(morse));
            LCD_print(letter);
        }
         else if(y<20){
               LCD_morse("SENT");
               y=0;
               letter[letterlocator] = '\n';
                HC06.print(letter);
                Serial.println("SENT");
                Serial.println(letter);
                delay(5000);
                lcd.clear();
                letterlocator = 0;
                memset(letter, 0, sizeof(letter));
        }
        else{
            letterlocator = 0;
            memset(letter, 0, sizeof(letter));
            lcd.clear();
            y = 0;
        }
    }

}
Serial.println(letter);
}
