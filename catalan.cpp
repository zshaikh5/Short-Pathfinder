//Zaina Shaikh
//Assignment 2: catalan.cpp

#include <iostream>
using namespace std; 

int Catalan(int value)
{
    int total = 0; 
    if(value == 0 || value == 1)
    {
        return 1; 
    }
    for(int i=0; i<value; i++)
    {
        total+= Catalan(i)*Catalan(value-i-1); 
    }

    return total; 
} 

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "ERROR: incorrect parameter" << endl; 
        return 1; 
    }

    int input_val = stoi(argv[1]); 

    if(input_val < 0) 
    {
        cout << "ERROR: The input is negative" << endl; 
    }
    if (input_val > 19)
    {
        cout << "ERROR: The input is too large" << endl; 
    }
    else
    {
        cout << "The catalan number is: " << Catalan(input_val) << endl; 
    }
    return 0; 
}
