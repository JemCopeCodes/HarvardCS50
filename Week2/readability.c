/* Coleman-Liau Index - Determine Text's Reading Grade Level
index = 0.0588 * L - 0.296 * S - 15.8
L == Average Number of Letters per 100 words
S == Average Number of sentences per 100 words

- Consider any sequence of characters separated by a space to be a word
- You may assume that a sentence will not start or end with a space, and you may assume that a sentence will not have multiple spaces in a row.
- Consider any sequence of characters that ends with a . or a ! or a ? to be a sentence
*/

#include <cs50.h>
#include <math.h> // for round();

int main(void){
    string textInput = get_string("Text: ");
}