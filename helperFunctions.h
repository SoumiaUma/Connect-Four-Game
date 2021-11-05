#pragma once
/*
 * helperFunctions.h
 * Code for calling functions belonging to helperFunctions.cpp
 */
#ifndef HELPER_F_
#define HELPER_F_

void initializeBoard();
void displayBoard();
bool addPiece(int col, bool isPlayer1);
bool isWinner(bool player);

#endif

