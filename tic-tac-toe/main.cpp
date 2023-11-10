#include <iostream>
using namespace std;

char turn= 'X';
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int rows,column;
bool draw=false;
void show_board()
{
    system("Cls");
    cout << "\t\tTIC-TAC-TOE GAME:"<<endl<<endl;
    cout << "PLAYER1 [X]"<<endl;
    cout << "PLAYER2 [O]"<<endl<<endl;

    cout << "\t\t     |     |     \n";
    cout << "\t\t"<<board[0][0]<< "    | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t-----|-----|-----\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t"<<board[1][0]<< "    | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t-----|-----|-----\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t"<<board[2][0]<< "    | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t     |     |     \n\n";
}

void player_turn()
{
    int choice;

    if(turn == 'X')
        cout<<"\n\tPLAYER1 [X] turn:";


    if(turn == 'O')
        cout<<"\n\tPLAYER1 [O]turn:";
        cin>>choice;
    switch(choice)
{
 case 1:rows=0;column=0;break;
 case 2:rows=0;column=1;break;
 case 3:rows=0;column=2;break;
 case 4:rows=1;column=0;break;
 case 5:rows=1;column=1;break;
 case 6:rows=1;column=2;break;
 case 7:rows=2;column=0;break;
 case 8:rows=2;column=1;break;
 case 9:rows=2;column=2;break;

 default:
    cout<<"invalid choice"<<endl;
    break;
}
 if(turn == 'X'&& board[rows][column]!='X'&&board[rows][column]!='O')
 {
     board[rows][column]='X';
     turn ='O';
 }
else if(turn == 'O'&& board[rows][column]!='X'&&board[rows][column]!='O')
 {
     board[rows][column]='O';
     turn ='X';
 }
 else
 {
     cout<<"Box already filled!\nPlease try again!!...\n";
     player_turn();
 }
 show_board();
}
bool gameover()
{

 // check win
    for (int i=0;i<3;i++)
    if(board[i][0]==board [i][1]&& board[i][0]== board[i][2]||board[0][i]==board [1][i]&&board[0][i]== board [2][i])
    return false;


if(board[0][0]== board[1][1]&& board[0][0]== board[2][2]||board[0][2]==board[1][1]&&board[2][0])
return false;

// if there is any box not filled
for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(board[i][j] != 'X'&& board[i][j] !='O')
    return true;

//draw
draw=true;
return false;
 }


int main()
{

    while(gameover())
{
    show_board();
    player_turn();
    gameover();

}

if(turn == 'X'&& draw == false)
    cout<<"PLAYER2 [O] Wins!! Congratulations\n";
else if(turn == 'O' && draw == false )
    cout<<"PLAYER1 [X] Wins!! Congratulations \n";
else
    cout << "GAMEDRAW!! \n";
    return 0;
}
