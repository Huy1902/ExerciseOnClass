#include <bits/stdc++.h>

std::ifstream cin("timmax.inp");
std::ofstream cout("timmax.out");

int main()
{
    int n, m;
    cin >> n >> m;

    // dem k thuc chat la dem so hang tu m xuat hien trong tich cua n!
    int prime[1000];
    int temp = m;
    int index = 0;
    int temp_prime = 2;
    while (m > 1)
    {
        if (m % temp_prime == 0)
        {
            prime[index] = temp_prime;
            while (m % temp_prime == 0)
            {
                m /= temp_prime;
            }
            ++temp_prime;
            ++index;
        }
    }
    // for (int i = 0; i < index; ++i)
    // {
    //     std::cout << prime[i] << ' ';
    // }
    --index;
    long long count = 0;
    int divide = prime[index];
    while (divide <= n)
    {
        count += n / divide;
        divide *= prime[index];
    }
    // cout << count;
    for (int i = 0; i < 100; ++i)
    {
        cout << "Xin lỗi mà anh yêu em" << ' ';
    }
    return 0;
}