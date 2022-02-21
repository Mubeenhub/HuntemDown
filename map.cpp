/*
Description:- This file generate the map, randomly assign enemy sidekicks,blocks & Swaps and set a locatoion
              of BOSS and Player. Varies the Players HP and Prints the Map 
              It also calls a fight scene and Save when needed and print win lose etc
              Ask user for map size and dynamically assign memory
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mymap.h"
#include "fight.h"
#include "Save.h"

using namespace std;

// map representation
const char Player = 'P';
const char Swamp = 'S';
const char Block = 'B';
const char Boss = 'X';
const char Sidekick = 'A';

// Clears the Screen 
void cleanScreen(){
  for (int i = 0; i < 100; i++)
  {
    cout << endl;
  }
}


// this function print the map
// input: size of map, map array
// Output :- Prints the Map
void printMap(int map_size, char** &map) {
    cout << "  -";
    for (int i = 0; i < map_size; i++) {
        cout << "------";
    }
    cout << endl;
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (map[i][j] != Sidekick)
              cout << "  |  " << map[i][j];
            else
              cout << "  |  " << ' ';
        }
        cout << "  |" << endl;
        cout << "  -";
        for (int j = 0; j < map_size; j++) {
            cout << "------";
        }
        cout << endl;
    }
        cout << "*************************Press Q or type 'quit' to Quit Game**********************" << endl;
}

// this function randomize and generate the map.
// input the mapsize and a blank map.
// randomize each row one block, one swamp, and one Sidekick
// these objects may overlap. if overlap, block < swamp < sidekick
void generateMap(int map_size, char ** & map){

  srand(time(NULL));
  int j;
  //prioity block < swamp < sidekick < Plyaer and boss (fix)
  for (int i=0; i<map_size; i++)
  {
    j = rand()%map_size;
    map[i][j] = Block;
    j = rand()%map_size;
    map[i][j] = Swamp;
    j = rand()%map_size;
    map[i][j] = Sidekick;
  }
  map[0][0] = Player;
  map[map_size-1][map_size-1] = Boss;
}

// this function tells the player that he cannot go pass the block
// Input :- Map Array and x,y cordinates of players next move
// Output :- True if Block Exists else False
bool block(char ** & map, int x, int y)
{
  if (map[x][y] == Block)
    return true;
  return false;
}

// this function asks people to move or quit
// if player inputs a direction, succesfully move OR get blocked OR step into swamp OR battle
// if player inputs "quit", save the recent gameplay
// Inputs :- Map size and map array , move command and x,y cordinates of Players and its hp
// Output:- Prints if player encounter enemy, looses, blocked and hit by swap and shows movement
void move(int map_size, char ** & map, string command, int &x, int &y, int & hp)
{
  if (command == "N" || command == "n") // move north
  {
    if (x == 0 || block(map, x-1, y))
    {
      cout << "This move is probibited, please input again" << endl;
      return;
    }
    else
    {
      map[x][y] = ' ';
      x--;
      if (map[x][y] == Swamp)
      {
        cout << "You step into the swamp and lose 1 hp" << endl;
        hp--;
        if (hp == 0) {
          cout << "You have no hp, good luck next time";
          exit (0);
        }
        cout << "You have " << hp <<" hp left" << endl;
        map[x][y] = Player;
      }
      else if (map[x][y] == Sidekick || map[x][y] == Boss)
      {
        cout << "You enter the battle" << endl;
        int enemyhp;
        if (map[x][y] == Sidekick)
          enemyhp = 3;
        else if (map[x][y] == Boss)
          enemyhp = 5;
        bool status = game(hp, enemyhp, x + 1);
        if (status == 1) {
          cout << "You defeat the enemy" << endl;
          map[x][y] = Player;
        }
        else{
          cout << "You lose the game" << endl;
          exit (0);
        }
      }
      else
        map[x][y] = Player;
    }
  }
  else if (command == "E" || command == "e") // move east
  {
    if (y == map_size-1 || block(map, x, y+1))
    {
      cout << "This move is probibited, please input again" << endl;
      return;
    }
    else
    {
      map[x][y] = ' ';
      y++;
      if (map[x][y] == Swamp)
      {
        cout << "You step into the swamp and lose 1 hp" << endl;
        hp--;
        if (hp == 0) {
          cout << "You have no hp, good luck next time" << endl;
          exit (0);
        }
        cout << "You have " << hp <<" hp left" << endl;
        map[x][y] = Player;
      }
      else if (map[x][y] == Sidekick || map[x][y] == Boss)
      {
        cout << "You enter the battle" << endl;
        int enemyhp;
        if (map[x][y] == Sidekick)
          enemyhp = 3;
        else if (map[x][y] == Boss)
          enemyhp = 5;
        bool status = game(hp, enemyhp, x + 1);
        if (status == 1) {
          cout << "You defeat the enemy" << endl;
          map[x][y] = Player;
        }
        else{
          cout << "You lose the game" << endl;
          exit (0);
        }
      }
      else
        map[x][y] = Player;
    }
  }
  else if (command == "W" || command == "w") // move west
  {
    if (y == 0 || block(map, x, y-1))
    {
      cout << "This move is prohibited, please input again" << endl;
      return;
    }
    else
    {
      map[x][y] = ' ';
      y--;
      if (map[x][y] == Swamp)
      {
        cout << "You step into the swamp and lose 1 hp" << endl;
        hp--;
        if (hp == 0) {
          cout << "You have no hp, good luck next time" << endl;
          exit (0);
        }
        cout << "You have " << hp <<" hp left" << endl;
        map[x][y] = Player;
      }
      else if (map[x][y] == Sidekick || map[x][y] == Boss)
      {
        cout << "You enter the battle" << endl;
        int enemyhp;
        if (map[x][y] == Sidekick)
          enemyhp = 3;
        else if (map[x][y] == Boss)
          enemyhp = 5;
        bool status = game(hp, enemyhp, x + 1);
        if (status == 1) {
          cout << "You defeat the enemy" << endl;
          map[x][y] = Player;
        }
        else{
          cout << "You lose the game" << endl;
          exit (0);
        }
      }
      else
        map[x][y] = Player;
    }
  }
  else if (command == "S" || command == "s") // move south
  {
    if (x == map_size-1 || block(map, x+1, y))
    {
      cout << "This move is prohibited, please input again" << endl;
      return;
    }
    else
    {
      map[x][y] = ' ';
      x++;
      if (map[x][y] == Swamp)
      {
        cout << "You step into the swamp and lose 1 hp" << endl;
        hp--;
        if (hp == 0) {
          cout << "You have no hp, good luck next time" << endl;
          exit (0);
        }
        cout << "You have " << hp <<" hp left" << endl;
        map[x][y] = Player;
      }
      else if (map[x][y] == Sidekick || map[x][y] == Boss)
      {
        cout << "You enter the battle" << endl;
        int enemyhp;
        if (map[x][y] == Sidekick)
          enemyhp = 3;
        else if (map[x][y] == Boss)
          enemyhp = 5;
        bool status = game(hp, enemyhp, x + 1);
        if (status == 1) {
          cout << "You defeat the enemy" << endl;
          map[x][y] = Player;
        }
        else{
          cout << "You lose the game" << endl;
          exit (0);
        }
      }
      else
        map[x][y] = Player;
    }
  }
// quit and save the gameplay
  else if (command == "Quit" || command == "quit"|| command == "q" || command == "Q"){ 
    savedata(hp, map, map_size, x, y);
    cout << "******************************************" << endl;
    cout << "saved the current progress, exit the game." << endl;
    exit (0);
  }
  else
  {
    cout << "Please input the correct direction" << endl;
    return;
  }
}

// Input:- Nothing
// Output: the function returns a curtomize map size or default map size (10)
// Ask for map size between 5-25
int map_size()
{
  int map_size = 10;
  char cmd;
  cout << "Do you want to customize your map size? Y|N" << endl;
  cin >> cmd;
  while (cmd != 'Y' && cmd != 'y' && cmd != 'N' && cmd != 'n')
  {
    cout << "wrong input: please input again: Y|N" << endl;
    cin >> cmd;
  }
  if (cmd == 'Y' || cmd == 'y'){
    cout << "Enter The Map Size: ";
    cin >> map_size;
    cout << endl;
    while (map_size < 5 || map_size > 25)
    {
      cout << "Alert!!! Please Choose Map Size Between 5-25" << endl;
      cout << "Please Enter Again, Thank You" << endl;
      cin >> map_size;
    }
  } 
  return map_size;

}

// Input:- Player hp, x,y positions and map array and mapsize and continue or not continue signal
// Output :- Check when the game ends and prints who win and loose also allocate and deallocate dynamic memory
void mymap(int & hp, int & pos_x, int & pos_y, char ** & map, int & mapsize, bool con)
{
    string command;
    if (con == 0) {
      mapsize = map_size();

      map =  new char*[mapsize];

      for (int i = 0; i < mapsize; i++)
      {
          map[i] = new char [mapsize];

      }


      for (int i=0;i<mapsize;i++){
          for (int j=0;j<mapsize;j++){
          map[i][j] = ' ';
          }
      }
      generateMap(mapsize, map);
    }

    printMap(mapsize, map);

  // While loops run till the player reaches the end of the map (i.e lower right corner the max row and column) 
    cout << "Move your player, N for north, E for east, S for south, W for west" << endl;
    while (map[mapsize-1][mapsize-1] != Player)
    {
      cin >> command;
      cleanScreen();
      move(mapsize, map, command, pos_x, pos_y, hp);
      printMap(mapsize, map);
    }

    // if (hp > 0){
    //   cout << " ----------------------------------------------------- " << endl;
    //   cout << "| Y   Y  O O O   U     U   W   W  W  IIIIII N    N  |         " << endl;
    //   cout << "|   Y   O     O  U     U   W  W W W    II   N N  N  |    " << endl;
    //   cout << "|   Y   O     O  U     U   W W   WW    II   N  N N  |     " << endl;
    //   cout << "|   Y    O O O     U U     W      W  IIIIII N   N   |    " << endl;
    //   cout << " ----------------------------------------------------- " << endl;
    
    // Print Message if Player Wins
    if (hp > 0){
      cout << " -------------------------------------- " << endl;
      cout << " YOU WON THE GAME ! Well Played CHAMP        " << endl;
      cout << " YOU WON THE GAME ! Well Played CHAMP   " << endl;
      cout << " YOU WON THE GAME ! Well Played CHAMP    " << endl;
      cout << " YOU WON THE GAME ! Well Played CHAMP  " << endl;
      cout << " ---------------------------------------" << endl;
    }

    // deallocate memory 
    for (int i = 0; i < mapsize; i++) {
        delete [] map[i];
    }
    delete [] map;
}
