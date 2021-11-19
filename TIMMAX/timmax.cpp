#include <bits/stdc++.h>

std::ifstream cin("timmax.inp");
std::ofstream cout("timmax.out");
int maxPrimeFactor(const int &m)
{
    int a = m;
    int max_prime;
    if (a % 2 == 0)
    {
        max_prime = 2;
        while (a % 2 == 0)
        {
            a /= 2;
        }
    }
    if (a % 3 == 0)
    {
        max_prime = 3;
        while (a % 3 == 0)
        {
            a /= 3;
        }
    }
    // a must be divided by 2, 3 => a cannot divided by 6
    // 2, 3, 5, 7 => a only have factor start from 5, 7
    for (int i = 5, range = sqrt(a); i <= range; i += 6)
    {
        if (a % i == 0)
        {
            max_prime = i;
            while (a % i == 0)
            {
                a /= i;
            }
        }
        if (a % (i + 2) == 0)
        {
            max_prime = i + 2;
            while (a % max_prime == 0)
            {
                a /= max_prime;
            }
        }
    }
    if (a > 4)
    {
        max_prime = a;
    }
    return max_prime;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int prime = maxPrimeFactor(m);
    int temp = 0;
    while (m % prime == 0)
    {
        m /= prime;
        ++temp;
    }
    int count = 0;
    long long divide = prime;
    while (divide <= n)
    {
        count += n / divide;
        divide *= prime;
    }
    // std::cout << count;
    cout << count / temp;
    return 0;
}