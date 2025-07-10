#include "A_star.h"
array<array<int,2>,2> StartGoalPoints;

int main(){
    
    auto board = ReadBoard("grid.txt"); // Path to the grid file
    PrintGrid(board);
    StartGoalPoints=StartGoal(board);
    



    

}
