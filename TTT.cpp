#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

void clearscreen(){
     #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void displayboard(char board[3][3], int selectedRow, int selectedCol){
    for(int row=0; row<3; row++ ){
    for(int col=0; col<3;col++){
        if(row==selectedRow && col ==selectedCol){
        cout<<"["<<board[row][col]<<"]";}
        else{
        cout<<" "<<board[row][col]<<" ";}
        if(col<2){ cout<<"|";}
        }
    cout<<endl;
    if (row<2){
    cout<<"-------------"<<endl;}
}
}

int main(){

char board[3][3]={ 
    {' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

char player='X';
int selectedRow=0;
int selectedCol=0;


while(true)
{
    clearscreen();

    cout << "Use arrow keys to move. Press Enter to stop.\n";
    cout << "Player " << player<<endl;

    displayboard(board, selectedRow, selectedCol);

    int key = _getch();

    if(key == 0 || key == 224)
    {
        key = _getch();

        if(key == 72 && selectedRow > 0)
        {
            selectedRow--;
        }
        else if(key == 80 && selectedRow < 2)
        {
            selectedRow++;
        }
        else if(key == 75 && selectedCol > 0)
        {
            selectedCol--;
        }
        else if(key == 77 && selectedCol < 2)
        {
            selectedCol++;
        }
    }
    else if(key == 13)
    {
        if(board[selectedRow][selectedCol] == ' ')
        {
            board[selectedRow][selectedCol] = player;

         bool won = false;

for(int i = 0; i < 3; i++)
{
if(board[i][0]==player &&
   board[i][1]==player &&
    board[i][2]==player)
    {
        won = true;
    }
if(board[0][i] == player &&
board[1][i] == player &&
 board[2][i] == player)
    {
        won = true;
    }
}

if(board[0][0] == player &&
   board[1][1] == player &&
   board[2][2] == player)
{
 won = true;
}


if(board[0][2] == player &&
   board[1][1] == player &&
   board[2][0] == player)
{
won = true;
}
if(won){
    clearscreen();
    cout<<"PLAYER"<<player<<endl;
   displayboard(board, selectedRow, selectedCol);
    cout<<"player: "<<player<<"  wins"<<endl;
    break;
}

bool full=true;
for(int row=0; row <3; row++){
    for(int col=0; col<3; col++){
        if(board[row][col]==' ')
        {
            full=false;
            break;
        } }
    }
    if(full){cout<<"it is draw!"<<endl;
        break;
}
if(player=='X'){player='O';}
else{player='X';}
        }
        else
        {
            cout << "That cell is already taken! Press any key to try again.\n";
            _getch();
        }
    }
}
}

