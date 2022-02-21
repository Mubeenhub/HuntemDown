/*
Description:- It loads the fighting Game and retrive questions from question folder
*/


#include <iostream>             // Use Cout and stuff like that
#include <string>             // use strings
#include <ctime>             // This is to use system time and note down time difference b/w question and answer
#include <fstream>           // Used for retrieving questions from file
#include <unistd.h>         // this library is to stop the code from running for sometime
#include "fight.h"

using namespace std;

// This function prints out the title of the battle scene
// Input/Output:- Nothing
void header(){

    cout << "*****************************************************************************************************" << endl;
    cout << endl;

    cout << "| BBBBBBBB          A      TTTTTTTTTTTTTTTTTT  TTTTTTTTTTTTTTTTT  LLL                EEEEEEEEEE |                                           " << endl;
    cout << "| BB     BB        A A     TTTTTTTTTTTTTTTTTT  TTTTTTTTTTTTTTTTT  LLL                EEEEEEEEEE |                             " << endl;
    cout << "| BB     BB       A   A           TT                 TT           LLL                EEE        |" << endl;
    cout << "| BBBBBBBB       A     A          TT                 TT           LLL                EEEEEEEEEE |" << endl;
    cout << "| BBBBBBBB      AAAAAAAAA         TT                 TT           LLL                EEEEEEEEEE |              " << endl;
    cout << "| BB     BB    A         A        TT                 TT           LLL                EEE        |              " << endl;
    cout << "| BB     BB   A           A       TT                 TT           LLLLLLLLLLLLLLL    EEEEEEEEEE |                              " << endl;
    cout << "| BBBBBBBB   A             A      TT                 TT           LLLLLLLLLLLLLLL    EEEEEEEEEE |                                   " << endl;

    cout << endl;
    cout << "*****************************************************************************************************" << endl;

    cout << "                            *  *                  *  *                                           " << endl;
    cout << "                             *    *              *     *                                       " << endl;
    cout << "                              *     *          *      *                                    " << endl;
    cout << "                               *     *       *      *                                          " << endl;
    cout << "                                *     *   *      *                                             " << endl;
    cout << "                                  *      *      *                                                 " << endl;
    cout << "                                    *  *      *                                                          " << endl;
    cout << "                                     *      *  *                                                      "<< endl ;
    cout << "                                   *     * *     *                                                        "<< endl ;
    cout << "                                   ******   *****                                                                   " << endl;
    cout << "                                     **       **                                                               " << endl;
    cout << "                                     **       **                                                               " << endl;



}

// INPUT :- It takes in file name to retrive the question {file name can be number of sidekick or enemy}
// Output :- It will retrive the question and print the question
string question(string f){
    string fullfile = "questions/"+f;
    ifstream fin;
    fin.open(fullfile.c_str());
    while (fin.fail()){
        cout << "Unable to Open File" << endl;
        cout << "Try Downloading Questions From github" << endl;
        cout << "Sorry! You have to restart your game Now " << endl;
        exit(1); 
    }
    string s;
    getline(fin,s);
    cout << "Type the given line in 10 seconds (Note:- This is case sensitive)" << endl;
    cout << s << endl;

    fin.close();
    return s;
}

// Input :- Hp as constant and enemy hap as constant
// Print the hp of both enemy and player
void showscore(int hp,int enemyhp){
    cout << "| Your HP: " << hp;
    for (int i=0;i<hp;i++){
        cout << "[]";
    }
    cout << "   ";
    cout << "ENEMY HP: " << enemyhp;
    for (int i=0;i<enemyhp;i++){
        cout << "[]";
    }
    cout << " |";
    cout << endl;
}

// This compare both answer and question
// False if doesn't match
bool compare(string s,string q){
    return (s == q);
}


// This is the game finction and calls all other function above and its gets called up in map file
// Input :- hp as reference and enenmy hp as constant
// You can't quit the game
// Output :- Return true if you win and return false if you loose
bool game(int & hp,int enemyhp, int enemy){

    // bool stop=true;
        time_t end,start;
        double diff;
        string s,q;
        string f = to_string(enemy) + ".txt";
        int i = 0;

    // Continues to iterate until either you loose or the enemy
    while (true){



        header();
        sleep(2);               // wait to give some emphasis to heading hehe
        showscore(hp,enemyhp);
        q=question(f);
        start=time(NULL);

        if (i == 0) {
          cin.get();
          i++;
        }
        getline(cin,s);
        end=time(NULL);
        diff=difftime(end,start);

        if (diff<10){
            cout << "You gave timely response. AMAZING" << endl;
            cout << "Lets compare your response" << endl;
            if (compare(s,q)){
                cout << "Take That you idiot" << endl;
                --enemyhp;
                showscore(hp,enemyhp);
            }else{
                cout << "Shit got Something Wrong in answer;(" << endl;
                --hp;
                showscore(hp,enemyhp);
            }

        }else{
            cout << "Time Has Elapsed. You are LATE:(" <<endl;
            cout << "Player: That Hurts,Ahhhhhhhhhh fuck you" <<endl;
            --hp;
            showscore(hp,enemyhp);
        }

        if (hp == 0){
            return false;
        }
        if (enemyhp == 0){
            return true;
        }

        cout << "----------------------------------" << endl;
        cout << "| Wait 10 sec for Next Question |" << endl;
        cout << "| Get Your Self Ready!          |" << endl;
        cout << "----------------------------------" << endl;

        sleep(10);              // makes my code wait till next question 
    }
}
