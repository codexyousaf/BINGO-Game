#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<algorithm>
#include<random>
using namespace std;

int const row=5;
int const col=5;

// Function to  print the bingo board for player 1
void player1(int board1[row][col])
{
     shuffle(&board1[0][0],&board1[0][0]+25,default_random_engine(time(0)));
     // Print the board for player 1
     for ( int i=0 ; i<5 ; i++ )
    {
        cout<<"\t|";
        for ( int j=0 ; j<5 ; j++ )
        {
            if(board1[i][j]<10)
                cout<<"  "<<board1[i][j]<<" ";
            else
                cout<<" "<<board1[i][j]<<" ";
        }
        cout<<"|";
        cout<<endl;

    }
}

// Function to  print the bingo board for player 2
void player2(int board2[row][col])
{
     shuffle(&board2[0][0],&board2[0][0]+25,default_random_engine(time(0)));
     // Print the board for player 2
     for ( int i=0 ; i<5 ; i++ )
    {
        cout<<"\t|";
        for ( int j=0 ; j<5 ; j++ )
        {
            if(board2[i][j]<10)
                cout<<"  "<<board2[i][j]<<" ";
            else
                cout<<" "<<board2[i][j]<<" ";
        }
        cout<<"|";
        cout<<endl;

    }
}

//Function in order to check rows of player1
bool checkRows1(int board1[row][col],int cout1[],string name1[])
{
    int n=0;
    for( int i=0 ; i<row ; i++)
    {
        n=0;
       for( int j=0 ; j<col ; j++)
       {
           if ( board1[i][j] == 0)
              n++;
        }
        if(n==5)
        {
            name1[0]="ROW";
            cout1[0]=i+1;
            return true;
        }
    }
    return false;
}
//Function in order to check column of player 1 board
bool checkCols1(int board1[row][col],int count1[],string name1[])
{
    int n=0;
    for(int i=0 ;i<col;i++)
    {
        n=0;
        for(int j=0;j<row;j++)
        {
            if(board1[j][i]==0)
                n++;
        }
        if(n==5)
        {
            name1[0]="COLUMN";
            count1[0]=i+1;
            return true;
        }
    }
    return false;
}
//Function in order to check rows of player 2 board
bool checkRows2(int board2[row][col],int count2[],string name2[])
{
    int n=0;
    for( int i=0 ; i<row ; i++)
    {
        n=0;
       for( int j=0 ; j<col ; j++)
       {
           if ( board2[i][j] == 0)
               n++;
       }
        if(n==5)
        {
            name2[0]="ROW";
            count2[0]=i+1;
            return true;
        }
    }
    return false;
}
//Function in order to check columns of player2 board
bool checkCols2(int board2[row][col],int count2[],string name2[])
{
    int n=0;
    for(int i=0 ;i<col;i++)
    {
        n=0;
        for(int j=0;j<row;j++)
        {

            if(board2[j][i]==0)
                n++;
        }
        if(n==5)
        {
            name2[0]="COLUMN";
            count2[0]=i+1;
            return true;
        }
    }
    return false;
}
//Function in order to check Diagonals of player 1 board
bool checkDiagonals1(int board1[row][col],int count1[],string name1[])
{
    int n=0;

    for(int i=0;i<row;i++)
    {
        if(board1[i][i]==0)
           n++;
    }
    if(n==5)
    {
        count1[0]=1;
        name1[0]="DIAGONAL";
        return true;
    }
    return false;
}
//Function in order to check diagonal of player2 board
bool checkDiagonals2(int board2[row][col],int count2[],string name2[])
{
    int n=0;
    for(int i=0;i<row;i++)
    {
        if(board2[i][i]==0)
            n++;
    }
    if(n==5)
    {
        count2[0]=1;
        name2[0]="DIAGONAL";
        return true;
    }
    return false;
}
//Function in order to check antiDiagonals of player1 board
bool checkAntiDiagonals1(int board1[row][col],int count1[],string name1[])
{
    int n=0;
    for(int i=0;i<row;i++)
    {
        if(board1[i][row-1-i]==0)
            n++;
    }
    if(n==5)
    {
        count1[0]=1;
        name1[0]="ANTI DIAGONAL";
        return true;
    }
    return false;
}
//Function in order to check diagonals of player two board
bool checkAntiDiagonals2(int board2[row][col],int count2[],string name2[])
{
    int n=0;
    for(int i=0;i<row;i++)
    {
        if(board2[i][row-1-i]==0)
            n++;
    }
    if(n==5)
    {
        count2[0]=1;
        name2[0]="ANTI DIAGONAL";
        return true;
    }
    return false;
}
//Main function
int main()
{
    cout << "        | *****  *****  *      *  *****  *****| \n";
    cout << "        | *   *    *    * *    *  *      *   *| \n";
    cout << "--------| *****    *    *   *  *  * * *  *   *|-------\n";
    cout << "        | *   *    *    *    * *  *   *  *   *|\n";
    cout << "        | *****  *****  *      *  *****  *****| \n";
    cout << endl;
    cout<<"-----RULES-----";
    cout<<"\n 1.In this game player has to press the ENTER button and it will generate a random number between 1-25.";
    cout<<"\n 2.If a player forms a line (horizontal, vertical, or diagonal) they will win and the game ends.";
    cout<<"\n 3.The process repeats until one of the players achieves 'BINGO!'.";
    cout<<"\n 4.If both of the players achieve a straight line of X the game will be TIED.";
    cout<<"\n 5.The first player to form any one complete line is declared the winner.\n";
    bool checkR1,checkC1,checkD1,checkAD1;
    bool checkR2,checkC2,checkD2,checkAD2;
    int  num,i;
    int count1[1]={0};
    int count2[1]={0};
    string name1[1],name2[1];


   string end="ABC";
   int board1[row][col]={{1,2,3,4,5,},{6,7,8,9,10,},{11,12,13,14,15,},{16,17,18,19,20,},{21,22,23,24,25,}};
   int board2[row][col]={{25,24,23,22,21},{20,19,18,17,16},{15,14,13,12,11},{10,9,8,7,6},{5,4,3,2,1}};
   srand(time(0));
      cout << "\n\t Player 1's Board:" << endl;
      cout<<endl;
      cout<<"\t-----------------------" << endl;
      player1(board1);
      cout<<"\t-----------------------" << endl;
      cout<<"\t Player 2's Board:" << endl;
      cout<<endl;
      cout<<"\t-----------------------" << endl;
      player2(board2);
      cout<<"\t-----------------------";
      num=(rand()%25+1);


//Game loop
    while(end!="BINGO")
    {
        cout<<"\n\t press enter to continue the game:";
        cin.get();
        i=num;
        cout<<"\n\t The new number generated is : "<<i;
        cout<<"\n\t Player 1 board:\n";
        cout<<"\t----------------------"<< endl;
      for(int i=0;i<5 ;i++)
      {
          cout<<"\t|";
        for( int j=0 ; j<5 ; j++)
        {
            if(board1[i][j]==num)
            {
                board1[i][j]=0; // Mark the number as called
            }
            if(board1[i][j]==0)
                cout<<"  X ";
            else if (board1[i][j]<10)
                cout<<"  "<< board1[i][j]<<" ";
            else
                cout<<" "<< board1[i][j]<<" ";
        }
        cout<<"|";
        checkR1=checkRows1(board1,count1,name1);
        checkC1=checkCols1(board1,count1,name1);
        checkD1=checkDiagonals1(board1,count1,name1);
        checkAD1=checkAntiDiagonals1(board1,count1,name1);
        cout<<"\n";
     }
    cout<<"\t----------------------" << endl;
    cout<<"\n\t Player 2 board:\n";
    cout<<"\t----------------------" << endl;
    for(int i=0;i<5 ;i++)
      {
          cout<<"\t|";
        for( int j=0 ; j<5 ; j++)
        {
            if(board2[i][j]==num)
            {
                board2[i][j]=0; // Mark the number as called
            }
            if(board2[i][j]==0)
                cout<<"  X ";
            else if (board2[i][j]<10)
                cout<<"  "<< board2[i][j]<<" ";
            else
                cout<<" "<< board2[i][j]<<" ";
        }
        cout<<"|";
        checkR2=checkRows2(board2,count2,name2);
        checkC2=checkCols2(board2,count2,name2);
        checkD2=checkDiagonals2(board2,count2,name2);
        checkAD2=checkAntiDiagonals2(board2,count2,name2);
        cout<<"\n";
      }
      cout<<"\t----------------------" << endl;
       while(num==i)
             num=(rand()%25+1);

    if( (checkR1==true || checkC1==true || checkD1==true || checkAD1==true) && (checkR2==true || checkC2==true || checkD2==true || checkAD2==true))
    {
          cout<<"\t\n"<<name1[0]<<" "<<count1[0]<<" of player 1 board has completed.";
          cout<<"\t\n"<<name2[0]<<" "<<count2[0]<<" of player 2 board has completed";
          cout<<"\n\t GAME TIED";
          end="BINGO";
    }
    else if(checkR1==true || checkC1==true || checkD1==true || checkAD1==true )
    {
        end="BINGO";
        cout<<"\n"<<name1[0]<<" "<<count1[0]<<" of player 1 board has completed.";
        cout<<"\n\t-----BINGO-----";
        cout<<"\n\t Player 1 has won the game";
    }
    else if(checkR2==true || checkC2==true || checkD2==true || checkAD2==true )
    {
        end="BINGO";
        cout<<"\n"<<name2[0]<<" "<<count2[0]<<" of player 2 board has completed";
        cout<<"\n\t-----BINGO-----";
        cout<<"\n\t Player 2 has won the game";
    }


    }

return 0;
}

