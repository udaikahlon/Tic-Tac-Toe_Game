#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>
#include <windows.h>
#include <string>


using namespace std;
string name;
void InitializeTurns(int &whosturnisit,int &turnsTaken);
void InitializegameBoard (int *gameBoard);
void DrawScreen (int *gameBoard,int turnsTaken,int *gameBoard2);
void taketurnplayer(int *gameBoard,int &turnsTaken,int &whosturnisit);
void taketurncomputer(int *gameBoard,int &turnsTaken,int &whosturnisit,int whoWins,int *gameBoard2);
int checkforwinner(int *gameBoard);
void displayWinner (int &whoWins);
int checkforwinner2 (int*gameBoard2);


int main()
{
int gameBoard[10];
int gameBoard2[10];
int whosturnisit, turnsTaken, whoWins;
cout<<"\t\tWelcome to the Most Hectic Tic Tac Toe Game Ever Made\n\n";
system("pause");
system("cls");

    InitializeTurns(whosturnisit,turnsTaken);
    InitializegameBoard(gameBoard);
    DrawScreen (gameBoard,turnsTaken,gameBoard2);

    do
        {
        if (whosturnisit==1)
            taketurnplayer(gameBoard,turnsTaken,whosturnisit);
        else if (whosturnisit==2)
            taketurncomputer(gameBoard,turnsTaken,whosturnisit,whoWins,gameBoard2);
        DrawScreen(gameBoard,turnsTaken,gameBoard2);
        whoWins=checkforwinner(gameBoard);
        }while (  (turnsTaken<9) && (whoWins==0) );
    displayWinner(whoWins);
    return 99;
}

void InitializegameBoard (int *gameBoard)
{
    for (int i=0;i<11;i++)
    gameBoard[i]=0;
return;
}

void InitializeTurns(int &whosturnisit, int &turnsTaken)
{
    srand(time(NULL));
    string i;
    whosturnisit=0;
    turnsTaken=0;
    cout<<"What is your name human? : \n";
    cin>>name;
    cout<<"Would you like to go first? (yes/no) :";
    cin>>i;
    if (i=="yes")
        whosturnisit=1;
    else if (i=="no")
        whosturnisit=2;
    else
    {
        cout<<"I guess you want me to go first then...";
        whosturnisit=2;
        Sleep(3000);
    }
return;
}

void DrawScreen(int *gameBoard,int turnsTaken,int *gameBoard2)
{
    system("cls");
    cout<<"Most Hectic Tic Tac Toe Game Ever Made";
    cout<<"\n\n____________________\n\n";
    for (int i=1;i<10;i++)
    {
        if (gameBoard[i]==1)
            cout<<"X\t";
        else if (gameBoard[i]==2)
            cout<<"O\t";
        else
            cout<<i<<"\t";
        if (i==3)
        cout<<"\n\n____________________\n\n";
        if (i==6)
        cout<<"\n\n____________________\n\n";
    }
    for (int i=1;i<10;i++)
    {
        gameBoard2[i]=gameBoard[i];
    }
    cout<<"\n\n____________________\n\n";
    cout<<"Turns Taken = "<<turnsTaken;

return;
}

void taketurnplayer(int *gameBoard,int &turnsTaken,int &whosturnisit)
{
    int x=0;
    do
    {
    cout<<"\n\nwhere would u like to place your X\n";
    cin>>x;
    }while (gameBoard[x]!=0);
    gameBoard[x]=1;
    whosturnisit=2;
    turnsTaken++;
    return;
}
void taketurncomputer(int*gameBoard, int &turnsTaken, int &whosturnisit,int whoWins,int *gameBoard2)
{
    int spot=0;


    for (int i=0;i<10;i++)
    gameBoard2[i]=gameBoard[i];

    do
    {
        spot=1+(std::rand()%(9-1+1));
        }while (gameBoard2[spot]!=0);

        //block

        for(int play=1;play<10;play++)
        {
            for (int i=0;i<10;i++)
        gameBoard2[i]=gameBoard[i];

        gameBoard2[play]=1;

        if ((checkforwinner2(gameBoard2)==1) && (gameBoard[play]==0))
            spot=play;
        }
        //win
        for (int play=1;play<10;play++)
        {
        for (int i=0;i<10;i++)
        gameBoard2[i]=gameBoard[i];

        gameBoard2[play]=2;

        if ((checkforwinner2(gameBoard2)==2) && (gameBoard[play]==0))
            spot=play;

        }

        gameBoard[spot]=2;
        whosturnisit=1;
        turnsTaken++;

    cout<<"\n\nPlease wait as I calculate the best possible move...";
    Sleep(2000);
    return;
}
int checkforwinner (int*gameBoard)
{
    int thewinneris=0;
    if((gameBoard[1]==gameBoard[2])&&(gameBoard[2]==gameBoard[3])&&(gameBoard[3]!=0))
        thewinneris=gameBoard[1];
    else if ((gameBoard[4]==gameBoard[5])&&(gameBoard[5]==gameBoard[6])&&(gameBoard[6]!=0))
        thewinneris=gameBoard[4];
    else if ((gameBoard[7]==gameBoard[8])&&(gameBoard[8]==gameBoard[9])&&(gameBoard[9]!=0))
        thewinneris=gameBoard[7];
    else if ((gameBoard[1]==gameBoard[5])&&(gameBoard[5]==gameBoard[9])&&(gameBoard[9]!=0))
        thewinneris=gameBoard[1];
    else if ((gameBoard[2]==gameBoard[5])&&(gameBoard[5]==gameBoard[8])&&(gameBoard[8]!=0))
        thewinneris=gameBoard[2];
    else if ((gameBoard[1]==gameBoard[4])&&(gameBoard[4]==gameBoard[7])&&(gameBoard[7]!=0))
        thewinneris=gameBoard[1];
    else if ((gameBoard[3]==gameBoard[6])&&(gameBoard[6]==gameBoard[9])&&(gameBoard[9]!=0))
        thewinneris=gameBoard[3];
    else if ((gameBoard[3]==gameBoard[5])&&(gameBoard[5]==gameBoard[7])&&(gameBoard[7]!=0))
        thewinneris=gameBoard[3];
        return thewinneris;
}
void displayWinner(int &whoWins)
{
    if (whoWins==1)
    cout<<"\nAwesome job "<<name<<" you won!";
    else if (whoWins==2)
        cout<<"\nBetter Luck Next Time "<<name<<"!!";
    else
        cout<<"\nOur Intellect is matched!\n\nWell Played "<<name;
}
int checkforwinner2 (int*gameBoard2)
{
 int thewinneris2=0;
    if((gameBoard2[1]==gameBoard2[2])&&(gameBoard2[2]==gameBoard2[3])&&(gameBoard2[3]!=0))
        thewinneris2=gameBoard2[1];
    else if ((gameBoard2[4]==gameBoard2[5])&&(gameBoard2[5]==gameBoard2[6])&&(gameBoard2[6]!=0))
        thewinneris2=gameBoard2[4];
    else if ((gameBoard2[7]==gameBoard2[8])&&(gameBoard2[8]==gameBoard2[9])&&(gameBoard2[9]!=0))
        thewinneris2=gameBoard2[7];
    else if ((gameBoard2[1]==gameBoard2[5])&&(gameBoard2[5]==gameBoard2[9])&&(gameBoard2[9]!=0))
        thewinneris2=gameBoard2[1];
    else if ((gameBoard2[2]==gameBoard2[5])&&(gameBoard2[5]==gameBoard2[8])&&(gameBoard2[8]!=0))
        thewinneris2=gameBoard2[2];
    else if ((gameBoard2[1]==gameBoard2[4])&&(gameBoard2[4]==gameBoard2[7])&&(gameBoard2[7]!=0))
        thewinneris2=gameBoard2[1];
    else if ((gameBoard2[3]==gameBoard2[6])&&(gameBoard2[6]==gameBoard2[9])&&(gameBoard2[9]!=0))
        thewinneris2=gameBoard2[3];
    else if ((gameBoard2[3]==gameBoard2[5])&&(gameBoard2[5]==gameBoard2[7])&&(gameBoard2[7]!=0))
        thewinneris2=gameBoard2[3];
             return thewinneris2;
}
