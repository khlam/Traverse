/*********************************************************************
** Program Filename: 
** Author: Kin-Ho Lam
** Date: 5/25/15
** Description: Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "./Room.hpp"
#include "./RandomRoomba.h"
#include "./SmartRandom.h"
#include "./SmarterRandom.h"
#include "./Roomba.hpp"

using namespace std;

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void choose_roomba(Room <Roomba> &r) {
	char choice;
	cout <<"\n\tKin-Ho Lam\tAssignment 4\tRoomba"<< endl;
	cout <<"\n\t Random Roomba\tR" << endl;
	cout <<"\t  Smart Random\tS" << endl;
	cout <<"\tSmarter Random\tZ" << endl;
	cout << "\t\n>";
	cin >> choice;

	switch(choice)
	{
		case 'R':
		{
			cout << "\033[2J\033[1;1H";
			cout << "\n\tRandom Roomba" << endl;
			r.set_roomba(new RandomRoomba);
		}break;

		case 'S':
		{
			cout << "\033[2J\033[1;1H";
			cout << "\n\tSmart Random" << endl;
			r.set_roomba(new SmartRandom);
		}break;

		case 'Z':
		{
			cout << "\033[2J\033[1;1H";
			cout << "\n\tSmarter Random" << endl;
			r.set_roomba(new SmarterRandom);
		}break;
	}
		
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void simulate_roomba(string filename, int row, int col, int battery, int moves) {
	Room <Roomba> r;
	if(!r.create_room(filename, row, col, battery, moves))
	{
		return;
	}
	choose_roomba(r);
	r.clean_room(); 
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
int main(int argc, char*argv[])
{
	srand(time(NULL));
	int row, col, battery, moves;
	string filename;

	if (argc < 10 )
	{
		cout << "Invalid arguments." << endl;
		return 1;
	}

    for (int i=1; i<argc -1; i=i+2)
    { 
	    string arg1 = string(argv[i]); 
	    int arg2 = atoi(argv[i+1]); 
	    if (arg1 == "-r")
	    	{
	            row = arg2; 
	        }
	    if (arg1 == "-c")
	    	{
	            col = arg2;
	        }
	    if (arg1 == "-b")
	    	{
	            battery = arg2;
	        }
	    if (arg1 == "-v")
	    	{
	    		moves = arg2;
	    	}
	    if (arg1 == "-f")
	    	{
	    		string file = string(argv[i+1]);
	    		filename = file;
	    	}
	}
	simulate_roomba(filename, row, col, battery, moves);
	return 0;
}