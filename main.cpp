#include "box.h"
#include "dice.h"
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
char q; //declare quit variable

do {
  int a, b, c; //declare user input variables
  Box box; //construct box
  box.tile_assign(); //assign tile values

  //start game
  do {
    box.print(box.score(), box.game_status()); //display score and tiles
    Dice dice(box.numdice()); //construct dice object with one or two dice depending on status of tiles 7, 8, 9
    dice.roll(); //roll dice
    cout << dice.str() << " Total: "<< dice.total() << endl; //display dice roll

    do {
      cout << "Enter up to 3 integers totalling the sum of your dice, separated by spaces, to close the corresponding tiles."
        " Enter '0' for no input. Enter '0 0 0' if you have no valid moves." << endl;
      cin >> a >> b >> c;
      if((a + b + c != dice.total()) && (a + b + c != 0))
        cout << "Your selections do not total the dice you rolled.";
    } while (((a + b + c != dice.total()) && (a + b + c != 0)) || box.verify_close(a, b, c) == false); 
    //loop until valid input is achieved
  
    box.close_tile(a, b, c); //close corresponding tiles
  } while ((box.score() !=0) && (a + b + c != 0)); //loop game until score is zero or input is '0 0 0'

    if (box.score() == 0) //end game win
    {
    cout << endl << "Congratulations! The Box is closed. You Win! \n \nEnter Y to play again, enter anything else to exit.";
      cin >> q;
    }
    else if (box.score() != 0 && a + b +c == 0) //end game loss
    cout << endl << "You did not close the box. Your score is: " << box.score() << ". Would you like to play again?"
      " Enter Y to play again, enter anything else to exit.";
      cin >>q;
} while (toupper(q) == 'Y'); //loop game until user chooses to quit

  return(0);
}

