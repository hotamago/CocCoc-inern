#include "robot.h"

void Robot::moveTo(int x, int y) {
    currentX = x;
    currentY = y;
}

void Robot::lineTo(int x, int y) {
    int x0 = currentX;
    int y0 = currentY;
    int x1 = x;
    int y1 = y;

    auto plot = [this](int x, int y) {
        grid.mark(x, y);
    };

    bresenhamLine(x0, y0, x1, y1, plot);

    currentX = x;
    currentY = y;
}