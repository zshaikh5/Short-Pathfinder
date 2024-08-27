//Zaina Shaikh
//Assignment 2: robo.cpp
#include <iostream>
#include "robo.h"

Robot::Robot(int max, int bot_x, int bot_y, int treas_x, int treas_y) 
{
    max_ = max; 
    robot_ = {bot_x, bot_y};
    treasure_ = {treas_x, treas_y};
    directions_ = {}; 
    TreasDirections(robot_, treasure_, "", 0, 0, 0, 0);
}

void Robot::Print() 
{
    if (directions_.size() > 0)
    {
        cout << "Paths:" << endl;
        for (int i = 0; i < directions_.size(); i++) 
        {
            cout << directions_[i] << endl;
        }
        cout << "Total Number of Paths: " << directions_.size() << endl;
    }
    else 
    {
        cout << "No Paths found" << endl << "Total Number of Paths = 0" << endl; 
    }
}

void Robot::TreasDirections(Point bot, Point treas, string current_paths, int north, int south, int east, int west) {
    
    int shortest_path = abs(bot.x - treas.x) + abs(bot.y - treas.y);
  
    if (bot.x == treas.x && bot.y == treas.y & shortest_path == 0) 
    {
        directions_.push_back(current_paths);
        return;
    }
    if (bot.y < treas.y && north < max_) 
    {
        TreasDirections(Point{bot.x, bot.y + 1}, treas, current_paths + 'N', north+1, 0, 0, 0);
    }
    if (bot.y > treas.y && south < max_) 
    {
        TreasDirections(Point{bot.x, bot.y - 1}, treas, current_paths + 'S', 0, south+1, 0, 0);
    }
    if (bot.x < treas.x  && east < max_) 
    {
        TreasDirections(Point{bot.x + 1, bot.y}, treas, current_paths + 'E', 0, 0, east+1, 0);
    }
    if (bot.x > treas.x  && west < max_) 
    {
        TreasDirections(Point{bot.x - 1, bot.y}, treas, current_paths + 'W', 0, 0, 0, west+1);
    }
}