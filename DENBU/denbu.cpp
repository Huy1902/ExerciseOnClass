#include <bits/stdc++.h>

std::ifstream cin("denbu.inp");
std::ofstream cout("denbu.out");

int main()
{
    int a, b, c, k, m, n;
    cin >> a >> b >> c >> k >> m >> n;
    cout << a * k + b * m + c * (n - k - m);
    return 0;
}