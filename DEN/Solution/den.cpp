#include <iostream>
#include <fstream>
using namespace std;

ifstream fi("den.inp");
ofstream fo("den.out");

const int g_digit[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int digitsSeperated(int x)
{
    if (x == 0)
    {
        return g_digit[x];
    }

    int sum = 0;
    while (x > 0)
    {
        sum += g_digit[x % 10];
        x /= 10;
    }
    return sum;
}

int main()
{
    int start[100000];
    int final[100000];
    int index = 0;
    int a, b;
    int max_v = 0;
    int min_v = 100000;
    while (fi >> a >> b)
    {
        start[index] = a;
        final[index] = b;
        ++index;
        if (b > max_v)
        {
            max_v = b;
        }
        if (a < min_v)
        {
            min_v = a;
        }
    }

    int sum[100000];
    sum[min_v - 1] = 0;
    for (int i = min_v; i <= max_v; ++i)
    {
        sum[i] = digitsSeperated(i) + sum[i - 1];
    }

    for (int i = 0; i < index; ++i)
    {
        fo << sum[final[i]] - sum[start[i] - 1] << '\n';
    }

    return 0;
}