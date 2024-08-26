#include <stdio.h>
#include<windows.h>
#include "structs.c"
#include "initialize.c"
#include "findindex.c"
#include"findPindex.c"
#include "addCategory.c"
#include "display.c"
#include "addProduct.c"
#include "removeCategory.c"
#include"removeProduct.c"
#include"sell.c"
#include"moveProduct.c"


COORD coord= {0,0};                  // this is global variable
//center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


int main()
{


supermarket super;
    initialize(&super);


/////////////////////////menu start//////////////////////////////////////////////

    int selected=0;
    while(1)
    {
        system("cls");
/////////////////////////////drawing menu/////////////////////////////////

        gotoxy(5,5);
        if (selected==0)
        {
            SetColor(0x0E);
            printf(" --> display \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     display \n");
        }
        gotoxy(5,6);
        if (selected==1)
        {
            SetColor(0x0E);
            printf(" --> add category \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     add category \n");
        }

        gotoxy(5,7);
        if (selected==2)
        {
            SetColor(0x0E);
            printf(" --> add product \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     add product \n");
        }
        gotoxy(5,8);
        if (selected==3)
        {
            SetColor(0x0E);
            printf(" --> Remove Category \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     Remove Category \n");
        }
        gotoxy(5,9);
        if (selected==4)
        {
            SetColor(0x0E);
            printf(" --> remove product \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     remove product \n");
        }
         gotoxy(5,10);
        if (selected==5)
        {
            SetColor(0x0E);
            printf(" --> Sell product \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     Sell product \n");
        }
           gotoxy(5,11);
        if (selected==6)
        {
            SetColor(0x0E);
            printf(" --> move product \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     move product \n");
        }
        gotoxy(5,12);
        if (selected==7)
        {
            SetColor(0x0E);
            printf(" --> exit \n");
        }
        else
        {
            SetColor(0x0F);
            printf("     exit \n");
        }

/////////////////////////////////moving cursor//////////////////////////////////////////////////////

        char key ;
        key =getch();
        if(key== -32)
        {
            key=getch();

            switch(key)
            {
            case 72://up
                if(selected==0)
                {
                    selected=7;
                }
                else
                {
                    selected--;
                }
                break;

            case 80://down
                if(selected==7)
                {
                    selected=0;
                }
                else
                {
                    selected++;
                }
                break;
            }
        }
        else if(key==13)  //enter
        {
            if(selected==0)
            {
                system("cls");
                display(&super);
                getche();
            }
            else if(selected==1)
            {
                system("cls");
                addCategory(&super);
                getche();
            }
            else if(selected==2)
            {
                system("cls");
                addProduct(&super);
                getche();
            }
            else if(selected==3)
            {
                 system("cls");

                removeCategory(&super);
                getche();
            }
            else if(selected==4)
            {
                system("cls");
                removeProduct(&super);
                getche();

            }
             else if(selected==5)
            {
                system("cls");
                sell(&super);
                getche();

            }
              else if(selected==6)
            {
                system("cls");
                moveProduct(&super);
                getche();

            }
            else if(selected==7)
            {
                system("cls");
                return 0;

            }
        }
////////////////////////////////menu end////////////////////////////////////////////





    }



    return 0;
}
