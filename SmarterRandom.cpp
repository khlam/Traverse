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
#include "./SmarterRandom.h"
using namespace std;
/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
SmarterRandom::SmarterRandom()
{
	max_row = 0;
	max_col = 0;
	total_moves = 0;
	lastmove = NULL;
}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void SmarterRandom::set_initial(Floor f)
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
void SmarterRandom::clean_floor(Floor f)
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
		if(f.get_row_pos()-1 >= 0 && f.check(-1, 0, 'c') && f.cutoff(-1, 0))
		{
			check +=1;
			up = check;
			lastmove ='n';
		}
		if(f.get_row_pos()+1 <= max_row && f.check(+1, 0, 'c') && f.cutoff(+1,0) )
		{
			check +=1;
			down = check;
			lastmove = 'n';
		}
		if(f.get_col_pos()-1 >= 0 && f.check(0, -1, 'c')  && f.cutoff(0,-1))
		{
			check +=1;
			left = check;
			lastmove ='n';
		}
		if(f.get_col_pos()+1 <= max_col && f.check(0, +1, 'c') && f.cutoff(0, +1))
		{
			check +=1;
			right = check;
			lastmove = 'n';
		}

		if (check == 0)
		{
			if(f.get_row_pos()-1 >= 0 && f.check(-1, 0, 'c') && f.is_corner(-1,0) && lastmove != 'd' && f.cutoff(-1, 0))
			{
				check +=1;
				up = check;
			}
			if(f.get_row_pos()+1 <= max_row && f.check(+1, 0, 'c') && f.is_corner(+1,0) && lastmove != 'u' && f.cutoff(+1,0) ) 
			{
				check +=1;
				down = check;
			}
			if(f.get_col_pos()-1 >= 0 && f.check(0, -1, 'c') && f.is_corner(0,-1) && lastmove != 'r' && f.cutoff(0,-1))
			{
				check +=1;
				left = check;
			}
			if(f.get_col_pos()+1 <= max_col && f.check(0, +1, 'c') && f.is_corner(0,+1) && lastmove != 'l' && f.cutoff(0, +1))
			{
				check +=1;
				right = check;
			}
		}

		if(check == 0)
		{
			if (f.find_edge() == 'r' && lastmove != 'l' && f.cutoff(-1, 0))
			{
				check +=1;
				right = check;
			}

			if (f.find_edge() == 'l' && lastmove != 'r' &&f.cutoff(+1,0))
			{
				check +=1;
				left = check;
			}

			if (f.find_edge() == 'd' && lastmove != 'u' &&f.cutoff(0,-1))
			{
				check +=1;
				down = check;
			}

			if (f.find_edge() == 'u' && lastmove != 'd' &&f.cutoff(0, +1))
			{
				check +=1;
				up = check;
			}

			/*
			if(f.get_row_pos()-1 >= 0 && f.check(-1, 0, 'f') && f.cutoff(-1, 0))
			{
				check +=1;
				up = check;
			}
			if(f.get_row_pos()+1 <= max_row && f.check(+1, 0, 'f') && f.cutoff(-1, 0))
			{
				check +=1;
				down = check;
			}
			if(f.get_col_pos()-1 >= 0 && f.check(0, -1, 'f') && f.cutoff(0, -1))
			{
				check +=1;
				left = check;
			}
			if(f.get_col_pos()+1 <= max_col && f.check(0, +1, 'f') && f.cutoff(0,+1) )
			{
				check +=1;
				right = check;
			}*/
		}

		if (check == 0)
		{
			if(f.get_row_pos()-1 >= 0 && f.check(-1, 0, 'o') )
			{
				check +=1;
				up = check;
			}
			if(f.get_row_pos()+1 <= max_row && f.check(+1, 0, 'o')  )
			{
				check +=1;
				down = check;
			}
			if(f.get_col_pos()-1 >= 0 && f.check(0, -1, 'o')  )
			{
				check +=1;
				left = check;
			}
			if(f.get_col_pos()+1 <= max_col && f.check(0, +1, 'o')  )
			{
				check +=1;
				right = check;
			}
		}

		if(check == 0)
		{
			cout << "No possible moves." << endl;
			return;
		}

		cout << endl;
		sleep(1);
		int move = rand() % check+1;

		if(up == move)
		{
			f.move(-1,0);
			lastmove = 'u';
		}
		if(down == move)
		{
			f.move(+1,0);
			lastmove = 'd';
		}
		if(left == move)
		{
			f.move(0,-1);
			lastmove = 'l';
		}
		if(right == move)
		{
			f.move(0,+1);
			lastmove = 'r';
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
int SmarterRandom::get_row()
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
int SmarterRandom::get_col()
{
	return col;
}