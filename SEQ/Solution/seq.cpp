#include <bits/stdc++.h>

std::ifstream cin("seq.inp");
std::ofstream cout("seq.out");

int main()
{
    int n;
    cin >> n;
    long long temp = 1;
    for (int i = 1; i < n; ++i)
    {
        temp = temp * 2 + 1;
    }
    cout << temp;
    return 0;
}