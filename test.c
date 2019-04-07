#include<stdio.h>
#include<stdlib.h>
#include"parcel.c"




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *rand_string(char *str)
{
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU";
    int num;
    for (int n = 0; n < 6; n++)
    {
        num = (rand() % (sizeof(charset)));
        printf("num : %d\n", num);
        str[n] = charset[num];
    }
    str[6] = '\0';
}

int main()
{
    char s[7];

    rand_string(s);

    printf("%s\n", s);

    return 0;
}