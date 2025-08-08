#include "Dijkstra.h"

void PrintBoard(vector<vector<int>> Board) {

<<<<<<< HEAD
void PrintBoard(vector<vector<States>> Board){

    for (auto i: Board){
        for (auto j: i){
            // cout<< j << " "; 
            cout<<GridSymbol(j);
        }
        cout << "\n" <<"";
=======
  for (auto i : Board) {
    for (auto j : i) {
      cout << j << " ";
>>>>>>> 151abf26d545991c1a2e32d90b944cd84b4758d3
    }
    cout << "\n" << "";
  }
}

<<<<<<< HEAD
vector<States> Readline(string line){
=======
vector<int> Readline(string line) {
>>>>>>> 151abf26d545991c1a2e32d90b944cd84b4758d3

  istringstream Newline(line);
  //   int n;
  char k;
  int n;
<<<<<<< HEAD
  vector <States> row;
  while(Newline>> n >> k && k ==',') { //checking if there is still characters in the line and the character is followed by ',' then the end of line is not reached
=======
  vector<int> row;
  while (
      Newline >> n >> k &&
      k == ',') { // if there is still characters in the line and the character
                  // is followed by ',' then the end of line is not reached
>>>>>>> 151abf26d545991c1a2e32d90b944cd84b4758d3

    if(n==0){
        row.push_back(States::kEmpty);
    }
    else{
        row.push_back(States::kObstacle);
    }
   
  }
  return row;
}

<<<<<<< HEAD
vector<vector<States>> Readboard(string boardfile){

    ifstream gridfile(boardfile);
    vector<vector<States>> board;
    if (gridfile){
        string j;
      while(getline(gridfile,j)){ // checks that the end of the board is reached or not

        vector<States> row= Readline(j);
=======
vector<vector<int>> Readboard(string boardfile) {

  ifstream gridfile(boardfile);
  vector<vector<int>> board;
  if (gridfile) {
    string j;
    while (getline(gridfile,
                   j)) { // checks that the end of the board is reached or not

      vector<int> row = Readline(j);
>>>>>>> 151abf26d545991c1a2e32d90b944cd84b4758d3

      board.push_back(row);
    }
  }

<<<<<<< HEAD
    } 
}

return board;
}

string GridSymbol(States Symbol){

    switch (Symbol){
        case States::kEmpty: return" 🟢 ";
        case States::kObstacle: return" ⛰️ ";
        case States::kPath: return" 🚗 ";
        case States::kStart: return" 🚦 ";
        case States::kFinish: return" 🏁 ";
        case States::kClosed: return" ❌ ";
        default: return"0";
    }
    


=======
  return board;
>>>>>>> 151abf26d545991c1a2e32d90b944cd84b4758d3
}