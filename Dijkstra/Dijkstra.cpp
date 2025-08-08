#include "Dijkstra.h"

void PrintBoard(vector<vector<States>> Board) {

    for (auto i: Board){
        for (auto j: i){
            // cout<< j << " "; 
            cout<<GridSymbol(j);
        }
        cout << "\n" <<"";
    }
  
}


vector<States> Readline(string line) {

  istringstream Newline(line);
  //   int n;
  char k;
  int n;
  vector <States> row;
  while(Newline>> n >> k && k ==',') { //checking if there is still characters in the line and the character is followed by ',' then the end of line is not reached
  
    if(n==0){
        row.push_back(States::kEmpty);
    }
    else{
        row.push_back(States::kObstacle);
    }
   
  }
  return row;
}

vector<vector<States>> Readboard(string boardfile){

    ifstream gridfile(boardfile);
    vector<vector<States>> board;
    if (gridfile){
        string j;
      while(getline(gridfile,j)){ // checks that the end of the board is reached or not
  
        vector<States> row= Readline(j);
        board.push_back(row);
        

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

}

bool checkvalidity(vector<int> point, vector<vector<States>> &board) {
  int x = point[0];
  int y = point[1];
  if (x <= board.size() && y <= board[0].size()) {
    cout << "You are on the grid" << "\n";
    if (board[x][y] == States::kEmpty) {
      cout << "The cell is empty" << "\n";
    }
    return true;
  } else {
    cout << "You are out of grid" << "\n";
    return false;
  }
}