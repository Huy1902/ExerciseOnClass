#include <bits/stdc++.h>

using namespace std;
ifstream in("Daychiahet.inp");
ofstream out("Daychiahet.out");

int main()
{
    int n;
    in >> n;
    int i = 1;
    int find = 0;
    while (n > 0)
    {
        n -= i;
        find -= find % i;
        find += i * i;
        // cout << find << '\n';
        ++i;
    }
    if (n < 0)
    {
        out << find + (i - 1) * n;
    }
    else
    {
        out << find;
    }
    return 0;
}
