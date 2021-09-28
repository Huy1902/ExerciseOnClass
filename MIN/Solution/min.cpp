#include <bits/stdc++.h>

std::ifstream cin("min.inp");
std::ofstream cout("min.out");

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    std::string result = "";
    while (n > 0 && k > 0)
    {
        int temp = n % 10;
        if (temp <= 5)
        {
            result = result + "5";
        }
        if (temp > 5)
        {
            int digit = 1;
            while (n % 10 >= 5 && k > 0)
            {
                ++digit;
                --k;
                n /= 10;
            }
            if (k == 0)
            {
                break;
            }
            ++k;
            result.insert(result.end(), digit, '5');
        }
        n /= 10;
        --k;
        cout << result << '\n';
    }

    cout << n + 1 << result;

    return 0;
}