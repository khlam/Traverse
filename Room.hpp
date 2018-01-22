/*********************************************************************
** Program Filename: 
** Author: Kin-Ho Lam
** Date: 5/25/15
** Description: Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <cstring>
#include "./Floor.hpp"
#include "./Roomba.hpp"
#include "./RandomRoomba.h"
using namespace std;

template <typename T>
class Room {
	private:
		Floor f;
		T *obj;
		int batt;
		int displ_m;
	public:
/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		Room()
		{
			obj = NULL;
		}

		~Room()
		{
			delete obj;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		bool create_room(string filename, int row, int col, int battery, int display)
		{
			displ_m = display;
			batt = battery;
			if(!f.get_floor(filename))
			{
				return false;
			}
			f.create_floor(filename, displ_m);

			f.populate_floor(filename);
			
			if(!f.set_start(row,col))
			{
				return false;
			}

			return true;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void set_roomba(Roomba *r)
		{
			obj = r;
			obj->set_end(batt, f.get_row()*f.get_col());
 			obj->set_initial(f);
			f.place_roomba();
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void clean_room()
		{
			if(obj!=NULL)
			obj->clean_floor(f);
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		int get_row()
		{
			return f.get_row();
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		int get_col()
		{
			return f.get_col();
		}
};