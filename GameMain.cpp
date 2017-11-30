//===========================================================================
// GameMain.cpp
//
// 
// Author: Layiwola Tobi
//===========================================================================
#include <iostream>
#include <string.h>
#include "GameGraph.h"

#define DataFile "gamelayout.txt"

void makeUpper(char *line);

int main(int argc, char **argv)
{
	GameGraph	*game;
	bool		done = false;
	char		command[64];

	game = new GameGraph();

	cout << "Welcome to Program Assignment 4 for CS 221.\n";
	// Add your name in the line below
	cout << "Programming by: YOUR NAME HERE\n";
	cout << "This is a Dungeons and Dragons style role \n";
	cout << "playing game.  At the prompt enter enter your commands.\n\n";

	game->LoadGame(DataFile);	// Load the game
 
	while(!done)
	{
		cout << "\n\nWhat do you want to do?  ";
		cin.getline(command, 64, '\n');
		makeUpper(command);
		if((game->doCommand(command))) // If doCommand returns true end game
			done = true;
	}
	return 0;
}

//--------------------------------------
// makeUpper()
// Converts input line to all upper case
//--------------------------------------
void makeUpper(char *line)
{
	char *temp;

	temp = line;
	while(*temp != '\0') 
	{
		*temp = toupper(*temp);
		temp++;
	}
}
