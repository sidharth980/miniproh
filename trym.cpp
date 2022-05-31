#include<iostream>
#include<string.h>

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

int main(){
    char morse[5];
    int loc=0;
    char a;
    while(1==1){
        std::cin>>a;
        morse[loc] = a;
        loc++;
        if(loc==5)
        loc = 0;
        a = retAlph(morse);
        std::cout<<"char :"<<a<<"\n";
    }
  return 0;
}