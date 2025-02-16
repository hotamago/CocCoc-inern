#include "helper.h"

// Function: bresenhamLine
// Draws a line from (x0, y0) to (x1, y1) using Bresenham's algorithm.
// For each point on the line, the provided callback is invoked.
void bresenhamLine(int x0, int y0, int x1, int y1, std::function<void(int, int)> callback) {
    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    while (true) {
        callback(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}
