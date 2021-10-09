# ExerciseOnClass

EXCERCISE I DONE
#include <bits/stdc++.h>

std::ifstream cin ("hop.inp");
std::ofstream cout ("hop.out");

int t[1000000];
int p[1000000];

int sum = 0;
void input(int a[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}
int main()
{
    int n;
    cin >> n;
    input(t, n);
    input(p, n - 1);

    bool chung_truoc = false; //co lam moi co an;
    p[-1] = 0;
    t[-1] = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if(!chung_truoc)
        {
            if(t[i] + t[i + 1] < p[i]){
                sum += t[i];
                chung_truoc = false;
            }
            else
            {
                sum += p[i];
                chung_truoc = true;
            }
        }
        else
        {
            int chung_truoc = p[i - 1] + t[i + 1];
            int tu_lam = t[i - 1] + t[i] + t[i + 1];
            int chung_sau = t[i - 1] + p[i];
            // sum la chung truoc;
            
        }
    }
    cout << sum[n - 2];
    return 0;
}
