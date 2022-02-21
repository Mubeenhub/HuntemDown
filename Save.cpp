/*
Description:- It is use to save game status and add file or read file under the log folder
*/

#include <iostream>       // I/O library
#include <string>        // Library to manage strings
#include <fstream>      // library for file input Output

using namespace std;

// This function will get the data from the file
// Input :- hp of player and map positions and map size
// Ourput :- Doesn't return but saves the file.
void retrievedata(int &hp,char** &map,int &size, int & pos_x, int & pos_y){
    string filename;
    string positions;
    char prompt,word;

    cout << "----------------------------------- LOADING PREVIOUS GAME... ----------------------------" << endl;
    cout << "Enter file name: ";

     while (true) {
        cin >> filename;
        cout << endl;

        // Add extention if not
        if (filename.rfind(".txt") == -1){
            filename += ".txt";
        }
        filename = "log/" + filename;

        ifstream fin;
        fin.open(filename.c_str());

        if (fin.fail()) {
            cout << "Unable to Open File try another name- SORRY FOR INCONVENIENCE!!!" << endl;
            continue;
        }


        getline(fin,positions);

        fin >> size;
        map =  new char*[size];

        for (int i = 0; i < size; i++)
        {
            map[i] = new char [size];

        }
        // adding values to map from file
        for (int i=0;i<size;i++){
            for (int j=0;j<size;j++){
                map[i][j] = positions[i+j+(size-1) * i];
            }
        }

        fin >> hp >> pos_x >> pos_y;
        fin.close();
        break;

    }



}


// This function will send the data to the file
// Input :- hp of player and map positions and map size
// Ourput :- Doesn't return but saves the file.
void savedata(int hp,char** &map,int size, int pos_x, int pos_y){

    string filename;
    char prompt;

    cout << "----------------------------------- SAVING GAME... ----------------------------" << endl;
    cout << "Enter file name or press B to go {Back}: ";

     while (true) {
        cin >> filename;


        //check user input
        //case exit
        if (filename == "B" || filename == "b" || filename == "back" || filename == "Back") {
            return;
        }
        // Ass extention if not
        if (filename.rfind(".txt") == -1){
            filename += ".txt";
        }
        filename = "log/" + filename;

    //check if file already exist
        ifstream fin;
        fin.open(filename.c_str());
        if (!fin.fail()) {
            cout << "Error, file already exist.";
            cout << "Do you wish to create a new file:Y or N : ";
            cin >> prompt;
            if (prompt == 'Y' || prompt == 'y') {
                continue;
            }
        }
        fin.close();

        ofstream fout;
        fout.open(filename.c_str());
        if (fout.fail()) {
            cout << "Error saving file. Please try again : ";
            continue;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fout << map[i][j];
            }
        }
        fout << endl;
        fout << size << endl;
        fout << hp << endl;
        fout << pos_x << endl;
        fout << pos_y << endl;

        fout.close();
        break;


    }




}

// ***************** Main finction to test the code (Working well) - All Hail Mubeen Sama**************************
// int main(int argc, char const *argv[])
// {
//     int size=5;
//     int hp=0;
//     // cin >> size;

//     char ** map = new char* [size];

//     for (int i=0;i<size;i++){
//         map[i]= new char [size];
//     }

//     retrievedata(hp,map,size);

//     cout << hp << " " << size << endl;

//     for (int i=0;i<size;i++){
//         for (int j=0;j<size;j++){
//             cout << map[i][j] << " ";
//         }
//     }




//     // savedata(5,map,size);

//     return 0;
// }
