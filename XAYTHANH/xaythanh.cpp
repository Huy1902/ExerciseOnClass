#include <bits/stdc++.h>

std::ifstream cin("xaythanh.inp");
std::ofstream cout("xaythanh.out");

bool compare(const std::string &a, const std::string b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    std::string s;
    cin >> s;
    std::string *check = new std::string[(s.size() * (s.size() + 1)) / 2 + 1];
    int index = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 1, range = s.size() - i; j <= range; ++j)
        {
            check[index] = s.substr(i, j);
            ++index;
        }
    }
    std::sort(check, check + index);
    for (int i = 0; i < index; ++i)
    {
        std::cout << check[i] << '\n';
    }
    check[index] = " ";
    int count = 0;
    for (int i = 0; i < index; ++i)
    {
        while (check[i] == check[i + 1])
        {
            ++i;
        }
        ++count;
    }
    cout << count;
    return 0;
}