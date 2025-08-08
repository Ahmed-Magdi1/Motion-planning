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

void PrintBoard(vector<vector<char>> Board);
vector<char> Readline(string line);
vector<vector<char>> Readboard(string boardfile);

#endif