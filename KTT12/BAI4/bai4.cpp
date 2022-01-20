#include <bits/stdc++.h>

using namespace std;
ifstream in("bai4.inp");
ofstream out("bai4.out");

int main()
{
    double n;
    in >> n;
    if (n == 1)
    {
        out << 1;
        return 0;
    }
    double count = 1;
    int i = 1;
    while (count <= n)
    {
        count += log10(i);
        ++i;
    }
    if (n == floor(count))
    {
        out << i - 1;
    }
    else
    {
        out << -1;
    }
    return 0;
}