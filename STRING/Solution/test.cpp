#include <iostream>
#include <fstream>
#include <cmath>
std::ofstream cout("string.inp");

int main()
{
    for (int i = 0, range = std::pow(10, 6); i < range; ++i)
    {
        cout << 'a';
    }

    return 0;
}