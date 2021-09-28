#include <iostream>
#include <fstream>
std::ifstream cin("string.inp");
std::ofstream cout("string.out");

int main()
{
    std::string s, result = "";
    int max_length = 0;
    while (cin >> s)
    {
        if (max_length < s.size())
        {
            max_length = s.size();
            result = s;
        }
    }
    cout << result;

    return 0;
}