#include <bits/stdc++.h>

std::ifstream cin("trochoi.inp");
std::ofstream cout("trochoi.out");

bool less(const std::string &s1, const std::string &s2)
{
    if (s1.size() < s2.size())
    {
        return true;
    }
    if (s1.size() > s2.size())
    {
        return false;
    }

    return s1 < s2;
}

void quickSort(int l, int r, std::string a[], int b[])
{
    std::string mid = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (less(a[i], mid))
        {
            ++i;
        }
        while (less(mid, a[j]))
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
    std::string s[100000];
    std::string number_char[100000];
    int pos[100000];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        std::string number = "";
        for (int j = 0; j < s[i].size(); ++j)
        {
            if (s[i][j] >= '0' && s[i][j] <= '9')
            {
                number = number + s[i][j];
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