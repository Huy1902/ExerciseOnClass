#include <bits/stdc++.h>
using namespace std;
int m, n, a[10000000], b[10000000], c[10000000], d[10000000], x, y;

// quick sort
void sx(int d, int c, int a[], int b[])
{
    int i = d, j = c, x = (d + c) / 2, g = a[x];
    while (i < j)
    {
        while (a[i] < g)
        {
            i++;
        }
        while (a[j] > g)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (j > d)
        sx(d, j, a, b);
    if (i < c)
        sx(i, c, a, b);
}
long long tong, max1, max2;
int main()
{
    freopen("thuong.inp", "r", stdin);
    freopen("thuong.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
        if (a[i] > max2)
            max2 = a[i];
        d[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        c[b[i]] = 0;
    }
    int temp;
    for (int i = 1; i <= max2; i++)
        if (c[i] != 0)
        {
            tong = c[i] * i;
            if (max1 <= tong)
            {
                max1 = tong;
                temp = i;
            }
        }
    cout << max1 << ' ' << temp;
    // sx(1, n, a, d); /*for(int i=1;i<=n;i++) cout<<a[i]<< " ";cout<<endl; for(int i=1;i<=n;i++) cout<<d[i]<<" ";*/
    // sort(b + 1, b + m + 1);
    // while (x <= n && y <= m)
    // {
    //     if (a[x] == b[y])
    //     {
    //         a[x] = 0;
    //         x++;
    //     }
    //     if (a[x] < b[y])
    //         x++;
    //     if (a[x] > b[y])
    //         y++;
    // }
    // sx(1, n, d, a);
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] != 0)
    //         cout << a[i] << " ";
    // }
    // cout << endl;
    // cout << max1;
    return 0;
}