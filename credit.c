#include <stdio.h>
#include <cs50.h>

// The program will scan a card and output if its a valid Visa,AMEX or MasterCard.
void checksum(long number);

int main()
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);
    checksum(number);
}

void checksum(long number)
{
    /*
     Luhns Alogorithm
     Assigning value of a 12-13 digit card number to seperate variables.
     variable for every other digit of a card * 2
     suppose card: 123456789
     card % 100 = 89 => 89/10 = 8
     since we have to * every other number by 2. we need to multiply
     (2, 4, 6, 8 and so on)
    */
    int num1 = ((number % 100) / 10) * 2;
    int num2 = ((number % 10000) / 1000) * 2;
    int num3 = ((number % 1000000) / 100000) * 2;
    int num4 = ((number % 100000000) / 10000000) * 2;
    int num5 = ((number % 10000000000) / 1000000000) * 2;
    int num6 = ((number % 1000000000000) / 100000000000) * 2;
    int num7 = ((number % 100000000000000) / 10000000000000) * 2;
    int num8 = ((number % 10000000000000000) / 1000000000000000) * 2;

    /* now let suppose if any of these number are 2 digit numbers then
    we add them seperately. i.e 12 = 1+2=3
    */
    num1 = (num1 % 100) / 10 + (num1 % 10);
    num2 = (num2 % 100) / 10 + (num2 % 10);
    num3 = (num3 % 100) / 10 + (num3 % 10);
    num4 = (num4 % 100) / 10 + (num4 % 10);
    num5 = (num5 % 100) / 10 + (num5 % 10);
    num6 = (num6 % 100) / 10 + (num6 % 10);
    num7 = (num7 % 100) / 10 + (num7 % 10);
    num8 = (num8 % 100) / 10 + (num8 % 10);

    int sum1 = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8;

    /* now we add all these nums to all other digits.
    */
    //last digit
    int num9 = (number % 10);
    int num10 = ((number % 1000) / 100);
    int num11 = ((number % 100000) / 10000);
    int num12 = ((number % 10000000) / 1000000);
    int num13 = ((number % 1000000000) / 100000000);
    int num14 = ((number % 100000000000) / 10000000000);
    int num15 = ((number % 10000000000000) / 1000000000000);
    int num16 = ((number % 1000000000000000) / 100000000000000);

    int sum2 = num9 + num10 + num11 + num12 + num13 + num14 + num15 + num16;
    // now we add sum1 and sum2. if result has 0 last digit card number is valid;
    int result = sum1 + sum2;

    // Declaring the type of cards
    int length = 0; // to find the length of the given card
    long firstDigit = number;
    long AmexDigits = number;
    long MasterCard = number;

    // length of number
    while (number > 0)
    {
        number = number / 10;
        length++;
    }
    // theorem
    int zeroInResult = result % 10;
    if (zeroInResult != 0 || length < 12)
    {
        printf("INVALID");
        printf("\n");
    }
    // Fetches the first digit from the input
    while (firstDigit >= 10)
    {
        firstDigit /= 10;
    }
    // fetches the first 2 digits of length 15
    while (AmexDigits >= 10000000000000)
    {
        AmexDigits /= 10000000000000;
    }
    // fetches the first 2 digits of length 16
    while (MasterCard >= 100000000000000)
    {
        MasterCard /= 100000000000000;
    }
    // conditions for a Visa Card
    if ((length == 13 || length == 16) && firstDigit == 4)
    {
        printf("VISA");
        printf("\n");
    }
    // conditions for an AMEX card
    else if (length == 15 && (AmexDigits == 34 || AmexDigits == 37))
    {
        printf("AMEX");
        printf("\n");
    }
    //conditions for an MasterCard
    else if (length == 16 && (MasterCard == 51 || MasterCard == 52 || MasterCard == 53 || MasterCard == 54 || MasterCard == 55))
    {
        printf("MASTERCARD");
        printf("\n");
    }
}
