#include <bits/stdc++.h>

std::ifstream cin("vuotnv.inp");
std::ofstream cout("vuotnv.out");
const int LIMIT = 20000;

void input(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[LIMIT], h[LIMIT];
    int result[201];
    for (int i = 0; i <= 200; ++i)
    {
        result[i] = 0;
    }

    input(h, n);
    input(a, n);

    for (int i = 0; i < n; ++i)
    {
        if (result[h[i]] == 0)
        {
            result[h[i]] = a[i];
        }
        else
        {
            if (a[i] > result[h[i]])
            {
                result[h[i]] = a[i];
            }
        }
    }
    long long max = 0;
    for (int i = 0; i < k; ++i)
    {
        long long temp = 0;
        for (int j = i; j <= 200; j += k)
        {
            temp += result[j];
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    cout << max;

    return 0;
}