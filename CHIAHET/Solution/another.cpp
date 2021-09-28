#include <bits/stdc++.h>

std::ifstream cin("chiahet.inp");
std::ofstream cout("chiahet.ans");

int main()
{
    int n;
    cin >> n;
    int add = 1;
    long long result = 0;
    while (n > 0)
    {
        while (result % add != 0)
        {
            ++result;
        }
        for (long long i = 0; i < add && n > 0; ++i)
        {
            cout << add << " " << result << '\n';
            result += add;
            --n;
        }
        ++add;
    }

    return 0;
}