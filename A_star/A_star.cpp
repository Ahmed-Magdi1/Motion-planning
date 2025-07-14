#include "A_star.h"


string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦   ";
    case State::kFinish: return "🏁   ";
    default: return "0   "; 
  }
}

void PrintGrid (vector<vector <State>> Grid){
    
    for (int i=0;i<Grid.size();i++){
        for(int j=0; j<Grid[i].size(); j++){
            cout<<CellString(Grid[i][j]);
        }
        cout<<"\n";
    }
    
}

// Add a node to the open list 
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> grid){
  // Add node to open vector 
  openlist.push_back(vector<int> {x, y, g, h});
  grid[x][y] = State::kClosed; // Mark grid cell as closed
}

// Compare the F values of two node in the open list
bool Compare(vector<int> a, vector<int> b){
    /*  open list   */
    /*  x, y, g, h  */

    int f1 = a[2] + a[3]; // F1 = g1 + h1
    int f2 = b[2] + b[3]; // F2 = g2 + h2
    return f1>f2;
}

vector<State> ReadLine(string line){
    istringstream Nline(line);
    int n;
    char k;
    // string o = "1";
    vector<State> row_vec;
    while (Nline >> n >> k && k == ',') // When you find int followed by char that is equal to ','
    {
        if (n ==0){
            row_vec.push_back(State::kEmpty);  // Empty
        }  else {
            row_vec.push_back(State::kObstacle); // Obstacles
        }
    }
    return row_vec;
}

vector<vector<State>> ReadBoard(string path) {
    ifstream gridfile(path);
    vector<vector<State>> board{};
    if (gridfile){
        string j;
        while (getline(gridfile, j))
        {
            vector<State> row = ReadLine(j);
            board.push_back(row);
        }
    }
    return board;
}

array<array<int,2>,2> StartGoal(vector<vector<State>> board){
    array<array<int,2>,2>StartGoal;
    cout<<"Please enter the starting point as x,y\n";
    cin>>StartGoal[0][0]>>StartGoal[0][1];
    cout<<"Please enter the goal point as x,y to find the path\n";
    cin>>StartGoal[1][0]>>StartGoal[1][1];
    if(board [StartGoal[0][0]][StartGoal[0][1]]==State::kObstacle || board [StartGoal[1][0]][StartGoal[1][1]]==State::kObstacle){
        cout<<"invalid start/goal points\n";
        exit(1);
    }

    return StartGoal;

}

int Heurestic(array<array<int,2>,2> Points){

  return abs(Points[1][0]-Points[0][0])+abs(Points[1][1]-Points[0][1]); 
}

bool CheckValidCell(int x, int y, vector<vector<State>> board) {

  bool cell;
  bool x_on_grid = (x >= 0 && x < board.size());
  bool y_on_grid = (y >= 0 && y < board[0].size());
  if (x_on_grid && y_on_grid) {
    if (board[x][y] == State::kEmpty) {
      cell = true;
    } else {
      cell = false;
    }
  } else {
        cout << "point out of grid\n";
        cell = false;
  }
  return cell;
}
