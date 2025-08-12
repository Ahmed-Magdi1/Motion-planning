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

void PrintBoardInt(vector<vector<int>> board) {
    for (auto i: board){
        for (auto j: i){
            cout<< j << " "; 
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
    if (board[x][y] == States::kEmpty) {
      return true;
    }
    return false;
  } else {
    return false;
  }
}

void AddToOpen(int x, int y, int g, int x_pre, int y_pre, vector<vector<int>> &openlist, vector<vector<States>> &grid){
  openlist.push_back(vector<int> {x, y, g, x_pre, y_pre});
  grid[x][y] = States::kClosed;
}

void expandsearch(vector<int> Point, vector<vector<States>> &grid, vector<vector<int>> &openlist){
  int x_current = Point[0];
  int y_current = Point[1];
  int g_current = Point[2];

  for (int i = 0; i < 4; i++) {
    int x_new = x_current + neigborhood[i][0];
    int y_new = y_current + neigborhood[i][1];
    vector<int> checkpoint{x_new, y_new};
    if (checkvalidity(checkpoint, grid)) {
      vector<int> validpoint{x_new, y_new, g_current, x_current, y_current};
      AddToOpen(x_new, y_new, g_current, x_current, y_current, openlist, grid);
    }
  }
}