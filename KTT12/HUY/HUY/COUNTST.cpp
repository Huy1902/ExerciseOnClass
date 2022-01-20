#include <bits/stdc++.h>

using namespace std;
ifstream inp("COUNTST.inp");
ofstream out("COUNTST.out");

int main()
{
    string s;
    inp >> s;
    int count = 0;
    int pos = 0;
    while (s.find("abc", pos) != string::npos)
    {
        pos = s.find("abc", pos) + 1;
        ++count;
    }
    out << count;
    return 0;
}
