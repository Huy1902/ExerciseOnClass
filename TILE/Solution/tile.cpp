#include <bits/stdc++.h>

std::ifstream cin("tile.inp");
std::ofstream cout("tile.out");

// s * 2;
void product(std::string &s)
{
    int remainder = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        int temp = (s[i] - '0') * 2 + remainder;
        s[i] = char(temp % 10 + '0');
        remainder = temp / 10;
    }
    if (remainder > 0)
    {
        s.insert(0, 1, char(remainder + '0'));
    }
}

//s1 - s2
std::string subtraction(std::string s1, std::string s2)
{
    s2.insert(0, s1.size() - s2.size(), '0');

    int remainder = 0;
    for (int i = s1.size() - 1; i >= 0; --i)
    {
        int temp = s1[i] + 10 - (s2[i] + remainder);
        s1[i] = char(temp % 10 + '0');
        if (temp < 10)
        {
            remainder = 1;
        }
        else
        {
            remainder = 0;
        }
    }
    int i = 0;
    while (s1[i] == '0')
    {
        ++i;
    }
    s1.erase(0, i);
    return s1;
}

int main()
{
    std::string way[1001];
    way[0] = "1";
    std::string temp = "1";
    for (int i = 1; i <= 1000; ++i)
    {
        product(temp);
        way[i] = subtraction(temp, way[i - 1]);
    }

    int n;
    while (cin >> n)
    {
        cout << way[n] << '\n';
    }
    return 0;
}