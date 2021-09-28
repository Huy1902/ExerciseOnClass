#include <bits/stdc++.h>

std::ifstream cin("min.inp");
std::ofstream cout("min.out");

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    long long result = 0;
    int n_digit = k;
    while (k > 0)
    {
        result = result * 10 + 5;
        --k;
    }
    //cout << result;

    if (result > n)
    {
        cout << result;
        return 0;
    }
    n /= std::pow(10, n_digit);
    cout << n + 1 << result;

    return 0;
}