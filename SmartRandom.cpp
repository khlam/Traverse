/*********************************************************************
** Program Filename: 
** Author: Kin-Ho Lam
** Date: 5/25/15
** Description: Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./SmartRandom.h"
using namespace std;
/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
SmartRandom::SmartRandom()
{
	max_row = 0;
	max_col = 0;
	total_moves = 0;
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void SmartRandom::set_initial(Floor f)
{
	max_row = f.get_row();
	max_col = f.get_col();
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void SmartRandom::clean_floor(Floor f)
{	
	while(!f.isclean() && (total_moves < get_batt()) )
	{
		cout << "\n#" << total_moves << endl;
		f.print_floor(total_moves);
		int up = -1; 
		int down = -1;
		int left = -1;
		int right = -1;
		int check = 0;
		if(f.get_row_pos()-1 >= 0 && f.check(-1, 0, 'c'))
		{
			check +=1;
			up = check;
		}
		if(f.get_row_pos()+1 <= max_row && f.check(+1, 0, 'c'))
		{
			check +=1;
			down = check;
		}
		if(f.get_col_pos()-1 >= 0 && f.check(0, -1, 'c'))
		{
			check +=1;
			left = check;
		}
		if(f.get_col_pos()+1 <= max_col && f.check(0, +1, 'c'))
		{
			check +=1;
			right = check;
		}

		if (check == 0)
		{
			if(f.get_row_pos()-1 >= 0 && f.check(-1, 0, 'f'))
			{
				check +=1;
				up = check;
			}
			if(f.get_row_pos()+1 <= max_row && f.check(+1, 0, 'f'))
			{
				check +=1;
				down = check;
			}
			if(f.get_col_pos()-1 >= 0 && f.check(0, -1, 'f'))
			{
				check +=1;
				left = check;
			}
			if(f.get_col_pos()+1 <= max_col && f.check(0, +1, 'f'))
			{
				check +=1;
				right = check;
			}
			if(check == 0)
			{
				return;
			}
		}
		cout << endl;
		sleep(1);
		int move = rand() % check+1;

		if(up == move)
		{
			f.move(-1,0);
		}
		if(down == move)
		{
			f.move(+1,0);
		}
		if(left == move)
		{
			f.move(0,-1);
		}
		if(right == move)
		{
			f.move(0,+1);
		}
		total_moves++;
	}
	if(!f.isclean())
	{
		cout << "Failed to clean." << endl;
	}
	cout << "Total Moves: " << total_moves << endl; 
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
int SmartRandom::get_row()
{
	return row;
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
int SmartRandom::get_col()
{
	return col;
}