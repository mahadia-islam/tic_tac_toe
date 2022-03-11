#include <iostream>

using namespace std;

// game is running or not

bool game_still_going = true;

// who is winner ?

char winner = 'N';

// current player

char player = 'X';

// array for board layout

char board[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};

void display_board(){
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// for handling turn

void handle_turn(){
    int position;
    cout << "\nNow " << player << " turn\n" << endl;
    cout << "Enter any number into 1 to 9 : ";
    cin >> position;
    if(board[position - 1] != '_'){
        cout << "The position is already filled !!\n";
    }else{
        board[position - 1] = player;
    }
    display_board();
}

// player changer

void flip_player(){
    if(player == 'X'){
        player = 'O';
    }else{
        player = 'X';
    }
}

// check the row

char check_row()
{
    bool row1 = (board[0] == board[1]) && (board[1] == board[2]) && board[0] != '_';
    bool row2 = (board[3] == board[4]) && (board[4] == board[5]) && board[3] != '_';
    bool row3 = (board[6] == board[7]) && (board[7] == board[8]) && board[6] != '_';
    if (row1)
    {
        return board[0];
    }
    else if (row2)
    {
        return board[3];
    }
    else if (row3)
    {
        return board[6];
    }
    else{
        return 'N';
    }
}

// check the column

char check_column()
{
    bool column1 = (board[0] == board[3]) && (board[3] == board[6]) && board[0] != '_';
    bool column2 = (board[1] == board[4]) && (board[4] == board[7]) && board[1] != '_';
    bool column3 = (board[2] == board[5]) && (board[5] == board[8]) && board[2] != '_';
    if (column1)
    {
        return board[0];
    }
    else if (column2)
    {
        return board[1];
    }
    else if (column3)
    {
        return board[2];
    }
    else{
        return 'N';
    }
}

// check diagonal

char check_diagonal()
{
    bool diagonal1 = (board[0] == board[4]) && (board[4] == board[8]) && board[0] != '_';
    bool diagonal2 = (board[2] == board[4]) && (board[4] == board[6]) && board[2] != '-';
    if (diagonal1)
    {
        return board[0];
    }
    else if (diagonal2)
    {
        return board[2];
    }
    else{
        return 'N';
    }
}

// check if anyone is winner

void check_if_win(){
    char row_winner = check_row();
    char column_winner = check_column();
    char diagonal_winner = check_diagonal();
    if(row_winner == 'X' || row_winner == 'O')
    {
        winner = row_winner;
        game_still_going = false;
    }else if(column_winner == 'X' || column_winner == 'O')
    {
        winner = column_winner;
        game_still_going = false;
    }
    else if (diagonal_winner == 'X' || column_winner == 'O')
    {
        winner = diagonal_winner;
        game_still_going = false;
    }
}

// check if the board is full

void check_if_tie(){
    int dash_count = 0;
    for (int i = 0; i < sizeof(board); i++)
    {
        if(board[i] == '_'){
            dash_count++;
        }
    }
    if(dash_count == 0){
        game_still_going = false;
    }
}

// check if the game is over

void check_if_game_over(){
    check_if_win();
    check_if_tie();
}

void play_game(){
    while(game_still_going){

        handle_turn();
        check_if_game_over();
        flip_player();
    }
    // the game has ended there
    if(winner == 'N'){
        cout << "Tie." << endl;
    }else{
        cout << "The winner is " << winner << endl;
    }
}

int main(){
    play_game();
    return 0;
}