#include <bits/stdc++.h>

using namespace std;

ifstream in("music.inp");
ofstream out("music_dynamic.out");

struct SActive
{
    int time;
    int prize;
};

bool compare(const SActive a, const SActive &b)
{
    return a.time < b.time;
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
        slot[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        int slot_index = a[i].time / d;
        if (slot[slot_index] == 0)
        {
            slot[slot_index] = a[i].prize;
            continue;
        }

        int min_prize = a[i].prize;
        int min_pos = a[i].time;
        for (int j = slot_index; j > 0; --j)
        {
            if (min_prize > slot[j])
            {
                min_prize = slot[j];
                min_pos = j;
            }
        }
        if (min_prize != a[i].prize)
        {
            slot[min_pos] = a[i].prize;
        }
    }

    int result = 0;
    for (int i = 1; i <= range; ++i)
    {
        result += slot[i];
    }
    out << result;
    in.close();
    out.close();
    return 0;
}