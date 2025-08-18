#include "Dijkstra.h"

int main()
{
  // int init[2] = {1, 3};
  // int goal[2] = {3, 1};
  vector<int> init={0,0};
  vector<int> goal={3,3};
  auto board = Readboard("grid.board");



  // /* * * * * * * *  2D vector for testing * * * * * * * */
  // vector<vector<int>> boardInt{{1, 2, 3, 4, 5},
  //                              {1, 2, 3, 4, 5},
  //                              {1, 2, 3, 4, 5}};
  // vector<int> testing {0, 0, 0};
  // // PrintBoard(board); // Function to print a 2D vector
  // vector<int> test={init[0],init[1],goal[0],goal[1]};
  // vector<vector<int>> openlist = {{0, 0, 1, 0, 0},
  //                                 {0, 1, 1, 0, 0},
  //                                 {0, 2, 2, 0, 1},
  //                                 {0, 3, 3, 0, 2},
  //                                 {0, 4, 3, 0, 3},
  //                                 {1, 4, 3, 0, 4},
  //                                 {2, 4, 3, 1, 4}};
  // // {1,-3,4,0,-3},{2,-3,5,1,-3},{3,-3,6,2,-3}};
  // // Path(openlist, board);
  // // PrintBoard(board);
  // // 
  // // checkvalidity(test, board);
  // // AddToOpen(1, 2, 7, 4, 5, boardInt, board);
  // // PrintBoardInt(boardInt);
  // // PrintBoard(board);
  // expandsearch(testing, board, boardInt);
  // PrintBoardInt(boardInt);
  // // PrintBoard(board);

  Search(init,goal,board);
 
  
}

