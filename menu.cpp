/*
Description:- It calls the map file and save file when needed
              Ask for user input on difficulty and continue or new game
              Print the header, rules and story of the game.
*/

#include <iostream>
#include "mymap.h"
#include "Save.h"
using namespace std;

// Clears the Screen 
void clearScreen(){
  for (int i = 0; i < 100; i++)
  {
    cout << endl;
  }
}

void tittle()
// the game title
{

cout << "██╗░░██╗██╗░░░██╗███╗░░██╗████████╗███████╗███╗░░░███╗██████╗░░█████╗░░██╗░░░░░░░██╗███╗░░██╗" << endl;
cout << "██║░░██║██║░░░██║████╗░██║╚══██╔══╝██╔════╝████╗░████║██╔══██╗██╔══██╗░██║░░██╗░░██║████╗░██║" << endl;
cout << "███████║██║░░░██║██╔██╗██║░░░██║░░░█████╗░░██╔████╔██║██║░░██║██║░░██║░╚██╗████╗██╔╝██╔██╗██║" << endl;
cout << "██╔══██║██║░░░██║██║╚████║░░░██║░░░██╔══╝░░██║╚██╔╝██║██║░░██║██║░░██║░░████╔═████║░██║╚████║" << endl;
cout << "██║░░██║╚██████╔╝██║░╚███║░░░██║░░░███████╗██║░╚═╝░██║██████╔╝╚█████╔╝░░╚██╔╝░╚██╔╝░██║░╚███║" << endl;
cout << "╚═╝░░╚═╝░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚═╝░░░░░╚═╝╚═════╝░░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚══╝" << endl;

}


// prints the description of the game and rules
// Input :- Nothing
// Output:- Just Prints nothing else
void setting()
{
  cout << "Welcome to the game of HUNTemDOWN." << endl;
  cout << "Nowadays, less and less people care about the correct spelling of words" << endl;
  cout << "Until one day, monsters appear and rob our words" << endl;
  cout << "You step on the adventure to hunt down monsters and retrieve our language" << endl;
  cout << endl;
  cout << endl;
  cout << "********************************** RULES *********************************" << endl;
  cout << "You have to Kill the Boss Labelled (X)" << endl;
  cout << "You can't move through the Block labelled (B)" << endl;
  cout << "If you step into a Swap labelled (S), you will loose 1 hp" << endl;
  cout << "While you are moving towards BOSS you would encounter boss sidekicks" << endl;
  cout << "The enemy sidekicks are HIDDEN so its on your luck how many you encounter" << endl;
  cout << "Note:- You can't quit during battle else state of the game won't be saved" << endl;
  cout << "Please Make sure you have questions & log Folder before you run your game." << endl;
  cout << "***************************** SO LETS PLAY **********************************" << endl;
  cout << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "| FOR BETTER EXPERIENCE PLAY IN FULLSCREEN _ THANKYOU! |" << endl;
  cout << "-------------------------------------------------------" << endl;
  
}

// let the player inputs "new" or "continue"
// Input:- Nothing as Parameter only ask play new or continue
// Output:- Print prompts and return new or continue
string new_or_con()
{
  string command;
  cout << "------------------------------------------" << endl;
  cout << "Please type the following to continue:"            << endl;
  cout << "new : New game"                                       << endl;
  cout << "continue : Continue from previous game"                        << endl;
  cout << "-------------------------------------------" << endl;
  cin >> command;
  while (command != "new" && command != "continue")
  {
    cout << "error input" << endl;
    cout << "please input again: new or continue " << endl;
    cin >> command;
  }
  clearScreen();
  return command;
}

// Input:- Take mode and hp as reference and adds value in it accordingly
// Output:- return nothing but sets hp of player according to difficulty
// let the player chooses the mode either hard, easy , difficult 
void choose_mode(string & mode, int & hp)
{
  cout << "please choose a difficulty: easy, moderate, or hard: " << endl;
  cin >> mode;
  while (mode != "easy" && mode != "moderate" && mode != "hard")
  {
    cout << "error input" << endl;
    cout << "please input again: easy, moderate, or hard" << endl;
    cin >> mode;
  }
  clearScreen();
  if (mode == "easy")
    hp = 6;
  else if (mode == "moderate")
    hp = 4;
  else
    hp = 2;
}

// Input :- Gets values from other functions in this files
// Output:- Nothing but calls the map function in other file and sends values according to new or continue
int main()
{
  tittle();
  setting();

  string cmd = new_or_con();
  if (cmd == "new") {
    int hp; // health point
    int pos_x = 0, pos_y = 0; // default position of player
    int mapsize;
    char ** map;
    string mode; // easy, moderate, or hard
    choose_mode(mode, hp);
    mymap(hp, pos_x, pos_y, map, mapsize, 0); // bool continue = 0, it is a new game
  }
  if (cmd == "continue") {
    int hp;
    int pos_x, pos_y;
    int mapsize;
    char ** map;
    retrievedata(hp, map, mapsize, pos_x, pos_y);
    mymap(hp, pos_x, pos_y, map, mapsize, 1); // bool continue = 1, it reloads the data.
  }
}
