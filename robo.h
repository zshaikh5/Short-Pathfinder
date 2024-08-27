//Zaina Shaikh
//Assignment 2: robo.h

#ifndef ROBO_H_
#define ROBO_H_

#include <vector>
#include <iostream>
#include <string> 
using namespace std;

struct Point 
{
    int x;
    int y;
};

class Robot {
public:
    Robot(int max, int bot_x, int bot_y, int treas_x, int treas_y);
    void Print();
    void TreasDirections(Point robot, Point treasure, string current_paths, int north, int south, int east, int west);

private:
    int max_;
    Point robot_;
    Point treasure_;
    vector<string> directions_;
};
#endif