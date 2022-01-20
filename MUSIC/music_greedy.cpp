#include <bits/stdc++.h>

using namespace std;

ifstream in("music.inp");
ofstream out("music_greedy.out");

struct SActive
{
    int time;
    int prize;
};

bool compare(const SActive a, const SActive &b)
{
    return a.prize > b.prize;
}
int main()
{
    int n, d;
    in >> n >> d;
    SActive *a = new SActive[n];
    int limit_time = 0;
    for (int i = 0; i < n; ++i)
    {
        in >> a[i].time;
        if (a[i].time > limit_time)
        {
            limit_time = a[i].time;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        in >> a[i].prize;
    }
    sort(a, a + n, compare);

    int range = limit_time / d;
    int *slot = new int[range + 1];
    for (int i = 0; i <= range; ++i)
    {
        slot[i] = -1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = a[i].time / d; j > 0; --j)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= range; ++i)
    {
        sum += a[slot[i]].prize;
    }
    out << sum;
    in.close();
    out.close();
    return 0;
}