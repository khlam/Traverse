/*********************************************************************
** Program Filename: 
** Author: Kin-Ho Lam
** Date: 5/25/15
** Description: Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Input: none
** Output: none
*********************************************************************/
#include "./Floor.hpp"
#include "./Roomba.hpp"
#ifndef RandomRoomba_H
#define RandomRoomba_H
class RandomRoomba : public Roomba 
{
	private:
		int row;
		int col;

		int max_row;
		int max_col;

		int total_moves;

	public:
		RandomRoomba();
		void set_initial(Floor f);
		void clean_floor(Floor f);
		int get_row();
		int get_col();
};

#endif