#include <iostream>
#include <stdlib.h>

using namespace std;

// Row then column
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int choice, row, column;
char turn = 'X'; //Start with player 1's turn
bool draw = false;

//Display each square of the board, each number signifies a tile
void displayBoard(){
    cout<<"\tPLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"\t\t_____|_____|_____\n";   
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"\t\t_____|_____|_____\n";   
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
    cout<<"\t\t     |     |     \n";
}


//Handle the players input
void playerTurn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn =='O'){
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }
    //Take input to get which tile the user wants to go in
    cin >> choice;

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    //Ensure the move is legal (the square is equal to a number char, not an X or O)
    if(board[row][column] == 'X' || board[row][column] == 'O'){
        cout<<"Tile is already full, please select another move\n";
        //Redo the player's turn
        playerTurn();
    }

    if(turn == 'X'){
        board[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O'){
        board[row][column] = 'O';
        turn = 'X';
    }
}

bool gameOver(){
    //Index through each row
    for(int i = 0; i < 3; i++){
        //Check for a win horizontally
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return true; //True the game is over, there is a winner
        }
        //Check for a win vertically
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return true;
        }
        //Check both diagonals
    }
    
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])){
        return true;
    }
    //Check to continue or not, (FULL BOARD)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' || board[i][j] != 'O'){
                return false;
            }
        }
    }
    //If no value is returned, the board is full, there is a draw
    draw = true;
    return true;
}

int main(){
    cout<<"\t\t TIC TAC TOE";
    cout<<"\n\tFOR 2 PLAYERS";
    while(!gameOver()){
        displayBoard();
        playerTurn();
        gameOver();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\nCONGRATULATIONS! Player 1 has won"<<endl;
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\nCONGRATULATIONS! Player 2 has won"<<endl;
    }
    else{
        cout<<"\n\nDRAW"<<endl;
    }
    return 0;
}