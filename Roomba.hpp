/*********************************************************************
** Program Filename: 
** Author: Kin-Ho Lam
** Date: 5/25/15
** Description: Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Input: none
** Output: none
*********************************************************************/
#ifndef ROOMBA_H
#define ROOMBA_H
#include "./Floor.hpp"
class Roomba {
	private:
		int battery; //how many moves it can make
		int total_moves; //total moves needed to clean

		int row; // current row
		int col; // current col
		int max_x;
		int max_y;

		bool up;
		bool down;
		bool left;
		bool right;
	public:

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		Roomba()
		{
			up = false;
			down = false;
			left = false;
			right = false;
		}

		virtual void clean_floor(Floor f) = 0;
		virtual void set_initial(Floor f) = 0;

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void set_room_size(int x, int y)
		{
			max_x = x;
			max_y = y;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void set_current_position(int x, int y)
		{
			row = x;
			col = y;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void set_end(int b, int total)
		{
			battery = b;
			total_moves = total;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		int get_batt()
		{
			return battery;
		}

	//The Roomba needs to be able to clean a floor, and
	//move left, right, up, down
};
#endif