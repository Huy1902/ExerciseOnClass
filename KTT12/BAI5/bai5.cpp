#include <bits/stdc++.h>

using namespace std;
ifstream in("bai5.inp");
ofstream out("bai5.out");

int main()
{
    int n;
    in >> n;
    int *a = new int[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        in >> a[i];
    }
    int *f = new int[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        f[i] = 1;
        for (int j = i - 2; j >= 1; --j)
        {
            if (a[j] < a[i] && f[j] + 1 > f[i])
            {
                f[i] = f[j] + 1;
            }
        }
    }
    int max_v = 0;
    int max_pos = 0;
    for (int i = n; i >= 1; --i)
    {
        if (f[i] > max_v)
        {
            max_v = f[i];
            max_pos = i;
        }
    }
    out << max_v << '\n';
    // find length end;

    int *ans = new int[n + 1];
    int index = 0;
    ans[index] = max_pos;
    ++index;
    for (int i = max_pos; max_v > 1;)
    {
        for (int j = i - 2; j >= 1; --j)

        {
            if (a[j] < a[i] && f[j] + 1 == max_v)
            {
                --max_v;
                ans[index] = j;
                i = j;
                ++index;
                break;
            }
        }
    }
    // export element end;
    for (int i = index - 1; i >= 0; --i)
    {
        out << ans[i] << ' ';
    }
    return 0;
}