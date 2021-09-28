#include <bits/stdc++.h>

std::ifstream cin("chiahet.inp");
std::ofstream cout("chiahet.out");

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    --n;
    int add = 2;
    long long result = 1;
    while (n > 0)
    {
        ++result;
        if (result % add != 0)
        {
            result += (add - result % add);
        }
        result += add * (add - 1);
        n -= add;
        ++add;
    }
    cout << result - abs(n) * (add - 1);
    return 0;
}