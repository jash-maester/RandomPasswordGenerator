/*
Description:-   Generating Random Passwords.
Written By:- Jashaswimalya Acharjee.
Created On:- 18/04/2020
*/
/* NOTES
    1) Used strncat instead of strcat as strcat copies the second string until the whole memory is full. Don't know why its so.
    2) Used Fisher–Yates shuffle Algorithm to shuffle the string.
    3) Used references from StackOverflow
    4) Anyone is free to contribute to it to make this more efficient
    5) I have used time as a factor to generate randomness.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void randomFnc(int length);
void swap(char *a, char *b);
int digits = 8;

int main(int argc, char *argv[])
{

    /* *************************************************************************************** */
    //Control Check
    if (argc != 2)
    {
        printf("Usage: ./randPassGen [Length]\n\tLength should be a multiple of 4.\n");
        return 1;
    }
    if (atoi(argv[1]) % 4 != 0)
    {
        printf("Usage: ./randPassGen [Length]\n\tLength should be a multiple of 4.\n");
        return 1;
    }
    if (atoi(argv[1]) == 0)
    {
        printf("Usage: ./randPassGen [Length]\n\tLength should be a multiple of 4.\nLength Should Be and Integer.\n");
        return 1;
    }
    /* **************************************************************************************** */

    int digits = 0;
    digits = atoi(argv[1]);

    //Executing the driver function
    randomFnc(digits);

    return 0;
}
void randomFnc(int length)
{
    int i, digits = 0;
    digits = length;
    time_t t;
    int count = 0;
    count = digits / 4;

    char string[digits];
    for (int i = 0; i < digits; i++)
    {
        string[i] = '\0';
    }

    char str[count];

    for (i = 0; i < count; i++)
    {
        srand((unsigned)time(&t));
        str[i] = (rand() % 26) + 65;
        sleep(1); //To increase variability in the time function.
    }
    strncat(string, str, count);

    for (int i = 0; i < count; i++)
    {
        srand((unsigned)time(&t));
        str[i] = (rand() % 26) + 97;
        sleep(1); //To increase variability in the time function.
    }
    strncat(string, str, count);

    for (int i = 0; i < count; i++)
    {
        srand((unsigned)time(&t));
        str[i] = (rand() % 10) + 48;
        sleep(1); //To increase variability in the time function.
    }
    strncat(string, str, count);

    int symbols[7] = {64, 33, 35, 36, 38, 61, 96};

    for (int i = 0; i < count; i++)
    {
        srand((unsigned)time(&t));
        int x = rand() % 7;
        str[i] = symbols[x];
        sleep(2); //To increase variability in the time function.
    }
    strncat(string, str, count);

    srand(time(NULL));
    int n = sizeof(string) / sizeof(string[0]);
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
        // Swap string[i] with the element at random index
        swap(&string[i], &string[j]);
    }

    printf("Random Generated Password: %s\n", string);
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
