
#include <bits/stdc++.h>

using namespace std;
long long n;

int k, a[100], nho, luu, k1, nho1, c;
int main()
{
    freopen("MIN.inp", "r", stdin);
    freopen("MIN.out", "w", stdout);

    cin >> n >> k;
    nho = 1;
    k1 = k;
    while (n > 0)
    {
        a[nho] = n % 10;
        n = n / 10;
        nho++;
    }
    if (k <= nho)
    {
        for (int i = k + 1; i < nho; i++)
            if (a[i] == 5)
                k--;
        for (int i = k1; i >= k + 1; i--)
            if (a[i] == 5)
                k--;

        c = 1;
        for (int i = 1; i <= k; i++)
            a[i] = 5;
        {
            for (int i = k + 1; i <= nho; i++)
                if (a[i] + nho1 + c > 9)
                {
                    a[i] = 0;
                    nho1 = 1;
                    c = 0;
                }
                else
                {
                    a[i] = a[i] + 1;
                    if (a[i] == 5)
                        a[k] = 0;
                    nho1 = 0;
                    break;
                }
        }

        if (a[nho] == 0)
            nho = nho - 1;
        for (int i = nho; i >= 1; i--)
            cout << a[i];
    }
    else
    {
        for (int i = 1; i <= k; i++)
            cout << 5;
    }
    return 0;
}