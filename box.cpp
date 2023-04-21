#include "box.h"
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

//constructor creates box with 9 tiles
Box::Box(int index) 
  {
    tile_index = index;
  }

  //assign values to tiles
  int Box::tile_assign()
    {
      for (int i=0; i<9; i++)
        {
          tile[i] = i+1;
          return(tile[i]);
        }
      return(0);
    };

  //verify the tiles to be closed are indeed open and valid
  bool Box::verify_close(int a, int b, int c)
    {
      if (a<0 || b<0 ||c<0 || a>9 || b>9 || c>9)
        {
          cout << "One or more of your options are out of range.";
          return(false);
        }
      if (((a == b) && (a != 0)) || ((a == c) && (a != 0)) || ((b == c) && (b != 0)))
        {
          cout <<"You have repeated inputs.";
          return(false);
        }
      tile[-1] = -1;
      if (tile[a-1] == 0 || tile[b-1] == 0 || tile[c-1]==0)
        {
          cout << "One or more of your options have already been closed.";
          return(false);
        } 
      return(true);
    };

  //close tile determined by user input
  void Box::close_tile(int a, int b, int c)
    {
      for (int i=0; i<9; i++)
        {
          if (tile[i] == a) tile[i] = 0;
          if (tile[i] == b) tile[i] = 0;
          if (tile[i] == c) tile[i] = 0;
          
        }
    };

  //calculate current score
  int Box::score()
    {
      int score = 0;
      for (int i=0; i<9; i++)
        {
          if (tile[i] != '*') score += tile[i];
        }
      return(score);
    };
  
  //shows open tile numbers, * over closed tiles
  string Box::game_status()
    {
      string str = "";
      for (int i=0; i<9; i++)
      {
        str += (to_string(tile[i]) + " "); 
        replace(str.begin(), str.end(), '0', '*');
      }
      return(str);
    };

  //print results
  void Box::print(int score, string status)
    {
      cout <<endl << "Tiles: " << status << endl;
      cout << "Score: " << score << endl;
    };

  int Box::numdice()
    {
      if( tile[6] ==7 || tile[7] == 8 || tile[8] ==9) return(2);
      else return(1);
    };
