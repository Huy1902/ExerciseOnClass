#include <bits/stdc++.h>

std::ofstream cout("matkhau.inp");

int random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    for (int i = 0; i < 1000; ++i)
    {
        cout << char(random(48, 122));
    }
    return 0;
}