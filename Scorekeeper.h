//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 2
//  Description: Header file for Scorekeeper.cpp and Driver.cpp
//  Filename: Scorekeeper.h
//  Last modified on: 9/25/12

#ifndef _Scorekeeper_h
#define _Scorekeeper_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_GAMES = 10;
const int NUM_PLAYERS = 20;

bool getValidChoice(void);
//PRE: User is prompted to enter 'y' or 'n' for yes or no
//POST: Valid bool is returned representing true for yes and false for no,
//      if invalid data, function loops until valid data is entered

void enterGame(int score_keep[][NUM_PLAYERS], int &game_count);
//PRE: User decides to enter a game, the game count is passed
//POST: User's games have been imported into the array
//PARAM: 

void importGame(int score_keep[][NUM_PLAYERS], int &game_count);
//PRE: User decides to import a game, the number game is passed
//POST: User's scores have been entered for the correct number of players

void retrieveScores(int score_keep[][NUM_PLAYERS], int game_count);
//PRE: User decides to retrieve a particular player's score
//POST: User's desired scores are displayed 

void printAllScores(int score_keep[][NUM_PLAYERS], int game_count);
//PRE: Games have been entered and array and game_count are passed in
//POST: All games and players are printed 

void printToFile(int score_keep[][NUM_PLAYERS], int game_count);
//PRE: Games have been entered and array and game_count are passed in
//POST: All games and players are printed to file "scores.txt" 

int getValidPlayers(void);
//PRE: User is prompted to enter the number of players as an integer
//POST: Valid number of players is returned, if invalid data, function
//      loops until valid data is entered

int getValidGames(void);
//PRE: User is prompted to enter the number of games as an integer
//POST: Valid number of games is returned, if invalid data, function
//      loops until valid data is entered

int getPlayerNumber(void);
//PRE: User is prompted to enter the specific player number or 0 for all
//POST: Valid player number is returned, if invalid data, function
//      loops until valid data is entered

int getValidScore(void);
//PRE: User is prompted to enter the score for a player as an integer
//POST: Valid score is returned, if invalid data, function
//      loops until valid data is entered

int getValidGameNumber(int game_count);
//PRE: User is prompted to enter the game number as an integer
//POST: Valid game number is returned, if invalid data, function
//      loops until valid data is entered

int getMenuNav(void);
//PRE: User is prompted to enter the int for where to navigate
//POST: Valid navigation int is returned, if invalid data, function
//      loops until valid data is entered


#endif
