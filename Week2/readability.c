/* Passes check50 cs50/problems/2021/x/readability

Coleman-Liau Index - Determine Text's Reading Grade Level
index = 0.0588 * L - 0.296 * S - 15.8
L == Average Number of Letters per 100 words
S == Average Number of sentences per 100 words

- Consider any sequence of characters separated by a space to be a word
- You may assume that a sentence will not start or end with a space, and you may assume that a sentence will not have multiple spaces in a row.
- Consider any sequence of characters that ends with a . or a ! or a ? to be a sentence
---------
Note: Could definitely just iterate through the text once and count everything as you go. It would be more efficient for runtime and memory.
However, I broke it into separate functions so it's easier to read since this is for learning.
*/


#include <cs50.h>
#include <math.h> // for round();
#include <string.h> //strlen();
#include <stdio.h> //printf();
#include <ctype.h> //isalpha();

int count_letters(string text){
    int count = 0;

    for(int i = 0; i <= strlen(text); i++)
        if(isalpha(text[i]))
            count++;
    return count;
}

int count_words(string text){
    int count = 1;
    for(int i = 0; i <=strlen(text); i++){
        if(text[i] == ' ')
            count++;
    }
    return count;
}

int count_sentences(string text){
    int count = 0;

    for(int i = 0; i < strlen(text); i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
            count++;
    }
    return count;
}

int main(void){
    string textInput = get_string("Text: ");

    int lettersCount = count_letters(textInput);
    int wordCount = count_words(textInput);
    int sentenceCount = count_sentences(textInput);

    float index = round(0.0588 * lettersCount/wordCount * 100 - 0.296 * sentenceCount/wordCount * 100 - 15.8);

    if(index >=16){
        printf("Grade 16+\n");
    } else if (index < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %.0f\n", index);
    }

    /*Tests
    printf("Letter Count: %d\n", lettersCount);
    printf("Word Count: %d\n", wordCount);
    printf("Sentence Count: %d\n", sentenceCount);
    */
}