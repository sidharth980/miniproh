#define sep A1
#define mor A0

int x=0,y=0; // Uptime value reader for Morse
int val;

int morseLocator = 0;

bool q,p;

char morse[4];
char letter;
char str[25];

char morsestr[][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "!"
};

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
}

void loop(){
    //Read and assign boolean value for morse
    delay(500);
    val = analogRead(mor);
    Serial.println(val);
    if (val>=100)
    q = 1;
    else
    q = 0;
    //Read and assign boolean value for seperator
    val = analogRead(sep);
    Serial.println(val);
    if (val>=100)
    p = 1;
    else
    p = 0;
    
    if (q == 1)
    x++;
    if (p==1)
    y++;

    // Assign . and -
    if (q == 0){
        if(x!=0){
            if(x<5)
            morse[morseLocator] = '.';
            else
            morse[morseLocator] = '-';
            morseLocator++;
            x=0;
            if(morseLocator=4){
                morseLocator = 0;
                memset(morse, 0, sizeof(morse));
            }
        }
    }
    // Read Seperator
    if (p == 0){
        if(y!=0){
            if(y<5)
            letter = retAlph(morse);
            y = 0; 
        }
    }
    Serial.println(morse);
    Serial.println(letter);
}