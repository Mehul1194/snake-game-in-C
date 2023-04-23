//Snake game in c language
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
char arr[25][40];
int posx=12;
int posy=19;
int dir=1;
int score=0;
void printbox();
void init();
void movingsnake1();
void movingsnake2();
int checkwin();
void fruit();
int gamem();
void entry();
int main()
{
    init();
    fruit();
    gamem();
}
int gamem()
{
    int a,n=0;
    printf("This a snake game\n");
    printf("Use 'w','a','s','d' to navigate the on screen snake");
    printf("Enter any number to start the game\n");
    while(n==0)
    {
        printbox();
        entry();
        movingsnake1();
        n=checkwin();
        movingsnake2();
    }
    system("cls");
    printf("THE GAME HAS ENDED\n");
    printf("The score is:%d",score);
}
void printbox()
{
    clock_t time;
    time= clock();
    while(clock()<time+50);
    system("cls");
    int i,j;
    for(i=0;i<25;i++)
    {
        for(j=0;j<40;j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    printf("Enter the direction of snake");
}
void entry()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'd':
            dir=1;
            break;
            case 's':
            dir=2;
            break;
            case 'a':
            dir=3;
            break;
            case 'w':
            dir=4;
            break;
            default:
            break;
        }
    }
}
int checkwin()
{
    if(arr[posx][posy]=='O')
    {
        score+=1;
        fruit();
        arr[posx][posy]=' ';
    }
    if(posx==0||posy==0||posy==39||posx==24)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
//moving the snake in the required direction according to direction but not printing to check for score first
void movingsnake1()
{
    arr[posx][posy]=' ';
    if(dir==1)
    {
        posy+=1;
    }
    else if(dir==2)
    {
        posx+=1;
    }
    else if(dir==3)
    {
        posy-=1;
    }
    else
    {
        posx-=1;
    } 
}
void movingsnake2()//moving the snake in the required direction according to direction after checking for score
{
    arr[posx][posy]=' ';
    if(dir==1)
    {
        arr[posx][posy]='>';
    }
    else if(dir==2)
    {
        arr[posx][posy]='v';
    }
    else if(dir==3)
    {
        arr[posx][posy]='<';
    }
    else
    {
        arr[posx][posy]='^';
    } 
}
//generate a random value for the fruit and store in the array keeping a boundary of at least one space
void fruit()
{
    int x,y;
    x=(rand()%21)+2;
    y=(rand()%36)+2;
    arr[x][y]='O';
}
void init()//initializing the array for the first time
{
    int i,j;
    for(i=0;i<25;i++)
    {
        for(j=0;j<40;j++)
        {
            if((j==0||j==39)&&(i!=0))
            {
                arr[i][j]='|';
            }
            else if(i==0||i==24)
            {
                arr[i][j]='_';
            }
            else
            {
                arr[i][j]=' ';
            }
        }
    }
    arr[12][19]='>';
}