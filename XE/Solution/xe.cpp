#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("xe.inp");
ofstream fo("xe.out");

void input(int value[], int mark[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        fi >> value[i];
        mark[i] = i;
    }
}

//sort b follow a
void quickSort(int l, int r, int a[], int b[])
{
    int mid = a[l + (r - l) / 2];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (a[i] < mid)
        {
            ++i;
        }
        while (a[j] > mid)
        {
            --j;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            ++i;
            --j;
        }
    }
    if (l < j)
    {
        quickSort(l, j, a, b);
    }
    if (i < r)
    {
        quickSort(i, r, a, b);
    }
}

int main()
{
    int n_group = 0, n_car = 0;
    fi >> n_group >> n_car;
    if (n_group == 0 || n_car == 0)
    {
        fo << 0;
        return 0;
    }

    int mark_group[200];
    int distance[200];
    input(distance, mark_group, n_group);

    int gasoline_used[200];
    int mark_car[200];
    input(gasoline_used, mark_car, n_car);
    //input data complete

    quickSort(0, n_group - 1, distance, mark_group);
    quickSort(0, n_car - 1, gasoline_used, mark_car);

    //decide which car will be used for each group;
    //calculate many liters will be used
    int index_car_use = n_group - 1;
    long long liters_gasoline_use = 0;
    int car_used[200];

    //can sort from increase sequence
    for (int i = 0; i < n_group; ++i)
    {
        car_used[mark_group[i]] = mark_car[index_car_use];
        liters_gasoline_use += distance[i] * gasoline_used[index_car_use];
        --index_car_use;
    }

    fo << liters_gasoline_use << '\n';

    for (int i = 0; i < n_group; ++i)
    {
        fo << car_used[i] + 1 << " ";
    }

    return 0;
}
