#include "Dijkstra.h"


void PrintBoard(vector<vector<int>> Board){

    for (auto i: Board){
        for (auto j: i){
            cout<< j << " ";  
        }
        cout << "\n" <<"";
    }
}