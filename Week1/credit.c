/*
Passes the automatic check from CS50
    check50 cs50/problems/2020/x/credit

Credit Card Formats
    American Express
        15 digits, starts with 34 or 37
    Mastercard
        16 digits, starts with 51, 52, 53, 54, 55
    VISA
        13 or 16 digits, starts with 4

Checksum
    - Multiply every other digit by 2, starting with the second-to-last digit
    - Add those products digits together
    - Add the sum to the sum of the digits that weren't multiplied by 2.
    - If the total's last digit is 0, number is valid!
*/

#include <stdio.h>
#include <cs50.h>

//Luhn's Algorithm
int checkSum(long number){
    //going to deal with 2 digits at a time and then shift and deal with the next 2.
    int sum = 0;
    while (number > 0){
        int digit1 = number % 10; //  Add the sum to the sum of the digits that weren't multiplied by 2.
        sum += digit1;
        int digit2 = 2*((number/10) % 10); //Multiply every other digit by 2, starting with the second-to-last digit
        int productDigits = digit2 % 10 + digit2/10 % 10; // Add those products digits together
        sum += productDigits;
        number /= 100; //shift it 2 places so we can deal with the next 2 numbers
    }
    return sum % 10 == 0; // If the total's last digit is 0, number is valid!
}

int getFirstDigits(long number){
    while (number > 100){
        number /= 10;
    }
    return number;
}

int getLength(long number){
    int counter = 0;

    while (number > 0){
        number /= 10;
        counter++;
    }
    return counter;
}

int main(void){
    long number = get_long("Number: ");
    if(checkSum(number)){
        int firsts = getFirstDigits(number);
            if((getLength(number) == 16 || getLength(number) == 13) && firsts/10 == 4){
                printf("VISA\n");
            } else if (getLength(number) == 16 && (firsts == 51 || firsts == 52 || firsts == 53 || firsts == 54 || firsts % 100 == 55)) {
                printf("MASTERCARD\n");
            } else if (getLength(number) == 15 && (firsts == 34 ||firsts == 37)) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }
    } else {
        printf("INVALID\n");
    }
}

