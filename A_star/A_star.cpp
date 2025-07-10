#include "A_star.h"

void PrintGrid (vector<vector <int>> Grid){
    
    for (int i=0;i<Grid.size();i++){
        for(int j=0; j<Grid[i].size(); j++){
            cout<<Grid[i][j];
            
        }
        cout<<"\n";
    }
    
}

vector<int> ReadLine(string line){
    istringstream Nline(line);
    int n;
    char k;
    // string o = "1";
    vector<int> row_vec;
    while (Nline >> n >> k && k == ',') // When you find int followed by char that is equal to ','
    {
        if (n ==0){
            row_vec.push_back(n);  // Empty
        }  else {
            row_vec.push_back(1); // Obstacles
        }
    }
    return row_vec;
}

vector<vector<int>> ReadBoard(string path) {
    ifstream gridfile(path);
    vector<vector<int>> board{};
    if (gridfile){
        string j;
        while (getline(gridfile, j))
        {
            vector<int> row = ReadLine(j);
            board.push_back(row);
        }
    }
    return board;
}

array<array<int,2>,2> StartGoal(vector<vector<int>> board){
    array<array<int,2>,2>StartGoal;
    cout<<"Please enter the starting point as x,y\n";
    cin>>StartGoal[0][0]>>StartGoal[0][1];
    cout<<"Please enter the goal point as x,y to find the path\n";
    cin>>StartGoal[1][0]>>StartGoal[1][1];
    if(board [StartGoal[0][0]][StartGoal[0][1]]==1 || board [StartGoal[1][0]][StartGoal[1][1]]==1){
        cout<<"invalid start/goal points\n";
        exit;
    }

    return StartGoal;

}

int Heurestic(array<array<int,2>,2> Points){

  return abs(Points[1][0]-Points[0][0])+abs(Points[1][1]-Points[0][1]); 
}

bool Compare(vector<int> a, vector<int> b){
    /*  open list   */
    /*  x, y, g, h  */

    int f1 = a[2] + a[3]; // F1 = g1 + h1
    int f2 = b[2] + b[3]; // F2 = g2 + h2
    return f1>f2;
}


