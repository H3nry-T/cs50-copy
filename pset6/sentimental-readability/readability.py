from cs50 import get_string
import math
import sys
from nltk.tokenize import sent_tokenize


def main():
    while True:
        text = get_string("Text:")
        if len(text) > 0:
            break
        else:
            print("cannot grade empty text")
            continue

    word = words(text)
    letter = letters(text)
    sentence = sentencesnew(text)
    L = letter / word * 100
    S = sentence / word * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def words(text):
    wordcount = 1
    for i in range(len(text)):
        if text[i] == " " or text[i] == "\t" or text[i] == "\n":
            wordcount += 1
    return wordcount


def letters(text):
    lettercount = 0
    for i in range(len(text)):
        if text[i].isalpha():
            lettercount += 1
    return lettercount


def sentences(text):
    sentence_count = sent_tokenize(text)
    return len(sentence_count)

def sentencesnew(text):
    sentence_count = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            sentence_count += 1
    return sentence_count
if __name__ == "__main__":
    main()
