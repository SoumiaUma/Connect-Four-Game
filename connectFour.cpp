#include <iostream>
#include <string>

#include "helperFunctions.cpp"

using namespace std;

int main() {
    //Initialize game play
    bool PlayerOne = true;
    bool gameWon = false;
    int totalMoves = 0;
    const int MAX_MOVES = ROWS * COLS;

    initializeBoard();
    displayBoard();

    //Create a game play loop
    while ((totalMoves < MAX_MOVES) && (!gameWon)) {
        bool validMove = false;
        int columnToPlay = 0;
        //ask current player for a column until a valid move
        //is chosen
        while (!validMove) {
            cout << "Player ";
            if (PlayerOne) {
                cout << "1";
            } else {
                cout << "2";
            }
            cout << " - Select a column (0-" << (COLS-1) << ") to play: ";
            cin >> columnToPlay;
            validMove = addPiece(columnToPlay, PlayerOne);
            if (!validMove) {
                cout << "Column full. Try again." << endl;
            }
        }
        totalMoves++;
        displayBoard();
        gameWon = isWinner(PlayerOne);
        //Switch Player
        if (!gameWon){
            PlayerOne = !PlayerOne;
        }
    }
    if (gameWon) {
        cout << "Congratulations Player ";
        if (PlayerOne) {
            cout << "1";
        } else {
            cout << "2";
        }
        cout << ". You've won Connect Four!!!!" << endl;
    }
    else if (totalMoves == MAX_MOVES) {
        cout << "Game over! No moves remaining." << endl;
    }
    return 0;
}

