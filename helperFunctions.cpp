#include <iostream>
#include <string>

#include "helperFunctions.h"

using namespace std;

//Global variables for representing the game board
const int COLS = 7;
const int ROWS = 6;
char board[COLS][ROWS]; //2D array of 7x6

//Global constants for game pieces
const char EMP = '-';
const char P1 = 'X';
const char P2 = 'O';


void initializeBoard() {
  for (int c = 0; c < COLS; c++) {
    for (int r = 0; r < ROWS; r++) {
        board[c][r] = EMP;
    }
  }
}

void displayBoard() {
  cout << endl <<  "Connect 4 Board:" << endl;
  //Display board one row at a time
  for (int r = 0; r < ROWS; r++) {
    //For each row display all of the columns
    for (int c = 0; c < COLS; c++) {
      cout << board[c][r] << " ";
    }
    //After each row output newline character
    cout << endl;
  }
  for (int c = 0; c < COLS; c++) {
      cout << c << " ";
  }
  cout << endl << endl;
}

bool addPiece(int c, bool isPlayer1) {
  //check if column c is full
  if (board[c][0] != EMP) {
    return false;
  } else {
    //add piece to lowest unoccupied slot in column c
    for (int r = (ROWS-1); r >= 0; r--) {
        if (board[c][r] == EMP) {
          if (isPlayer1) {
            board[c][r] = P1;
          }
          else {
            board[c][r] = P2;
          }
          break;
        }
    }
    return true;
  }
}

bool isWinner(bool player) {
    //Variable to poistion on board of the player
    char currTile;
    if (player){
        currTile = P1;
    }else{
        currTile = P2;
    }
    //Check if current player has 4 pieces horizontally
    for (int r = 0; r < ROWS; r++){
        //reset counter to zero for each row
        int counter = 0; 
        for (int c = 0; c < COLS; c++) {
            if(board[c][r] == currTile) {
                counter++;
            }else {
                counter = 0;
            }
            //Game win conditional statement
            if (counter == 4){
                return true;
            }
        }
    }
    //Check if current player has 4 pieces vertically
    for (int c = 0; c < COLS; c++){//itterate over each index
        int counter = 0; //reset counter to zero for each column
        for (int r = 0; r < ROWS; r++){
            if(board[c][r] == currTile){
                counter++;
            }else{ //if not in a row, restart counter for that same column
                counter = 0;
            }
            //Game win conditional statement
            if (counter == 4){
                return true; 
            }
        }
    }
    //Check if current player has 4 pieces diagonally (top left to bottom right)
    for (int r = 0; r < ROWS; r++){ //itterate over every index
        for (int c=0; c < COLS;c++){
            int counter=0;
            //for each index, loop through 4 diagonal indexes. If all 4 are the same player, the player won
            for (int i=0;i<4;i++){
                if (board[c+i][r+i]==currTile &&(r+i)<ROWS&&(c+i)<COLS){
                    counter=counter+1;
                }
            }
            //Game win conditional statement
            if (counter==4){
                return true;
            }

        }
    }

    //Check if current player has 4 pieces diagonally (bottom left to top right)
    for (int r = 0; r < ROWS; r++){
        for (int c=0; c < COLS;c++){
            int counter=0;
            //Check each index for the 4 diagonal indexes. If all 4 are the same player's game piece, then the player has won
            for (int i=0;i<4;i++){ 
                if (board[c+i][r-i]==currTile &&(r-i)>0&&(c+i)<COLS)
                {
                    counter=counter+1;
                }
            }
            //Game win conditional statement
            if (counter==4)
            {
                return true;
            }

        }
    }
}