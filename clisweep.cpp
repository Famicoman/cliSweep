/*
   cliSweep v 0.1
   Mike Dank
   Circa 2008
*/

#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char Back[10][10]=
    {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
    };

char Front[10][10]=
    {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
    };


class Minesweeper
{
private:
    int x;
    int y;
    int nonmines;
public:
    Minesweeper();
    void Intro();
    void Placemines();
    void Countem();
    void Move();
    void Showboard_Front();
    void Outro();
};


Minesweeper::Minesweeper()
{
    nonmines=0;
}


void Minesweeper::Intro()
{
    cout<<" ________________________________________________________ "<<endl;
    cout<<"| Welcome to Minesweeper                                 |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|  * Type coordinates when prompted                      |"<<endl;
    cout<<"|  * Coordinates go from top to bottem                   |"<<endl;
    cout<<"|  * If you hit a mine, you die                          |"<<endl;
    cout<<"|  * Do not uncover coordinates you think are mines      |"<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"| Good luck                                              |"<<endl;
    cout<<"|________________________________________________________|"<<endl;
    cout<<endl;
    system("pause");
    system("cls");

}

void Minesweeper::Placemines()
{
    for(int mines=0;mines<10;mines++)
    {
        int x=rand()%9;
        int y=rand()%9;

        if (Back[x][y]=='*')
        {            
            mines--;
        }
        else
        {
            Back[x][y]='*';
        }
    }
}

void Minesweeper::Countem()
{
    for (int a=0;a<10;a++)
    {
        for (int b=0;b<10;b++)
        {
            if(Back[a][b]!='*')
            {
                int temp=0;
                
                
                if (a==0 && b==0)
                {
                    
                    if (Back[a+1][b]=='*')
                        temp++;
                    if (Back[a+1][b+1]=='*')
                        temp++;
                    if (Back[a][b+1]=='*')
                        temp++;

                }
                else if (a==0 && b==9)
                {
                    
                    if (Back[a][b-1]=='*')
                        temp++;
                    if (Back[a+1][b-1]=='*')
                        temp++;
                    if (Back[a+1][b]=='*')
                        temp++;

                }
                else if (a==9 && b==9)
                {
                    
                    if (Back[a-1][b]=='*')
                        temp++;
                    if (Back[a-1][b-1]=='*')
                        temp++;
                    if (Back[a][b-1]=='*')
                        temp++;

                }
                else if (a==9 && b==0)
                {
                    
                    if (Back[a-1][b]=='*')
                        temp++;
                    if (Back[a-1][b+1]=='*')
                        temp++;
                    if (Back[a][b+1]=='*')
                        temp++;

                }                                
                else if(a==0)
                {
                    if (Back[a][b-1]=='*')
                        temp++;
                    if (Back[a][b+1]=='*')
                        temp++;
                    if (Back[a+1][b-1]=='*')
                        temp++;
                    if (Back[a+1][b+1]=='*')
                        temp++;
                    if (Back[a+1][b]=='*')
                        temp++;

                }
                else if(a==9)
                {
                    if (Back[a][b-1]=='*')
                        temp++;
                    if (Back[a][b+1]=='*')
                        temp++;
                    if (Back[a-1][b-1]=='*')
                        temp++;
                    if (Back[a-1][b+1]=='*')
                        temp++;
                    if (Back[a-1][b]=='*')
                        temp++;

                }
                else if(b==0)
                {
                    if (Back[a-1][b]=='*')
                        temp++;
                    if (Back[a+1][b]=='*')
                        temp++;
                    if (Back[a-1][b+1]=='*')
                        temp++;
                    if (Back[a+1][b+1]=='*')
                        temp++;
                    if (Back[a][b+1]=='*')
                        temp++;

                }
                else if(b==9)
                {

                    if (Back[a-1][b]=='*')
                        temp++;
                    if (Back[a+1][b]=='*')
                        temp++;
                    if (Back[a-1][b-1]=='*')
                        temp++;
                    if (Back[a+1][b-1]=='*')
                        temp++;
                    if (Back[a][b-1]=='*')
                        temp++;

                }
                else
                {
                
                    if (Back[a-1][b]=='*')
                        temp++;
                    if (Back[a][b-1]=='*')
                        temp++;
                    if (Back[a-1][b-1]=='*')
                        temp++;
                    if (Back[a+1][b+1]=='*')
                        temp++;
                    if (Back[a-1][b+1]=='*')
                        temp++;
                    if (Back[a+1][b-1]=='*')
                        temp++;
                    if (Back[a+1][b]=='*')
                        temp++;
                    if (Back[a][b+1]=='*')
                        temp++;
                }
                    temp=temp+48;
                    Back[a][b]=temp;

                
            }
        }
    }


}



void Minesweeper::Move()
{
    Showboard_Front();

    cout<<"Please enter a row number (0-9)";
    cin>>x;
    if (x>9 || x<0)
    {
        cout<<"Please enter a number between 1 and 10"<<endl;
        system("pause");
        system("cls");
        Move();
    }
    cout<<"Please enter a columm number (0-9)";
    cin>>y;
    if (y>9 || y<0)
    {
        cout<<"Please enter a number between 1 and 10"<<endl;
        system("pause");
        system("cls");
        Move();
    }

if (Front[x][y]==Back[x][y])
{
    system("cls");
    Move();
}
else
{
    Front[x][y]=Back[x][y];
    nonmines++;
    system("cls");
}


if (Back[x][y]=='*' || nonmines>=90)
{
    Outro();
}
else
Move();

}


void Minesweeper::Showboard_Front()
{
    for (int a=0;a<10;a++)
    {
        for (int b=0;b<10;b++)
        {
            cout<<Front[a][b]<<" ";
        }
        cout<<endl;
    }

}

void Minesweeper::Outro()
{
    for (int a=0;a<10;a++)
    {
        for (int b=0;b<10;b++)
        {
            cout<<Back[a][b]<<" ";
        }
        cout<<endl;
    }


    cout<<"Thank you for playing minesweeper"<<endl;
    if (nonmines==90)
    {
        cout<<"You have beat the game"<<endl;
    }
    else
    {
        cout<<"You have hit a mine and died"<<endl;
    }

    cout<<endl<<"Thanks for playing"<<endl;

}

int main()
{
    srand(time(0));
    Minesweeper thisgame;
      thisgame.Intro();
    thisgame.Placemines();
    thisgame.Countem();
    thisgame.Move();
    return 0;
}