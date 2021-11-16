#include <bits/stdc++.h>

std::ifstream cin("capsocong.inp");
std::ofstream cout("capsocong.out");

int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int *l = new int[n];
    l[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        l[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[i] - a[j] == k && l[j] + 1 > l[i])
            {
                l[i] = l[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (l[i] > max)
        {
            max = l[i];
        }
    }
    cout << max;
    return 0;
}