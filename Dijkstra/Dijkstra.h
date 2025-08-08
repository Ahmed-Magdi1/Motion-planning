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

enum class States { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

void PrintBoard(vector<vector<States>> Board);
vector<States> Readline(string line);
vector<vector<States>> Readboard(string boardfile);
string GridSymbol(States Symbol);
bool checkvalidity(vector<int> point, vector<vector<States>> &board);

#endif