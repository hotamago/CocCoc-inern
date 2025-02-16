#ifndef GRAPH_H
#define GRAPH_H

#include <math.h>
#include <functional>
#include <iostream>
#include <vector>  // added
using namespace std;

class Grid {
    public:
        Grid();  // added constructor declaration
        int getSize() const;
        void setSize(int N);
        void mark(int x, int y);
        void print() const;
    private:
        int size;  // added member
        vector<vector<char>> cells;  // added member
};

#endif // GRAPH_H
