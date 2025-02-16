#if !defined(__HELPER_H__)
#define __HELPER_H__
#include <functional>
#include <iostream>

using namespace std;

// Function: bresenhamLine
// Draws a line from (x0, y0) to (x1, y1) using Bresenham's algorithm.
void bresenhamLine(int x0, int y0, int x1, int y1, function<void(int, int)> callback);

// Function: trim
// Trims leading and trailing whitespaces from a string.
string trim(const string& str);

#endif // __HELPER_H__