//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 2
//  Description: Driver for score keeping program for the Droll Bowling Alley
//  Filename: Driver.cpp
//  Last modified on: 9/25/12

#include "Scorekeeper.h"

int main ()
{
    int score_keep[NUM_GAMES][NUM_PLAYERS]; //create 2D array for storing scores
    int game_count = 0; //create counter to track games
    int menu = 0; //input for menu navigation
    bool choice = false, file = false; //create flags for navigating menu
    
    //instantiate array with all -1, -1 will denote field that has not been filled in
    for (int i = 0; i < NUM_GAMES; i++)
        for (int j = 0; j < NUM_PLAYERS; j++)
            score_keep [i][j] = -1;
    
    //welcome screen is displayed
    cout << endl << "Welcome to The Droll Bowling Alley." << endl;
    
    //user must first enter at least one game before accessing menu
    cout << "Would you like to enter a game (y/n): " << endl;
    choice = getValidChoice();
    
    //if user wants to enter game, enters first game then goes to menu
    if (choice)
    {    
        //check if from file or user input
        cout << "Would you like to import games from a file first (y/n): " << endl;
        file = getValidChoice();
        
        //enter/import a game
        if (file == true)
            importGame(score_keep, game_count);
        else
            enterGame(score_keep, game_count);
        
        //print text
        cout << "Now that a game has been entered, there are several options:" << endl;
        
        //loop to stay in menu until user exits
        while (menu != 4)
        {
            //prints instructions
            cout << "Enter more games (enter 1), retrieve any score (2), " <<
            "view all games/scores (3), or exit the program (4)." << endl <<
            "The results of all the games will be printed to a data file " <<
            "titled \"scores.txt\" once you exit." << endl;
            
            //gets valid menu input
            menu = getMenuNav();
            
            //launches different methods depending on menu input
            if (menu == 1)
                enterGame(score_keep, game_count);
            if (menu == 2)
                retrieveScores(score_keep, game_count);
            if (menu == 3)
                printAllScores(score_keep, game_count);
        }
        
        //prints all scores to file
        printToFile(score_keep, game_count);
        cout << "Scores have been printed to \"scores.txt\"." << endl << endl;
        
        //end program
        return 0;
    }
}