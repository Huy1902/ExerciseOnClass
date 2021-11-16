#include <bits/stdc++.h>

std::ofstream cout("thuong.inp");

const int MAX_A_B = 3 * 10000;
const int MAX_M_N = 10000000;

int random(int l, int r)
{
    return l + rand() % (r - l + 1);
}

int main()
{
    srand(time(NULL));
    int n = random(0, MAX_A_B);
    int m = random(0, MAX_A_B);
    cout << n << ' ' << m << '\n';
    int *a = new int[n];
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << random(1, MAX_M_N) << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; ++i)
    {
        cout << random(1, n) << ' ';
    }

    return 0;
}