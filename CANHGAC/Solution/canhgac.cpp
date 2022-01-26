#include <bits/stdc++.h>

using namespace std;
auto start = std::chrono::high_resolution_clock::now();
ifstream in("canhgac.inp");
ofstream out("canhgac.out");

struct SGurdian
{
    int from;
    int to;
    int money;
};

bool compare(const SGurdian &a, const SGurdian &b)
{
    return a.from < b.from;
}

int main()
{

    int n_time, n_gurdian;
    in >> n_time >> n_gurdian;
    SGurdian *a = new SGurdian[n_gurdian + 1];
    for (int i = 0; i < n_gurdian; ++i)
    {
        in >> a[i].from >> a[i].to >> a[i].money;
    }
    int *slot = new int[n_time + 1];
    for (int i = 0; i <= n_time; ++i)
    {
        slot[i] = 0;
    }

    sort(a, a + n_gurdian, compare);
    int i = 0;
    while (a[i].from == 0)
    {
        int j = a[i].to;
        while (slot[j] == 0 && j >= a[i].from)
        {
            slot[j] = a[i].money;
            --j;
        }
        int temp = min(slot[j], a[i].money);
        while (j >= a[i].from)
        {
            slot[j] = temp;
            --j;
        }
        ++i;
    }

    for (; i < n_gurdian; ++i)
    {
        if (slot[a[i].from] == 0)
        {
            continue;
        }
        int min_value = slot[a[i].from];
        for (int j = a[i].from + 1; j <= a[i].to; ++j)
        {
            if (slot[j] == 0)
            {
                int temp = min_value + a[i].money;
                while (slot[j] == 0 && j <= a[i].to)
                {
                    slot[j] = temp;
                    ++j;
                }
            }
            else
            {
                if (min_value > slot[j])
                {
                    min_value = slot[j];
                }
            }
        }
    }
    out << slot[n_time];
    for (int i = 0; i <= n_time; ++i)
    {
        printf("time: %d ; value: %d\n", i, slot[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = (end - start);
    cout << duration.count();

    return 0;
}