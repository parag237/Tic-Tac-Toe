#include <cstdlib>
#include<iostream>
#include<conio.h>
using namespace std;
class Player
{
public:
    int chance;
}p1,p2;
static int win=0;
static int moves[9];
void print(int n)
{
    cout<<n;
}
void board()
{
    cout<<"\n\n    ";
    print(1);
    cout<<"    |    ";
    print(2);
    cout<<"    |    ";
    print(3);
    cout<<"    \n  --------------------------\n    ";
    print(4);
    cout<<"    |    ";
    print(5);
    cout<<"    |    ";
    print(6);
    cout<<"    \n  --------------------------\n    ";
    print(7);
    cout<<"    |    ";
    print(8);
    cout<<"    |    ";
    print(9);
}
void board(int p)
{
    for(int i=0;i<9;i++)
    {
        if(i%3==0 || i%3==1)
        {
            if(moves[i]==0)
                cout<<"         |";
            else if(moves[i]==1)
                cout<<"    X    |";
            else
                cout<<"    O    |";
        }
        else if(i%3==2)
        {
            if(moves[i]==0)
                cout<<"    \n";
            else if(moves[i]==1)
                cout<<"    X\n";
            else
                {cout<<"    O\n";}
            if(i!=8)
                cout<<"  --------------------------"<<endl;
        }
    }
}
int playerMove(Player &p, int n)
{
    cout<<"Enter Move:";
    cin>>p.chance;
    if((p.chance>9 && p.chance<1) || moves[p.chance-1]!=0)
        return 0;
    moves[p.chance-1]=n;
    if(moves[0]==moves[1] && moves[0]==moves[2])
    {
        if(moves[0]==1)
            win=1;
        if(moves[0]==2)
            win=2;
    }
    else if(moves[3]==moves[4] && moves[4]==moves[5])
    {
        if(moves[3]==1)
            win=1;
        if(moves[3]==2)
            win=2;
    }
    else if(moves[6]==moves[7] && moves[7]==moves[8])
    {
        if(moves[6]==1)
            win=1;
        if(moves[6]==2)
            win=2;
    }
    else if(moves[0]==moves[4] && moves[4]==moves[8])
    {
        if(moves[4]==1)
            win=1;
        if(moves[4]==2)
            win=2;
    }
    else if(moves[2]==moves[4] && moves[4]==moves[6])
    {
        if(moves[6]==1)
            win=1;
        if(moves[6]==2)
            win=2;
    }
    else for(int i=0;i<3;i++)
    {
        if(moves[i]==moves[i+3] && moves[i]==moves[i+6])
        {
            if(moves[i]==1)
                win=1;
            if(moves[i]==2)
                win=2;
        }
    }
    return 1;
}
int main()
{
    char con;
    do{
        for(int i=0;i<9;i++)
            moves[i]=0;
        win=0;
        int play=0;
        board();
        while(win==0 && play<5)
        {
            play++;
            system("cls");
            board();
            cout<<"\n\n ENTER YOUR MOVE ACCORDING TO ABOVE BOARD.\n\n\n";
            board(play);
            p1m:if(cout<<"PLAYER 1:\n" && playerMove(p1,1));
            else
            {
                cout<<"Invalid Move..Try again:\n";
                goto p1m;
            }
            system("cls");
            board();
            cout<<"\n\n ENTER YOUR MOVE ACCORDING TO ABOVE BOARD.\n\n\n";
            board(play);
            p2m:if(win!=1 && play!=5 && cout<<"PLAYER 2:\n" && playerMove(p2,2));
            else{
                if(win==1 || play==5)
                        break;
                cout<<"Inavalid Move..Try again:\n";
                goto p2m;
            }

        }
        if(win==0&& play>=5)
        {
            system("cls");
            board(1);
            cout<<"\n\n    ****MATCH DRAW****\n";
        }
        if(win==1)
        {
            cout<<"PLAYER 1 WINS...";
        }
        else if(win==2)
        {
            cout<<"PLAYER 2 WINS...";
        }

        cout<<"\n\nDo you want to continue (if yes press 'y'):";
        cin>>con;
    }while(con=='y' || con=='Y');
    return 0;
}
