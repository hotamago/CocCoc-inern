#include "cli.h"

// Function to parse and process commands from input file
void processCommands(const string& filename, Grid& grid, Robot& robot) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw runtime_error("Could not open input file: " + filename);
    }

    bool dimensionSet = false;
    string line;

    while (getline(inputFile, line)) {
        line = trim(line);
        if (line.empty()) continue;

        string command, params;
        size_t spacePos = line.find(' ');
        if (spacePos != string::npos) {
            command = line.substr(0, spacePos);
            params = trim(line.substr(spacePos + 1));
        } else {
            command = line;
            params = "";
        }

        if (command == "DIMENSION") {
            if (dimensionSet) {
                throw runtime_error("DIMENSION command can only be set once");
            }
            int N;
            try {
                N = stoi(params);
            } catch (const exception& e) {
                throw runtime_error("Invalid DIMENSION parameter: " + params);
            }
            if (N <= 0) {
                throw runtime_error("DIMENSION must be a positive integer");
            }
            dimensionSet = true;
            grid.setSize(N);
        } else if (command == "MOVE_TO" || command == "LINE_TO") {
            if (!dimensionSet) {
                throw runtime_error("DIMENSION must be set before other commands");
            }
            // Split parameters into x and y
            stringstream paramStream(params);
            string token;
            vector<string> xyStr;
            while (getline(paramStream, token, ',')) {
                xyStr.push_back(trim(token));
            }
            if (xyStr.size() != 2) {
                throw runtime_error("Invalid parameters for " + command + ": " + params);
            }
            int x, y;
            try {
                x = stoi(xyStr[0]);
                y = stoi(xyStr[1]);
            } catch (const exception& e) {
                throw runtime_error("Invalid coordinates for " + command + ": " + params);
            }
            if (x < 0 || x >= grid.getSize() || y < 0 || y >= grid.getSize()) {
                throw runtime_error("Coordinates (" + to_string(x) + ", " + to_string(y) + ") out of bounds");
            }
            if (command == "MOVE_TO") {
                robot.moveTo(x, y);
            } else {
                robot.lineTo(x, y);
            }
        } else {
            throw runtime_error("Unknown command: " + command);
        }
    }

    if (!dimensionSet) {
        throw runtime_error("No DIMENSION command found");
    }
}