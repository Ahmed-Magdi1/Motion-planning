#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;

vector<int> ReadLine(string line){
    istringstream Nline(line);
    int n;
    char k;
    // string o = "1";
    vector<int> row_vec;
    while (Nline >> n >> k && k == ',') // When you find int followed by char that is equal to ','
    {
        if (n ==0){
            row_vec.push_back(n);  // Empty
        }  else {
            row_vec.push_back(1); // Obstacles
        }
    }
    return row_vec;
}

vector<vector<int>> ReadBoard(string path) {
    ifstream gridfile(path);
    vector<vector<int>> board{};
    if (gridfile){
        string j;
        while (getline(gridfile, j))
        {
            vector<int> row = ReadLine(j);
            board.push_back(row);
        }
    }
    return board;
}

int main(){
    auto board = ReadBoard("grid.txt"); // Path to the grid file
}
