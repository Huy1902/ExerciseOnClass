#include <bits/stdc++.h>

std::ifstream cin("matkhau.inp");
std::ofstream cout("matkhau.out");

bool checkPrimes(int x)
{
    if (x <= 1)
    {
        return false;
    }
    if (x == 2)
    {
        return true;
    }
    if (x % 2 == 0)
    {
        return false;
    }
    for (int i = 3, range = std::sqrt(x); i <= range; i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string s;
    getline(cin, s);
    s.insert(s.end(), 1, ' ');
    int a[1001];
    int index = 0;
    for (int i = 0, range = s.size(); i < range; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int temp = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                temp = temp * 10 + s[i] - '0';
                ++i;
            }
            a[index] = temp;
            ++index;
        }
    }
    // for (int i = 0; i < index; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    std::sort(a, a + index, std::greater<int>());
    for (int i = 0; i < index; ++i)
    {
        if (checkPrimes(a[i]))
        {
            cout << a[i];
            return 0;
        }
    }
    return 0;
}