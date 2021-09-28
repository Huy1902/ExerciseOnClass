#include <bits/stdc++.h>

std::ofstream fo("vuotnv.inp");

const int N_TEST = 1;

int random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL));
    int max = std::pow(10, 9);
    int range = std::pow(10, 6);
    for (int i = 0; i < N_TEST; ++i)
    {
        int n = random(1, 20000);
        int k = random(1, 100);
        fo << n << " " << k << '\n';

        for (int i = 0; i < n; ++i)
        {
            fo << random(1, 200) << " ";
        }
        for (int i = 0; i < n; ++i)
        {
            fo << random(1, 1000000) << " ";
        }

        system("./vuotnv");
        system("./anotherway");

        if (system("diff vuotnv.out vuotnv.ans") != 0)
        {
            std::cout << "correct " << i << '\n';
        }
    }
    return 0;
}