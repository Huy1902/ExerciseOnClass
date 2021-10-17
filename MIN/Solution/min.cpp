#include <bits/stdc++.h>

std::ifstream cin("min.inp");
std::ofstream cout("min.out");

void create5Digit(long long n, int k)
{
    //convert n to string s
    std::string s = "";
    int temp = n;
    while (temp > 0)
    {
        s = s + char(temp % 10 + '0');
        temp /= 10;
    }
    // end convert

    //special case
    if (s.size() <= k)
    {
        long long result = 0;
        while (k > 0)
        {
            result = result * 10 + 5;
            --k;
        }
        if (result > n)
        {
            cout << result;
            return;
        }
        else
        {
            cout << 1 << result;
            return;
        }
    }
    //end case

    //create new number
    int range = s.size();
    int n_digit_5 = 0;
    for (int i = 0; i < range; ++i)
    {
        ++n_digit_5;
    }

    std::string compare = s;
    int n_digit_need = k - n_digit_5;
    int i;
    for (i = range - 1; n_digit_need > 0; --i)
    {
        if (s[i] == '5')
        {
            ++n_digit_need;
        }
        s[i] = '5';
        --n_digit_need;
    }
    //end creation;

    //check result;
    ++i;
    if (compare[i] < s[i])
    {
        cout << s;
        return;
    }
    //end check;

    //optimize result
    --i;
    while (s[i] == '5')
    {
        --i;
    }
    if (s[i] == '4')
    {
        s[i] = '5';
        s[i + 1] = '0';
        cout << s;
        return;
    }

    long long result = 0;
    for (int j = 0; j <= i; ++j)
    {
        result = result * 10 + s[j] - '0';
    }
    cout << result + 1 << s.substr(i, range - i);

    return;
}

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    create5Digit(n, k);

    return 0;
}