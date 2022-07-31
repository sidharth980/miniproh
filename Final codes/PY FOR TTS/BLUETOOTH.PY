
import time
import serial
from gtts import gTTS
import os

ser = serial.Serial("COM12", 9600, timeout=1)


def retrieveData():
    data = ser.readline().decode('ascii')

    return data


while(True):
    n = ser.in_waiting
    print(n)
    if(n != 0):
        data = retrieveData()
        print(data)
        print("data printed")
        myobj = gTTS(text=data, lang='en', slow=False)

        myobj.save(
            "WELCOME.mp3")
        os.system(
            "start WELCOME.mp3")
    time.sleep(1)
    # else:
    # h = input("enterere")


#

# # This module is imported so that we can
# # play the converted audio
# import os

# # The text that you want to convert to audio
# mytext = 'Welcome to geeksforgeeks!'

# # Language in which you want to convert
# language = 'en'

# # Passing the text and language to the engine,
# # here we have marked slow=False. Which tells
# # the module that the converted audio should
# # have a high speed
# myobj = gTTS(text=mytext, lang=language, slow=False)

# # Saving the converted audio in a mp3 file named
# # welcome
# myobj.save(r"D:\NOTES AND LECTURES\S6\MINI PROJECT\PY FOR TTS\WELCOME.mp3")

# # Playing the converted file
# os.system("start welcome.mp3"
gTTS(text=mytext, lang=language, slow=False)
