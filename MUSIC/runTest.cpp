#include <bits/stdc++.h>
using namespace std;

const int N_TEST = 10000;
const string NAME = "music";

int random(const int &min, const int &max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < N_TEST; ++i)
    {
        ofstream out("music.inp");
        int n = random(1, 1000);
        int d = random(1, 1000);
        out << n << ' ' << d << '\n';
        for (int i = 0; i < n; ++i)
        {
            out << random(1, 1000) << ' ';
        }
        out << '\n';
        for (int i = 0; i < n; ++i)
        {
            out << random(1, 1000) << ' ';
        }
        out.close();
        system((" g++ " + NAME + "_dynamic.cpp -o " + NAME + "_dynamic && ./" + NAME + "_dynamic").c_str());
        system((" g++ " + NAME + "_greedy.cpp -o " + NAME + "_greedy && ./" + NAME + "_greedy").c_str());
        if (system(("diff -b " + NAME + "_dynamic.out " + NAME + "_greedy.out").c_str()) != 0)
        {
            cout << "Test " << i << " : WRONG\n";
            return 0;
        }
        else
        {
            cout << "Test " << i << " : CORRECT\n";
        }
    }
    cout << "ALL CORRECT";
    return 0;
}