from cs50 import get_string
import math
import sys

def words(text):
    wordcount = 1
    for i in range(len(text)):
        if text[i] == " " or text[i] == "\t" or text[i] == "\n":
            wordcount += 1
    return wordcount

while True:
    text = get_string("Text:")
    if len(text) > 0:
        break
    else:
        print("cannot grade empty text")
        continue

words = words(text)
print(words)