#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
std::ifstream fi("sdb.inp");
std::ofstream fo("sdb.out");

struct SNode
{
    int value;
    int position;
};
bool compare(const SNode &a, const SNode &b)
{
    return a.value < b.value;
}

bool compare_result(const SNode &a, const SNode &b)
{
    return a.position < b.position;
}
int main()
{
    int n;
    fi >> n;
    SNode *a = new SNode[n];
    for (int i = 0; i < n; ++i)
    {
        fi >> a[i].value;
        a[i].position = i;
    }

    std::sort(a, a + n, compare);

    // for (int i = 0; i < n; ++i)
    // {
    //     fo << a[i].value << " ";
    // }

    SNode *result = new SNode[n];
    int index = 0;

    bool uni;
    for (int i = 0; i < n; ++i)
    {
        uni = true;
        if (a[i + 1].value == a[i].value)
        {
            uni = false;
            while (a[i + 1].value == a[i].value)
            {
                ++i;
            }
        }
        if (uni)
        {
            result[index].value = a[i].value;
            result[index].position = a[i].position;
            ++index;
        }
    }

    std::sort(result, result + index, compare_result);

    fo << index << '\n';
    for (int i = 0; i < index; ++i)
    {
        fo << result[i].value << '\n';
    }
    return 0;
}
