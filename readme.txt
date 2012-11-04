Name: David Hand
Course: CSC260, Section 1
Semester: Fall 2012
Instructor: Dr. Pulimood
Assignment: Assignment 2
Description: Described how the program works
Filename: readme.txt
9/25/2012

My program consists of 3 source code files: Scorekeeper.cpp, Scorekeeper.h, and Driver.cpp.

The Scorekeeper.h file describes the methods of each of the functions that the Driver calls.  The file also lays out the constants for number of games (10) and number of players for a game (20).

In the Driver, the program first instantiates a 2D array for 10 games of 20 players each.  Each array index is declared as -1, which will denote a non-existent player or game in the program.  

The user is first prompted to enter a game.  If they don't want to, the program ends.  If they do, the user is asked if the data is from a file or will be inputted manually.  If the data is from a file, importGame is called, and a specific number of games are read from the file, determined by the user.  If the data is to be entered manually, the enterGame function is called, and the first game's data is entered.  The program then enters a loop where the user can continue to enter data for games, retrieve specific data for entered games, or print the scores of all players from all games to the screen.  Once the user is done, they can exit the program.  Exiting the program causes the scores for all the games to be printed to a file "scores.txt."

Each function has its specifications as well.  getValidChoice, getValidPlayers, getValidGames, getPlayerNumber, getValidScore, getValidGameNumber, and getMenuNav all get correct data that the program can use, and throw out invalid data.  

enterGame allows the user to enter scores for each player for a specific game.  Once the correct scores for a game are entered, the game count is incremented.  If the maximum number of games (10) has already been entered, then the function informs the user and exits the function.

importGame gets a file name from the user.  Once the file name is validated, the user is asked for the number of games.  The function then imports the score for each player for each game in the file.  The file should have the each score separated by a space or new line character.  Each game should be separated by a -1.  For instance, the score line 2 3 -1 4 5 -1, is for 2 games with 2 players each and the data as follows:

Game 1:
Player 1: 2
Player 2: 3

Game 2:
Player 1: 4
Player 2: 5

retrieveScores allows the user to retrieve a specified score a for a game previously entered.  The user first enters a game number.  The user can then choose to view all scores for the game or a specific player.  The function loops if the user wants to view an additional game's score.

printAllScores allows the user to print the score of every player for every game to the screen.

printToFile is called after the user is finished entering scores.  The function creates a file "scores.txt" with the score of every player for every game.