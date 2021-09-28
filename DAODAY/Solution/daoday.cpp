#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("daoday.inp");
ofstream fo("daoday.out");

int main()
{
    int n;
    fi >> n;

    int a[1000];
    for (int i = 0; i < n; ++i)
    {
        fi >> a[i];
    }
    sort(a, a + n);

    int result = 0;
    for (int i = 0; i <= n / 2; ++i)
    {
        result = max(result, a[i] + a[n - i - 1]);
    }
    fo << result;
    return 0;
}