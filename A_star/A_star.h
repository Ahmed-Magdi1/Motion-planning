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





void PrintGrid (vector<vector <int>> Grid);
vector<int> ReadLine(string line);
vector<vector<int>> ReadBoard(string path);
array<array<int,2>,2> StartGoal(vector<vector<int>> board);
int Heurestic(array<array<int,2>,2> Points);

#endif