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
    return false;}
    else{
      return false;
    }

}

void Path(vector<vector<int>> &openlist, vector<vector<States>> &grid)
{

  int &point_x = openlist[openlist.size() - 1][3];
  int &point_y = openlist[openlist.size() - 1][4];
  int start_pre_x = openlist[0][0];
  int start_pre_y = openlist[0][1];
  bool finish = true;

  while (finish)
  {
    if (point_x != start_pre_x || point_y != start_pre_y)
    {

      for (int i = 0; i < openlist.size(); i++)
      {

        int new_point_x = openlist[i][0];
        int new_point_y = openlist[i][1];

        if (new_point_x == point_x && new_point_y == point_y)
        {
          vector<vector<int>> path = addToPath(new_point_x, new_point_y, grid);
          cout << i << "\n";
          point_x = openlist[i][3];
          point_y = openlist[i][4];
          
        }
      }
    }
    else
    {
      finish = false;
    }
  }
}

vector<vector<int>> addToPath(int x, int y, vector<vector<States>> &grid)
{
  vector<vector<int>> pathlist;
  pathlist.push_back({x, y});
  grid[x][y] = States::kPath;
  return pathlist;
}


void AddToOpen(int x, int y, int g, int x_pre, int y_pre, vector<vector<int>> &openlist, vector<vector<States>> &grid){
  openlist.push_back(vector<int> {x, y, g, x_pre, y_pre});
  
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
      // vector<int> validpoint{x_new, y_new, g_current, x_current, y_current};
      AddToOpen(x_new, y_new, g_current, x_current, y_current, openlist, grid);
      grid[x_new][y_new] = States::kClosed;
    }
  }
}

void Search(vector<int> start_point, vector<int> goal_point, vector<vector<States>> &grid){
  int i=0;
  int &curr_x=start_point[0];
  int &curr_y=start_point[1];
  int g=0;
  int &curr_g=g;
  vector<int> point={curr_x,curr_y,curr_g};
  bool flag=true;
  vector<vector<int>> openlist;
  grid[goal_point[0]][goal_point[1]]=States::kFinish;
  grid[start_point[0]][start_point[1]]=States::kStart;



  AddToOpen(start_point[0],start_point[1],curr_g,start_point[0],start_point[1],openlist,grid);
  // 
  while(grid[curr_x][curr_y]!=States::kFinish){
    curr_g++;
    point={curr_x,curr_y,curr_g};
    expandsearch(point,grid,openlist);
    i++;
    cout<<i<<"\n";
    cout<<"////////////////////////////////\n";
    PrintBoardInt(openlist);
    cout<<"////////////////////////////////\n";
    cout<<i<<"\n";
    curr_x=openlist[i][0];
    curr_y=openlist[i][1];
    cout<<i<<"\n";
    cout<<curr_x<<","<<curr_y<<"\n";
         
  }
  // AddToOpen(goal_point[0],goal_point[1],curr_g+1,curr_x,curr_y,openlist,grid);
  // cout<<"////////////////////////////////\n";
  // PrintBoardInt(openlist);
  // cout<<"////////////////////////////////\n";
  Path(openlist,grid);
  PrintBoard(grid);

}