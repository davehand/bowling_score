//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 2
//  Description: Function file for Driver.cpp
//  Filename: Scorekeeper.cpp
//  Last modified on: 9/25/12

#include "Scorekeeper.h"

//gets valid yes or no in boolean form
bool getValidChoice(void)
{
    bool tryAgain = true;
    bool choice = false;
    char value;
    
    while (tryAgain)
    {
        cin >> value;
        
        //ensures good value is read
        if ((cin.fail()) || !((tolower(value) == 'y') || (tolower(value) == 'n')))
        {
            cout << "Invalid input - Please enter a character value (y/n): " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            tryAgain = false;
    }
    
    //converts y/n to boolean
    if (tolower(value) == 'y')
        choice = true;
    
    return choice;
}

//allows user to enter game data
void enterGame(int score_keep[][NUM_PLAYERS], int &game_count)
{
    //checks that max number of games has not been entered yet
    if (game_count < 10)
    {
        int num_players = 0;
        
        //gets number of players
        cout << endl << "Please enter the number of players: " << endl;
        num_players = getValidPlayers();
        
        //enter score for each player
        for (int i = 0; i < num_players; i++)
        {
            cout << "Please enter the score for player " << (i+1) << ":" << endl;
            score_keep[game_count][i] = getValidScore();
        }
        game_count++;
    }
    else
        cout << "The maximum number of games has been entered." << endl << endl;
    
    return;
}

//allows user to import game data
void importGame(int score_keep[][NUM_PLAYERS], int &game_count)
{
    int num_games = 0, score = 0, player = 0;
    bool tryAgain = true, quickexit = true;
    ifstream inFile;
    string filename;
    
    cout << "Please enter the file name with the .txt appended: " << endl;
    
    //gets filename and checks that file exists, allows user to exit as well
    while (tryAgain)
    {
        cin >> filename;
        
        if (filename.compare("exit") != 0)
        {
            inFile.open(filename.c_str());
        
            if (inFile.fail())
            {
                cout << "Please try a different file name with .txt appended: " << endl;
                cout << "If there is no input file, type \"exit\" to enter a game manually." << endl;
            }
            else
            {
                cout << "Please enter the number of games to import: " << endl;
                num_games = getValidGames();
                tryAgain = false;
            }
        }
        else
        {
            tryAgain = false;
            quickexit = false;
            enterGame(score_keep, game_count);
        }
    }
    
    //imports data from file
    while ((game_count < num_games) && quickexit)
    {
        inFile >> score;
        
        //increases game count if score is -1
        if (score == -1)
        {
            game_count++;
            player = 0;
        }
        else
        {
            //checks to make sure no more than 20 players played
            if (player < 20)
            {
                score_keep[game_count][player] = score;
                player++;
            }
        }
    }
    
    return;
}

//retrieves user specified scores
void retrieveScores(int score_keep[][NUM_PLAYERS], int game_count)
{
    int game = 0, player = 0;
    bool doAgain = true;
    
    while (doAgain)
    {
        //gets game number to view
        cout << endl << "What game would you like to view?" << endl;
        game = getValidGameNumber(game_count)-1;
        
        //gets player number to view
        cout << "What player would you like to view (you can view all by entering 0)?" << endl;
        player = getPlayerNumber()-1;
        
        //prints all player scores if user entered 0
        if (player == -1)
        {
            int i = 0;
            while ((score_keep[game][i] != -1) && (i < 20))
            {
                cout << "Player " << (i+1) << ": " << score_keep[game][i] << endl;
                i++;
            }
        }
        //prints specified player's score
        else
        {
            if (score_keep[game][player] == -1)
                cout << "There weren't this many players. Try again in the loop." << endl;
            else
            {
                cout << "Game " << (game+1) << endl;
                cout << "Player " << (player+1) << ": " << score_keep[game][player] << endl;
            }
        }
        
        //prompts the user if they would like to retrieve another score
        cout << "Would you like to view another game (y/n)?" << endl;
        doAgain = getValidChoice();
    }
    return;
}

//prints the score of every player for every game to the command line
void printAllScores(int score_keep[][NUM_PLAYERS], int game_count)
{
    int count = 0;
    cout << endl;
    
    //prints each game number and each player's score
    while (count < game_count)
    {
        int player = 0;
        cout << "Game " << (count+1) << endl;
        
        while ((score_keep[count][player] != -1) && (player < 20))
        {
            cout << "Player " << (player+1) << ": " << score_keep[count][player] << endl;
            player++;
        }
        cout << endl;
        count++;
    }
    
    return;
}

//prints the score of every player for every game to a file "scores.txt"
void printToFile(int score_keep[][NUM_PLAYERS], int game_count)
{
    int count = 0;
    ofstream outFile;
    outFile.open("scores.txt");
    
    //prints scores to "scores.txt"
    while (count < game_count)
    {
        int player = 0;
        outFile << "Game " << (count+1) << endl;
        
        while ((score_keep[count][player] != -1) && (player < 20))
        {
            outFile << "Player " << (player+1) << ": " << score_keep[count][player] << endl;
            player++;
        }
        outFile << endl;
        count++;
    }
                                                                     
    return;
}

//gets a valid number of players
int getValidPlayers(void)
{
    bool tryAgain = true;
    int value;
    
    //reads in value and repeats until valid data entered
    while (tryAgain)
    {
        cin >> value;
        
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer value: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((value < 1) || (value > 20))
            cout << "Invalid input - Please enter a value between 1-20: " << endl;
        else
            tryAgain = false;
    }
    
    return value;
}

//gets a valid number of games
int getValidGames(void)
{
    bool tryAgain = true;
    int value;
    
    //reads in value and repeats until valid data entered
    while (tryAgain)
    {
        cin >> value;
        
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer value: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((value < 1) || (value > 10))
            cout << "Invalid input - Please enter a value between 1-10: " << endl;
        else
            tryAgain = false;
    }
    
    return value;
}

//gets a valid player number
int getPlayerNumber(void)
{
    bool tryAgain = true;
    int value;
    
    //reads in value and repeats until valid data entered
    while (tryAgain)
    {
        cin >> value;
        
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer value: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((value < 0) || (value > 20))
            cout << "Invalid input - Please enter a value between 0-20: " << endl;
        else
            tryAgain = false;
    }
    
    return value;
}

//gets a valid final score for a player
int getValidScore(void)
{
    bool tryAgain = true;
    int value;
    
    //reads in value and repeats until valid data entered
    while (tryAgain)
    {
        cin >> value;
        
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer value: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((value < 0) || (value > 300))
            cout << "Invalid input - Please enter a value between 0-300: " << endl;
        else
            tryAgain = false;
    }
    
    return value;
}

//gets a valid game number
int getValidGameNumber(int game_count)
{
    bool tryAgain = true;
    int value;
    
    //reads in value and repeats until valid data entered
    while (tryAgain)
    {
        cin >> value;
        
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer value: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((value < 1) || (value > game_count))
            cout << "Invalid input - Please enter a value for a game played: " << endl;
        else
            tryAgain = false;
    }
    
    return value;
}

//gets a valid menu navigation number
int getMenuNav(void)
{
    bool tryAgain = true;
    int value;
    
    //reads in value and repeats until valid data entered
    while (tryAgain)
    {
        cin >> value;
        
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer value: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((value < 1) || (value > 4))
            cout << "Invalid input - Please enter a value between 1-4: " << endl;
        else
            tryAgain = false;
    }
    
    return value;
}
