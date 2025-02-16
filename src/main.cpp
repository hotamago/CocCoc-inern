#include "modules/graph/graph.h"
#include "modules/robot/robot.h"
#include "modules/cli/cli.h"

using namespace std;
Grid grid;
Robot robot(grid);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input-file>" << endl;
        return 1;
    }

    try {
        processCommands(argv[1], grid, robot);
        grid.print();   
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}