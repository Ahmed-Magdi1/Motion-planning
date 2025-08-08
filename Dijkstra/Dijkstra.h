#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

void PrintBoard(vector<vector<int>> Board);
vector<int> Readline(string line);
vector<vector<int>> Readboard(string boardfile);
bool checkvalidity(vector<int> point, vector<vector<int>> &board);

#endif