<h1>STAGE 1 - PROPOSAL</h1>
 
<h3>Team members:-</h3>
Muhammad Mubeen - 3035831783<br>
Li Hon Lam -3035666279<br>
 
<h3><b>Game description:-</b></h3>

 Hunt em Down is a speed typing combat game implemented for different age groups. The player has to kill a supreme language monster placed inside the map and he is     surrounded by his sidekicks in an unknown location. The sidekicks pop out whenever the player steps in at the location of a sidekick.
 The fight proceeds through a typing game where the player has to type the answer in a particular time to land to blow on the enemy if he fails to do so the enemy lands a blow on the player which will decrease the player’s health. The health of the enemy depends on how many questions you have to solve to defeat the other guy. Technically in order to defeat the boss, you need to solve more questions. 
 Players are put into the top right starting of the map at the beginning of the game. The player can only move to the surrounding area one step by step if the player finds a sidekick, he cannot move until he defeats it.
 
 <h3>Story Line & Rules</h3>
Welcome to the game of HUNTemDOWN.
Nowadays, less and less people care about the correct spelling of words
Until one day, monsters appear and rob our words
You step on the adventure to hunt down monsters and retrieve our language
<h3>RULES</h3>

1. You have to Kill the Boss Labelled (X).
2. You can't move through the Block labelled (B).
3. If you step into a Swap labelled (S), you will loose 1 hp.
4. If you want to customise the Map the size should be b/w 5-25.
5. Inorder to Quit the game, Don't Randomly Close the window else no changes would be saves.
6. While you are moving towards BOSS you would encounter boss sidekicks and procede to fight scene.
7. You can Quit during Fight else your progress won't be saved plus you don't have quit option either ways aha.
8. Please Make sure you have questions Folder before you run your game.



<h3><b>Features / Functions<b></h3> 
  
1. The game will have 3 modes (i.e Easy, Medium, Hard). In easy mode, the player will have more health than the hard mode. The player will move inside the maze and find the boss and kill him to win the game. If he is unable to do so, the player loses. We will cover the 2nd point of requirement i.e __Data structures for storing game status__ as we would be storing the health and map using variables and arrays. 
2. Sidekicks are unseen while the player can see the block, swamp, and boss. Sidekicks pops up when the player steps in the location where the sidekick is placed. We will cover the 1st point & 2nd Point of requirement i.e **Generation of random game sets or events** {generate the location of enemy sidekicks randomly} &  __Data structures for storing game status__ {for storing the location of swap,block,boss,players,sidekicks}
3. Interactive Text-Based Graphics. This is to increase the interactivity of our game. 
4. Users will be given a choice to select the size of the map or customize it. We will store the map in a 2D array and allocate separate memory for the customizable map. This Covers the 3rd Point i.e **Dynamic memory management** by allocating sufficent memory for our map so that player can customize the length of map.
5. Fight scene:- You would be given a typing challenge and if you get it right then you defeat the sidekick and move further but if you can’t answer you lose 1 HP and you can’t move until you defeat the sidekick. This covers the 4th point i.e **File input/output.** by using file to retrieve questions for the fight scene.
6. Save/Continue game:- This is to store the status of the game so we can continue playing the game later. This is also cover point 4  i.e **File input/output.** inorder to save and retrieve the status of the game.
7. Use Makefile command to launch the game. This will cover the 5th Point i.e **Program codes in multiple files** as we would be using makefile to compile different files to perform different functions in our game which are highlighted below.

<h3><b>Compilation Command:-<b></h3>
 <b>First run *make HuntemDown* in linux cmd.<br>
  Then run "./HuntemDown" to start the game.</b>


<h3><b>Functions & Files (we will have different files/Functions and will use makefile)</b></h3>

* Menu/Main File: let the player choose the mode, new game, or continue, have access to quit/continue, save function.
* Map file: input size of the map, Generate the map, and randomly spawn sidekicks, blocks, and swamp. Remove the sidekick when it is defeated. (3)
* Move Function:: the player types “EWNS” i.e (East,West,North,South) to move right, left,upward, and downwards respectively.
* Block Function: the player cannot go through the block area
* Swamp Function: the player’s health minus 1 when he gets into the swamp.
* battle File: the battle begins when the player steps into sidekicks or touches the boss
* Quit/ continue Function: save the status in a text file, use that as the input when continuing the game(4,5)
<br>
<h3>Project Requirements:</h3>

1. Generation of random game sets or events
2. Data structures for storing game status
3. Dynamic memory management
4. File input/output (e.g., for loading/saving game status)
5. Program codes in multiple files
6. Proper indentation and naming styles
7. In-code documentation
 
 

 
 

 

