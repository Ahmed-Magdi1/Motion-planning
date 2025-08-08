#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>


using std::cout;
using std::vector;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::string;

void PrintBoard(vector<vector<int>> Board);
vector<int> Readline(string line);
vector<vector<int>> Readboard(string boardfile);

#endif