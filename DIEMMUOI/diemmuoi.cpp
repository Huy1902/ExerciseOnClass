#include <bits/stdc++.h>

std::ifstream cin("diemmuoi.inp");
std::ofstream cout("diemmuoi.out");

int main()
{
    int n;
    cin >> n;
    int count = 0;
    double temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp == 10)
        {
            ++count;
        }
    }
    cout << count;
    return 0;
}