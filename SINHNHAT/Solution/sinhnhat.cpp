#include <iostream>
#include <algorithm>
#include <fstream>

std::ifstream cin("sinhnhat.inp");
std::ofstream cout("sinhnhat.out");

struct SCake
{
    int pos;
    int cost;
};
bool compare(const SCake &a, const SCake &b)
{
    return a.cost > b.cost;
}

int main()
{
    SCake a[10010];
    int result[10010];
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].cost;
        a[i].pos = i;
    }
    // long long temp_sum = 0;
    // int temp;
    // for (int i = 0; i < k; ++i)
    // {
    //     cin >> temp;
    //     temp_sum += a[temp].cost;
    // }
    // std::cout << temp_sum;
    a[n + 1].cost = -1;

    std::sort(a + 1, a + n + 1, compare);

    int index = 0;
    long long sum = 0;
    for (int i = 1, min; index < k; ++i)
    {
        if (a[i + 1].cost == a[i].cost)
        {
            std::cout << a[i + 1].cost << ' ' << a[i].cost << '\n';
            min = a[i].pos;
            while (a[i + 1].cost == a[i].cost)
            {
                if (a[i + 1].pos < min)
                {
                    min = a[i + 1].pos;
                }
                ++i;
            }
            // cout << min << ' ';
            result[index] = min;
        }
        else
        {
            // cout << a[i].pos << ' ';
            result[index] = a[i].pos;
        }
        ++index;
        sum += a[i].cost;
    }
    for (int i = 1; i <= index; ++i)
    {
        cout << a[i].cost << ' ';
    }
    // std::sort(result, result + index);
    // cout << sum << '\n';
    // for (int i = 0; i < index; ++i)
    // {
    //     cout << result[i] << ' ';
    // }
    return 0;
}