//moving a snake across the screen
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,j;
    clock_t time;
    for(i=1;i<=100;i++)
    {
        time= clock();
        while(clock()<time+100);
        system("cls");
        for(j=1;j<=i+4;j++)
        {
            printf(" ");
        }
        printf("***>");
    }
}