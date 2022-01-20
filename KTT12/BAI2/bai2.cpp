#include <bits/stdc++.h>

using namespace std;
ifstream in("bai2.inp");
ofstream out("bai2.out");

int main()
{
    int n;
    in >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        in >> x;
        out << floor(sqrt(x)) << '\n';
    }
    return 0;
}