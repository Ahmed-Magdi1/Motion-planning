#include "A_star.h"

int main(){
    array<array<int,2>,2> StartGoalPoints;
    int h;
    auto board = ReadBoard("grid.txt"); // Path to the grid file
    PrintGrid(board);
    StartGoalPoints=StartGoal(board);
    h=Heurestic(StartGoalPoints);
    cout<<h;
}
