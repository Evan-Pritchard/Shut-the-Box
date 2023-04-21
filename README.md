[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10053572)
# Shut the Box, Part 2

Using the *Box* class you developed in the provious assignment, complete the implementation the game.

To recap game play from the previous assignment...

    In this game, there is a box that contains 9 tiles numbered 1 through 9 with all tiles in the “up” position. In each round of the game the player rolls a pair of dice, unless the sum of the numbers on the up-facing tiles totals 6 or less in which case the player rolls a single die. After rolling the dice (or die), the player chooses one, two, or three of the up-facing tiles totaling the same number as the roll of the dice to move to the “down” position. The player continues until either all the tiles are in the down position, or there is no combination of up-facing tiles that total the roll of the dice. The player’s score is the total of the up-facing tiles at the end of the game, with the goal being the lowest score possible. A perfect score is zero.

You will also need the *Dice* class that was implemented during class.

Your program should play a single game, which consists of multple rounds (or rolls of the dice). With each round, display the contents of the box, roll and display the dice (or die), then prompt for three tiles to close. Game play should continue in this manner until either all tiles are in the down position or the player enters three zero's for input.

The input for each round is three integers. You should validate that each integer is in the range of 0 through 9, and no two non-zero input values are the same. According to the rules of the game, no input should be a down-facing tile, however if you *Box* class is implemented as described in part 1 the *Box* object will handle that part of the validation.

Note that when the sum of the tiles in the box totals 6 or less, you need to switch to using a single die rather than two dice. You might consider declaring your *Dice* variable with two dice:

```C++
Dice dice(2);
```

Then, within your game input loop once you detect that your box totals 6 or less, you can overrite the *dice* variable with a single die:

```C++
dice = Dice(1);
```

Here is a sample run of the program:

```
Let's play Shut The Box

Box: 1 2 3 4 5 6 7 8 9
Dice: 6-3
Tiles: 9 0 0

Box: 1 2 3 4 5 6 7 8 *
Dice: 5-6
Tiles: 8 3 3
Tile selection is not valid. Try again.
Tiles: 8 3 0

Box: 1 2 * 4 5 6 7 * *
Dice: 1-3
Tiles: 1 3 0
Tile selection is not valid. Try again.
Tiles: 4 0 0

Box: 1 2 * * 5 6 7 * *
Dice: 2-1
Tiles: 1 2 0

Box: * * * * 5 6 7 * *
Dice: 3-2
Tiles: 5 0 0

Box: * * * * * 6 7 * *
Dice: 5-6
Tiles: 0 0 0

Box: * * * * * 6 7 * *
Score: 13
```

In this sample, the only user input is following the `Tiles:` prompt.
