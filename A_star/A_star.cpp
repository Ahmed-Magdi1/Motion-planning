#include "A_star.h"

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return " ⛰️ ";
    case State::kPath: return " 🚗 ";
    case State::kStart: return " 🚦 ";
    case State::kFinish: return " 🏁 ";
    case State::kClosed: return " ❌ ";
    default: return " 0 "; 
  }
}

void PrintGridInt(vector<vector<int>> board) {

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
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
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid){
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

array<array<int,2>,2> StartGoal(vector<vector<State>> &board){
    array<array<int,2>,2>StartGoal;
    cout<<"Please enter the starting point as x,y\n";
    cin>>StartGoal[0][0]>>StartGoal[0][1];
    cout<<"Please enter the goal point as x,y to find the path\n";
    cin>>StartGoal[1][0]>>StartGoal[1][1];
    if (StartGoal[0][0] < 0 || StartGoal[0][0] >= board.size() || 
        StartGoal[0][1] < 0 || StartGoal[0][1] >= board[0].size() ||
        StartGoal[1][0] < 0 || StartGoal[1][0] >= board.size() || 
        StartGoal[1][1] < 0 || StartGoal[1][1] >= board[0].size()) {
        cout << "Coordinates out of bounds\n";
        exit(1);
    }
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
  if (board.empty() || board[0].empty()) return false; 
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

void ExpandNeighborhood(array<array<int, 2>, 2> Points, vector<vector<State>> &Grid, int &g, vector<vector<int>> &openlist) {
  int current_x = Points[0][0], current_y = Points[0][1], end_x = Points[1][0], end_y = Points[1][1];
  int h;
  int curr_g=g;
  array<array<int, 2>, 2> NewPoints;
  vector<vector<int>> neigborhood = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  for (int i=0; i < neigborhood.size(); i++) {
    int x2 = current_x + neigborhood[i][0];
    int y2 = current_y + neigborhood[i][1];
    NewPoints = {{{x2, y2}, {end_x, end_y}}};
    if (CheckValidCell(x2, y2, Grid)) {
      h = Heurestic(NewPoints);
      int g2=curr_g+1;
      AddToOpen(x2, y2, g2, h, openlist, Grid);
    }
  }
}

vector<vector<State>> Search(array<array<int, 2>, 2> Points,vector<vector<State>> board){
  int g=0;
  int x,y;
  vector<vector<int>> openlist{};
  
  x=Points[0][0];
  y=Points[0][1];
  int h=Heurestic(Points);
  
  AddToOpen(x, y, g, h, openlist, board);
  cout<<openlist[0][3];
  while(openlist.size()>0){
   
    Sort(&openlist);
      auto Path= openlist.back();
      x=Path[0];
      y=Path[1];
      board[x][y]=State::kPath;
      array<array<int,2>,2> CurrentPoints={{{x,y},{Points[1][0],Points[1][1]}}};
      openlist.pop_back();
      cout<<"yes\n";
      
      // if(x==StartGoalPoints[1][0]&&y==StartGoalPoints[1][1]){
      //   PrintGrid(board);

      // }  
      if (x==Points[1][0]&&y==Points[1][1]){
        board[Points[0][0]][Points[0][1]]=State::kStart;
        board[Points[1][0]][Points[1][1]]=State::kFinish;
        PrintGrid(board);

        return board;
      
    } 
    int current_g = Path[2]; 
    ExpandNeighborhood(CurrentPoints,board,current_g,openlist);  
    }
    return std::vector<vector<State>> {};

  

}

void Sort(vector<vector<int>> *F){
  sort(F->begin(),F->end(),Compare);
}
// void blabla(){
//   Sort(openlist);
//     vector<int> Path= openlist.back();
//     x=Path[0];
//     y=Path[1];
//     // cout<<Path[0]<<"\n";
//     // cout<<Path[1]<<"\n";
//     // cout<<Path[2]<<"\n";
//     // cout<<Path[3]<<"\n";
//     PrintGridInt(openlist);
//     openlist.pop_back();
//     // cout<<openlist.size()<<"\n";
    
//     // board[x][y]=State::kPath;    
//     // array<array<int,2>,2> CurrentPoints={{{x,y},{StartGoalPoints[1][0],StartGoalPoints[1][1]}}};
//     // ExpandNeighborhood(CurrentPoints,board,g,openlist);




// }