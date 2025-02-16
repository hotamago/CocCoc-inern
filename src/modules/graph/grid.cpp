#include "graph.h"

// Implementation of Grid member functions
Grid::Grid() : size(0) {}

void Grid::setSize(int N) {
    size = N;
    cells.assign(N, vector<char>(N, '.'));
}

int Grid::getSize() const {
    return size;
}

void Grid::mark(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        cells[y][x] = '+';
    }
}

void Grid::print() const {
    for (const auto& row : cells) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i != row.size() - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}