#include <bits/stdc++.h>

std::ifstream cin("pinoc.inp");
std::ofstream cout("pinoc.out");

bool compare(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    long long a[100001];

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    std::sort(a + 1, a + n + 1, compare);

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << a[i] << " ";
    // }

    a[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        a[i] += a[i - 1];
        long long temp = a[i] - m;
        if (temp % i == 0 && temp / i >= a[i + 1])
        {
            cout << temp / i;
            return 0;
        }
    }
    a[n] += a[n - 1];
    long long temp = a[n] - m;
    if (temp % n == 0)
    {
        cout << temp / n;
    }

    return 0;
}