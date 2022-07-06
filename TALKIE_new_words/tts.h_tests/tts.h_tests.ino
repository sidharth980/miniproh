#include <english.h>
#include <sound.h>
#include <TTS.h>


// Media pins                      
#define ttspin 3
TTS text2speech(ttspin);  // default is digital pin 10

void setup() { 

}

void loop() {


  text2speech.setPitch(6);
  text2speech.sayText("Hello  master! How are you doin?");
  delay(500); 

  text2speech.setPitch(1);
  text2speech.sayText("I am fine, thankyou."); 

}  
