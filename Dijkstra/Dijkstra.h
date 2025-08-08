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


enum class States{
    kEmpty,kObstacle,kClosed,kPath,kStart,kFinish,
};

void PrintBoard(vector<vector<States>> Board);
vector<States> Readline(string line);
vector<vector<States>> Readboard(string boardfile);
string GridSymbol(States Symbol);

#endif