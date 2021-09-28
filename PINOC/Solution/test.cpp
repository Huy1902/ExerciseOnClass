#include <bits/stdc++.h>

std::ofstream cout("pinoc.inp");

int random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    int max = std::pow(10, 9);
    int range = std::pow(10, 6);
    cout << range << " " << random(1, range);
    for (int i = 0; i < range; ++i)
    {
        cout << random(0, max) << '\n';
    }
    return 0;
}