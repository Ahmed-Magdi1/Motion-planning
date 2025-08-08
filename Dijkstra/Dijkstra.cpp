#include "Dijkstra.h"


void PrintBoard(vector<vector<int>> Board){

    for (auto i: Board){
        for (auto j: i){
            cout<< j << " ";  
        }
        cout << "\n" <<"";
    }
}

vector<int> Readline(string line){

  istringstream Newline(line);
//   int n;
  char k;
  int n;
  vector <int> row;
  while(Newline>> n >> k && k ==',') { //if there is still characters in the line and the character is followed by ',' then the end of line is not reached

    row.push_back(n);
  }
  return row;
}

vector<vector<int>> Readboard(string boardfile){

    ifstream gridfile(boardfile);
    vector<vector<int>> board;
    if (gridfile){
        string j;
      while(getline(gridfile,j)){ // checks that the end of the board is reached or not

        vector<int> row= Readline(j);

        board.push_back(row);
        

    } 
}



return board;
}