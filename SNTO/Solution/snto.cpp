#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;
ifstream fi("snto.inp");
ofstream fo("snto.out");

bool checkPrime(int x)
{
    for (int i = 3; i <= sqrt(x); i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int u, v;
    fi >> u >> v;
    queue<long long> q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);
    int count = 0;

    if (v > 9)
    {
        int add[] = {1, 3, 7, 9};
        int index = 0;
        int limit = 4;

        while (!q.empty())
        {
            int value = q.front();
            if (value >= u)
            {
                ++count;
            }

            index = 0;
            int temp;
            while (index < limit)
            {
                temp = value * 10 + add[index];
                if (temp <= v && checkPrime(temp))
                {
                    q.push(temp);
                }
                ++index;
            }
            q.pop();
        }
    }
    else
    {
        while (!q.empty())
        {
            if (q.front() >= u && q.front() <= v)
            {
                ++count;
            }
            q.pop();
        }
    }
    fo << count;

    return 0;
}