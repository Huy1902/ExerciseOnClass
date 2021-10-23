#include <bits/stdc++.h>

std::ifstream cin("duongdi.inp");
std::ofstream cout("duongdi.out");

void standard(std::string &s1, std::string &s2)
{
    if (s1.size() == s2.size())
    {
        return;
    }
    else
    {
        if (s1.size() > s2.size())
        {
            s2.insert(s2.begin(), s1.size() - s2.size(), '0');
        }
        else
        {
            s1.insert(s1.begin(), s2.size() - s1.size(), '0');
        }
    }
}

void add(std::string &s1, std::string &s2, std::string &sum)
{
    standard(s1, s2);
    int rest = 0;
    sum = "";
    for (int i = s1.size() - 1, plus; i >= 0; --i)
    {
        plus = s1[i] + s2[i] - 96;
        plus += rest;
        sum += char(plus % 10 + 48);
        rest = plus / 10;
    }
    if (rest != 0)
    {
        sum += char(rest + 48);
    }
    char temp;
    int size = sum.size() - 1;
    for (int i = 0, range = size / 2; i <= range; ++i)
    {
        temp = sum[i];
        sum[i] = sum[size - i];
        sum[size - i] = temp;
    }
}
std::string a[1000][1000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        a[0][i] = a[i][0] = "1";
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            add(a[i - 1][j], a[i][j - 1], a[i][j]);
        }
    }

    cout << a[n - 1][n - 1];
    return 0;
}