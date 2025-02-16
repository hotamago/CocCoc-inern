#ifndef CLI_H
#define CLI_H
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "../graph/graph.h"
#include "../robot/robot.h"
using namespace std;

void processCommands(const string& filename, Grid& grid, Robot& robot);

#endif // CLI_H