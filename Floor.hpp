/*********************************************************************
** Program Filename: 
** Author: Kin-Ho Lam
** Date: 5/25/15
** Description: Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Input: none
** Output: none
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
	private:
		vector < vector <char> > v;
		int obj_row; //Holds an object’s current row position
		int obj_col; //Holds an object’s current col position
		
		int displ_m;

		int x; //number of rows
		int y; // number of col

	public:

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		bool isclean()
		{
			for(int i = 0; i < v.size(); i++)
			{
				for(int j = 0; j < v[i].size(); j++)
				{
					if(v[i][j] == 'f')
					{
						return false;
					}
				}
			}
			cout <<"\nFloor Cleaned!" << endl;
			print_floor(displ_m);
			return true;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		bool get_floor(string filename)
		{ 
			x = 0;
			y = 0;
			string line;

			ifstream file;
			file.exceptions ( ifstream::failbit | ifstream::badbit );
			try 
			{
   				file.open (filename.c_str());
			}
				catch (ifstream::failure e) {
			    cout << "Exception opening/reading file" << endl;
			    exit(1);
			}
			file.exceptions(ifstream::goodbit);
			while (getline(file, line)) //gets number of rows
			{
		   		x++;
		   	}

		   	for (int i = 0; i < line.length(); ++i) //gets number of columns
		   	{
		   		if (line[i] == 'f' || line[i] == 'o' || line[i] == 'c')
		   		{
		   			y++;
		   		}
		   	}
		   	file.close();
		   	return true;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void populate_floor(string filename)
		{
			string line;
			fstream file(filename.c_str());
			for(int i = 0; i < v.size(); i++)
			{	
				getline(file,line);
				for(int k = 0; k < line.size(); k++)
				{
					if (line[k] == 'f' || line[k] == 'o' || line[k] == 'c')
			   		{
			   			v[i][k] = line[k];
			   		}
				}
			}
			print_floor(displ_m);
			file.close();
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 				
		void create_floor(string filename, int displ)
		{
			displ_m = displ;
			for(int i = 0; i <x; i++)
			{
				vector<char> row;
				for (int j = 0; j < y; j++)
				{
					row.push_back('f');
				}
				v.push_back(row);
			}
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void print_floor(int move_numb)
		{
			if ( !(move_numb % displ_m))
			{
				for(int i = 0; i < v.size(); i++)
				{
					for(int j = 0; j < v[i].size(); j++)
					{
						cout << v[i][j] << " ";
					}
					cout << endl;
				}
			}
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void place_roomba()
		{
			v[obj_row][obj_col] = 'R';
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		void move(int rmod, int cmod)
		{
			v[obj_row][obj_col] = 'c';
			v[obj_row+=rmod][obj_col+=cmod] = 'R';
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		bool is_corner(int rmod, int cmod)
		{
			if(obj_row + rmod == 0 && obj_col + cmod == 0)
			{
				return false;
			}

			if(obj_row + rmod == 0 && obj_col + cmod == y)
			{
				return false;
			}

			if(obj_row + rmod == x && obj_col + cmod == 0)
			{
				return false;
			}

			if(obj_row + rmod == x && obj_col + cmod == y)
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
		bool check(int rmod, int cmod , char ignore)
		{
			if((obj_row + rmod >= 0 && obj_row + rmod <= x) &&  (obj_col + cmod >= 0 && obj_col + cmod <= y))
			{
				char m = v[obj_row + rmod][obj_col + cmod];
				if (m == ignore || m== 'o')
				{
					return false;
				}
				return true;
			}
			return false;
		}

		char find_edge()
		{
			if ( (obj_col -1 >=0) && (obj_col + 1 <= y-1) && (obj_row -1 >=0) && (obj_row + 1 <= x-1) )
			{
				int r = (y-1) - (obj_row +1);//right
				int l = (obj_row -1);//left
				int d = (x-1) - (obj_col +1);//down
				int u = (obj_col -1);//up

				if (r == l == d == u)
				{
					return 'n';
				}

				int small = NULL;
				if(r < l)
				{
					small = r;
				}
				else
				{
					small = l;
				}


				if(small < d)
				{
					;//do nothing
				}
				else
				{
					small = d;
				}

				if(small < u)
				{
					;//do nothing
				}
				else
				{
					small = u;
				}
				//returns shortest route

				if(small == r)
				{ 
					return 'r';
				}

				if(small == l)
				{
					return 'l';
				}

				if(small == d)
				{
					return 'd';
				}

				if(small == u)
				{
					return 'u';
				}
			}
		}

		bool cutoff(int rmod, int cmod)
		{ //'c'
				if ( (obj_col + cmod -1 >=0) && (obj_col + cmod + 1 <= y-1) && (obj_row + rmod >=0) && (obj_row + rmod <= x-1) )
				{

					/*pos(0,0);
					pos(0,cmod-1);
					pos(0,cmod+1);
					cout << endl;*/
					if(v[obj_row + rmod][obj_col + cmod -1] == 'f' && v[obj_row + rmod][obj_col + cmod +1] == 'f')
					{
						return false;
					}
				}
				
				if ( (obj_row + rmod -1 >=0) && (obj_row + rmod + 1 <= x-1) && (obj_col + cmod >=0) && (obj_col + cmod<= y-1) )
				{
					/*pos(0,0);
					pos(rmod-1,0);
					pos(rmod+1,0);
					cout << endl;*/
					if(v[obj_row + rmod +1 ][obj_col + cmod] == 'f' && v[obj_row + rmod -1][obj_col + cmod] == 'f')
					{
						return false;
					}
				}
		
			return true;
		}

		void pos(int rmod, int cmod)
		{
			cout << "("<< obj_row + rmod<<","<< obj_col+cmod<<")"<< endl;
		}
/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		bool set_start(int x_start, int y_start)
		{
			if ( (x_start > x-1 || y_start > y-1) || (x_start < 0 || y_start < 0) )
			{
				cout <<"(" << x_start <<", " << y_start << ") is out of bounds. Please enter a valid position." << endl;
				return false;
			}
				obj_row = x_start;
				obj_col = y_start;
				cout << "Starting roomba at (" << x_start << ", " << y_start << ")" << endl;
				return true;
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
			return x-1;
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
			return y-1;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		int get_row_pos()
		{
			return obj_row;
		}

/*********************************************************************
** Function: 
** Description:Assists with the overall program. Necessary for operation. Holds functions/function declerations which perform calculations.
** Parameters:
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
		int get_col_pos()
		{
			return obj_col;
		}
		
};

#endif