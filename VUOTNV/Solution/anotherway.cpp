#include <bits/stdc++.h>

std::ifstream cin("vuotnv.inp");
std::ofstream cout("vuotnv.ans");
const int LIMIT = 20000;

struct SPerson
{
    int h;
    int a;
};

bool compare(SPerson a, SPerson b)
{
    return a.h < b.h;
}

int main()
{
    int n, k;
    cin >> n >> k;
    SPerson *in = new SPerson[LIMIT];
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i].h;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i].a;
    }

    std::sort(in, in + n, compare);

    bool *mark = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        mark[i] = true;
    }

    long long max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mark[i])
        {
            long long temp = in[i].a;
            int check = in[i].h + k;
            for (int j = i + 1; j < n; ++j)
            {
                if (in[j].h == check)
                {
                    if (in[j + 1].h == check && j + 1 < n)
                    {
                        int max_temp = in[j].a;
                        while (in[j + 1].h == check && j + 1 < n)
                        {
                            if (in[j + 1].a > max_temp)
                            {
                                max_temp = in[j + 1].a;
                                ++j;
                            }
                        }
                        temp += max_temp;
                        check += k;
                    }
                }
                else
                {
                    temp += in[j].a;
                    check += k;
                }
            }
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    cout << max;

    return 0;
}