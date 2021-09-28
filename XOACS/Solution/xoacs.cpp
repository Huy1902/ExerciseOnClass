#include <bits/stdc++.h>

std::ifstream cin("xoacs.inp");
std::ofstream cout("xoacs.out");

int findMaxInRange(const std::string &s, int begin, int end)
{
    char max_v = s[begin];
    int max_pos = begin;
    if (end >= s.size())
    {
        end = s.size() - 1;
    }
    for (int i = begin + 1; i <= end; ++i)
    {
        if (s[i] > max_v)
        {
            max_v = s[i];
            max_pos = i;
        }
    }
    return max_pos;
}

int main()
{
    std::string n;
    int k;
    cin >> n >> k;

    for (int i = 0; i < n.size() && k > 0; ++i)
    {
        //std::cout << k << " " << i << " ";
        int max_pos = findMaxInRange(n, i, i + k);
        char max_v = n[max_pos];
        //std::cout << max_pos << " " << n[max_pos] << '\n';
        n.erase(i, max_pos - i);
        k -= (max_pos - i);
        while (n[i + 1] == max_v)
        {
            ++i;
        }
        //std::cout << max_v << " " << n << '\n';
    }
    if (k > 0)
    {
        n = n + char('9' + 1);
        for (int i = 0; i < n.size() && k > 0; ++i)
        {
            int j;
            int range;
            for (j = i + 1, range = i + k; j <= range; ++j)
            {
                if (n[j] > n[i])
                {
                    break;
                }
            }
            if (n[j] >= n[i])
            {
                n.erase(i + 1, j - (i + 1));
                k -= (j - (i + 1));
            }
        }
        n.erase(n.size() - 1, 1);
    }
    cout << n;
    return 0;
}