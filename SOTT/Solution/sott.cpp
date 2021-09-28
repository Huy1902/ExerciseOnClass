#include <bits/stdc++.h>

std::ifstream cin("sott.inp");
std::ofstream cout("sott.out");

long long sumDivisor(int x)
{
    if (x == 1)
    {
        return 1;
    }
    long long sum = 0;
    int range = std::sqrt(x);
    for (int i = 1; i <= range; ++i)
    {
        if (x % i == 0)
        {
            sum += (x / i + i);
        }
    }
    if (range * range == x)
    {
        sum -= range;
    }
    return sum;
}

int gcd(long long a, long long b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 || b == 0)
    {
        cout << -1;
        return 0;
    }

    long long sum_a = sumDivisor(a);
    long long sum_b = sumDivisor(b);

    double epsilon = 0.000000001;
    if (std::abs(double(sum_a) / a - double(sum_b) / b) < epsilon)
    {
        int temp = gcd(sum_a, a);
        cout << sum_a / temp << " " << a / temp;
    }
    else
    {
        cout << -1;
    }

    return 0;
}