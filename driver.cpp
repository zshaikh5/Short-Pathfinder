//Zaina Shaikh
//Assignment 2: driver.cpp

#include "robo.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 6) 
    {
        cout << "ERROR, please enter the following values: " << " [max] [robot_x] [robot_y] [treasure_x] [treasure_y]\n";
        return 0;
    }

    int max_distance = stoi(argv[1]);
    int bot_x = stoi(argv[2]);
    int bot_y = stoi(argv[3]);
    int treas_x = stoi(argv[4]);
    int treas_y = stoi(argv[5]);
    
    // Error Handling
    if(max_distance <= 0 || max_distance > 15)
    {
        cout << "ERROR: Max Distance must be between 1 and 15" << endl; 
        return 0;
    }

    if(bot_x > 15 || bot_x < -15 || bot_y > 15 || bot_y < -15)
    {
        cout << "ERROR: Please Enter Coordinates between -15 and 15" << endl; 
        return 0; 
    }

    if(treas_x > 15 || treas_x < -15 || treas_y > 15 || treas_y < -15)
    {
        cout << "ERROR: Please Enter Coordinates between -15 and 15" << endl; 
        return 0; 
    }

    if (bot_x == treas_x && bot_y == treas_y)
    {
        cout << "Robot and Treasure are at the Same Location" << endl;
        return 0;
    }

    Robot robot(max_distance, bot_x, bot_y, treas_x, treas_y);
    robot.Print();
}