// main.cpp ****************

#include <iostream>
#include "Player.h"

using namespace std;

int main() 
{
    cin.ignore();
    srand(time(0));
    cout << " \n\t\t /**********************************************\\n\n";
    cout << " \t\tCricket Match Between Asad Raza And Computer Teams\n\n";
    cout << " \t\t/**********************************************\\n\n";
    CricketMatch match("Asad Raza", "The Computer");
    match.play();
    return 0;
}