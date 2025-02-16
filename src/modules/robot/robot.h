#ifndef ROBOT_H
#define ROBOT_H
#include "../graph/graph.h"
#include "../helper/helper.h"
#include <functional>

using namespace std;

class Robot {
    public:
        Robot(Grid& grid) : grid(grid), currentX(0), currentY(0) {}
        void moveTo(int x, int y);
        void lineTo(int x, int y);
    private:
        Grid& grid;
        int currentX;
        int currentY;
    };

#endif // ROBOT_H