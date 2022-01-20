#include <bits/stdc++.h>

using namespace std;
ifstream inp("bai1.inp");
ofstream out("bai1.out");

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