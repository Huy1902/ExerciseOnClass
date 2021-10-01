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
    long long a[1000001];

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

    long long max = 0;
    long long temp;
    for (int i = 1; i < n; ++i)
    {
        a[i] += a[i - 1];
        temp = a[i] - m;
        // /cout << "i la : " << i << "so bi chia la : " << temp - temp % i << '\n';
        if (temp - temp % i > max * i)
        {
            max = (temp - temp % i) / i;
        }
    }
    a[n] += a[n - 1];
    temp = a[n] - m;
    if (temp - temp % n > max * n)
    {
        max = (temp - temp % n) / n;
    }
    cout << max;

    return 0;
}