#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

const int neigborhood[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
enum class States { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

void PrintBoard(vector<vector<States>> Board);
vector<States> Readline(string line);
vector<vector<States>> Readboard(string boardfile);
string GridSymbol(States Symbol);
bool checkvalidity(vector<int> point, vector<vector<States>> &board);
void AddToOpen(int x, int y, int g, int x_pre, int y_pre, vector<vector<int>> &openlist, vector<vector<States>> &grid);
void PrintBoardInt(vector<vector<int>> board);
void expandsearch(vector<int> Point, vector<vector<States>> &grid, vector<vector<int>> &openlist);
void Path(vector<vector<int>> &openlist, vector<vector<States>> &grid);
vector<vector<int>> addToPath(int x,int y,vector<vector<States>> &grid);

#endif