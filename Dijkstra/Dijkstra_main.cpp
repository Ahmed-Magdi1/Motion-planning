#include "Dijkstra.h"

int main() {
  int init[2] = {1, 3};
  int goal[2] = {3, 1};
  /* * * * * * * *  2D vector for testing * * * * * * * */
  // vector<vector<int>> board{{1, 2, 3, 4, 5},
  //                           {1, 2, 3, 4, 5},
  //                           {1, 2, 3, 4, 5}};
  // vector<int> testing {4,0,3,4};
  // PrintBoard(board); // Function to print a 2D vector
  auto board = Readboard("grid.board");
  //   vector<int> test{init[0], init[1], goal[0], goal[1]};
  //   checkvalidity(test, board);
  // PrintBoard(board);
}