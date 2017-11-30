
#include <stdlib.h>
#include <string.>
#include <iostream>
#include <fstream>
#include "GameGraph.h"

using namespace std;

GameGraph::GameGraph(){

	cout << "constructor" << endl;
	m_iLocation = 0;

	char *stay = "----";

	for(int i=0; i<NUMROOMS; i++){
		for(int j=0; j<NUMROOMS; j++){
			m_cAdjMatrix[i][j] = '-';
		}
	}

}

GameGraph::~GameGraph(){

	cout << "destructor reached" << endl;

}

bool GameGraph::LoadGame(char *filename)
{

	cout << "LoadGame reached" << endl;

	char line[128];
    int link;
    bool done;

    m_InFile.open(filename, ifstream::in); 
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        return false;
    }

    done = false;
    for(int i=0; i<20; i++)
    {
        // Read room name
        getNextLine(line, 128);
        /* --- Copy room name into data structure i --- */
		strcpy(m_Rms[i].m_sRoomName,line);

        // Read room description
        getNextLine(line, 128);
        /* --- Copy room description into data structure i --- */
		strcpy(m_Rms[i].m_sRoomDesc,line);
        // Read room item
        getNextLine(line, 128);
        /* --- Copy room item name into data structure i --- */
		strcpy(m_Rms[i].m_sItemName,line);

        // Read room creature
        getNextLine(line, 128);
        /* --- Copy room creature name into data structure i --- */
		strcpy(m_Rms[i].m_sCreatureName,line);

        // Read North door
        getNextLine(line, 128);
        link = atoi(line); // Convert to room index
		if (link < 0)
		{
			
		}else
		{
			setLink(i,link,'N');
		}
        // Call function to set link in adjacency matrix

        // Read South door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
		if (link < 0)
		{
			
		}else
		{
			setLink(i,link,'S');
		}
		

        // Read East door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
		if (link < 0)
		{
			
		}else
		{
			setLink(i,link,'E');
		}

        // Read West door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
		if (link < 0)
		{
			cout << endl;
		}else
		{
			setLink(i,link,'W');
		}

        // Read up stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
		if (link < 0)
		{
			
		}else
		{
			setLink(i,link,'U');
		}

        // Read down stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
		if (link < 0)
		{
			
		}else
		{
			setLink(i,link,'D');
		}
    }

    return true;
}

bool GameGraph ::doCommand( char *cmd){

	
	int m = NULL;
	

	cout << "doCommand reached" << endl;
	/*
	char *storm = "month";
	cout << "doCommand reached" << endl;
	setLink(5,6, *storm);

	getNextLine(storm, 18);

	*/

	char cmd1[128];
	char cmd2[128];
	sscanf(cmd,"%s",cmd1);

	if(strcmp("QUIT", cmd1)==0){

		exit(EXIT_SUCCESS);
		return true;
	
	}
	else if((strcmp("TAKE", cmd1)==0)|| (strcmp("FIGHT", cmd1)==0) )
	{
		cout << "This command has not been implemented yet" << endl;
		return false;

	}
	else if (strcmp("GO", cmd1)==0)
	{
		sscanf(cmd, "%s %s", cmd1, cmd2);
		
		
		if (strcmp("NORTH", cmd2)==0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (m_cAdjMatrix[m_iLocation][i] == 'N')
				{
					
					m_iLocation = i;
					break;
					
				}
				
			}
		}

		else if(strcmp("SOUTH", cmd2)==0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (m_cAdjMatrix[m_iLocation][i] == 'S')
				{
					
					m_iLocation = i;
					break;

				}

			}
		}
		else if(strcmp("EAST", cmd2)==0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (m_cAdjMatrix[m_iLocation][i] == 'E')
				{
					
					m_iLocation = i;
					break;

				}

			}
		}
		else if(strcmp("WEST", cmd2)==0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (m_cAdjMatrix[m_iLocation][i] == 'W')
				{
					
					m_iLocation = i;
					break;

				}

			}
		}
		else if(strcmp("UP", cmd2)==0)
		{
			for (int i = 0; i < 20; i++)
			{
				
				
				if (m_cAdjMatrix[m_iLocation][i] == 'U')
				{
					
					m_iLocation = i;
					break;
				}

			}
		}
		else if(strcmp("DOWN", cmd2)==0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (m_cAdjMatrix[m_iLocation][i] == 'D')
				{
					
					m_iLocation = i;
					break;

				}

			}
		}
		else
		{
			cout << "Direction to move is not understood.\n";
			return false;
		}
		cout << endl;

		describeRoom(m_iLocation);
			
		

		
		

	}
	else
	{
		cout << "The command is not understood by this program" << endl;
	}

	return false;
}
/*
void GameGraph::PrintAll(){


	for (int i = 0; i < 20; i++)
	{

	cout << m_Rms[i].m_sCreatureName << endl;
	cout << m_Rms[i].m_sItemName << endl;
	cout << m_Rms[i].m_sRoomDesc << endl;
	cout << m_Rms[i].m_sRoomName << endl;


	}

	
	
}
*/
void GameGraph::setLink(int roomIdx, int linkIdx, char dCode){
	

	m_cAdjMatrix[roomIdx][linkIdx] = dCode;

}

void GameGraph::getNextLine(char *line, int lineLen){
	
	int    done = false;

    while(!done)
    {
        m_InFile.getline(line, lineLen);  
        // Note: m_InFile is an ifstream object that is part of the GameGraph class

        if(m_InFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return;
        }
    } // end while
}

void GameGraph::describeRoom(int roomIdx){
	//cout<< "describeRoom" << endl;
	cout << "The creature's Name is : " << m_Rms[m_iLocation].m_sCreatureName << endl;
	cout <<"The Creature's item is: " << m_Rms[m_iLocation].m_sItemName << endl;
	cout <<"The room's description is: " << m_Rms[m_iLocation].m_sRoomDesc << endl;
	cout <<"The room's location is: " << m_Rms[m_iLocation].m_sRoomName << endl << endl;

	for (int i = 0; i < 20; i++)
	{
		if (m_cAdjMatrix[m_iLocation][i] == 'N')
		{
			cout << "there is a room to the north"<< endl;
		}
		if (m_cAdjMatrix[m_iLocation][i] == 'S')
		{
			cout << "there is a room to the south"<< endl;
		}
		if (m_cAdjMatrix[m_iLocation][i] == 'W')
		{
			cout << "there is a room to the west"<< endl;
		}
		if (m_cAdjMatrix[m_iLocation][i] == 'E')
		{
			cout << "there is a room to the east"<< endl;
		}
		if (m_cAdjMatrix[m_iLocation][i] == 'U')
		{
			cout << "there is a room to the UP stairs"<< endl;
		}
		if (m_cAdjMatrix[m_iLocation][i] == 'D')
		{
			cout << "there is a room to the Down stairs"<< endl;
		}
		
	}
}