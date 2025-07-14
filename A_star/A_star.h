#ifndef A_STAR_H
#define A_STAR_H
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::array;
using std::string;
using std::ifstream;
using std::istringstream;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

void PrintGrid (vector<vector <State>> Grid);
void PrintGridInt(vector<vector<int>> board);
vector<State> ReadLine(string line);
vector<vector<State>> ReadBoard(string path);
array<array<int,2>,2> StartGoal(vector<vector<State>> board);
int Heurestic(array<array<int,2>,2> Points);
bool Compare(vector<int> a, vector<int> b);
bool CheckValidCell(int x, int y, vector<vector<State>> board);
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid);
void ExpandNeighborhood(array<array<int,2>,2> Points, vector<vector <State>> &Grid,int g,vector<vector<int>> &openlist);




#endif