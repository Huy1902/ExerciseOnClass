#include <bits/stdc++.h>

std::ifstream cin("trochoi.inp");
std::ofstream cout("trochoi.out");

void quickSort(int l, int r, int a[], int b[])
{
    int mid = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (a[i] < mid)
        {
            ++i;
        }
        while (a[j] > mid)
        {
            --j;
        }
        if (i <= j)
        {
            std::swap(a[i], a[j]);
            std::swap(b[i], b[j]);
            ++i;
            --j;
        }
    }
    if (l < j)
    {
        quickSort(l, j, a, b);
    }
    if (i < r)
    {
        quickSort(i, r, a, b);
    }
}

int main()
{
    std::string s[10001];
    int number_char[10001];
    int pos[10001];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        int number = 0;
        for (int j = 0; j < s[i].size(); ++j)
        {
            if (s[i][j] >= '0' && s[i][j] <= '9')
            {
                number = number * 10 + s[i][j] - 48;
            }
        }
        number_char[i] = number;
        pos[i] = i;
    }

    quickSort(0, n - 1, number_char, pos);

    for (int i = 0; i < n; ++i)
    {
        cout << s[pos[i]] << '\n';
    }

    return 0;
}