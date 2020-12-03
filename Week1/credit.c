/*
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
    - Add teh sum to the sum of the digits that weren't multiplied by 2.
    - If the total's last digit is 0, number is valid!
*/

#include <stdio.h>
#include <cs50.h>

int checkSum(long number){
    //Luhn's Algorithm
    printf("%ld\n", number/10 % 10);//testing getting digits
    return 1; //temp for debug
}

int getLength(long number){
    //13, 15, or 16 digit number?
    printf("inside getLength\n");
    return 13; //temp for debug
}

int main(void){
    long number = get_long("Number: ");
    if(checkSum(number)){
            if(getLength(number) == 13 && number/1000000000000000 % 10 == 4){
                printf("VISA\n");
            }
    } else{
        printf("INVALID\n");
    }
}

