#pragma once
#include <string>
using namespace std;

class Box
{

private: 
  Box(int index);
  int tile_index;
  bool tile_state[9] = {true};
  int tile[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

public:
  
//constructor creates box with 9 tiles
  Box() {tile_index = 9;}
  
//assign values to tiles
  int tile_assign();
  
//verify the tiles to be closed are indeed open and valid
  bool verify_close(int a, int b, int c);

//close tile determined by user input
  void close_tile(int a, int b, int c);
  
//display current score
  int score();

//shows open tile numbers, * over closed tiles
  string game_status();

//print score and tile status
  void print(int score, string status);

//assign number of dice to be rolled
  int numdice();
};
