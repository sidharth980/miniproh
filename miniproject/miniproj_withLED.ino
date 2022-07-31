#include <LiquidCrystal.h>

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
}


void loop(){
//Read and assign boolean valuor morse
delay(10); // Frequency
val = analogRead(mor); // Read analogue pin 0
//Assign q = mor with boolean
if (val>=300)
q = 1;
else
q = 0;
//Read and assign boolean value for seperator
val = analogRead(sep); // read seperator pin
//assign p = seperator with boolean
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
      Serial.println(x);
        if(x<16){
          morse[morseLocator] = '.';
        }
        else{
          morse[morseLocator] = '-';}
        morseLocator++;
        x = 0;
        if(morseLocator==5){
            morseLocator = 0;
            memset(morse, 0, sizeof(morse));

        }
    }
}
Serial.println(morse);

// Read Seperator
if (p == 0){
    if(y!=0){
        if(y<16){
            letter[letterlocator] = retAlph(morse);
            letterlocator++;
            morseLocator = 0;
            y = 0;
            memset(morse, 0, sizeof(morse));
            LCD_print(letter);
        }
        // else if(y<100){
        //     TTS CONVERSION CODE HERE
        //         letterlocator = 0;
        //         memset(letter, 0, sizeof(letter))
        // }
        else{
            letterlocator = 0;
            memset(letter, 0, sizeof(letter))
        }
    }

}
Serial.println(letter);
}