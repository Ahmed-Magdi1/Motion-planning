#include "A_star.h"


int main(){
    
    auto board = ReadBoard("grid.txt"); // Path to the grid file
    PrintGrid(board);
    // array<array<int,2>,2> StartGoalPoints=StartGoal(board);
    bool cell=CheckValidCell(1,0,board);
    cout<<cell<<"\n";
     

}
