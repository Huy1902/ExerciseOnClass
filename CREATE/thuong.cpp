
#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream cin("thuong.inp");
std::ofstream cout("thuong.out");

int a[3000000]; // follow n cac so tren bang dien tu
int b[3000000]; // follow m cac so khong bi loai

void input(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	input(a, n);
	int temp;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		a[temp - 1] = 0;
	}

	int n_number = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != 0)
		{
			b[n_number] = a[i];
			++n_number;
		}
	}
	std::sort(b, b + n_number);
	b[n_number] = 0;
	long long sum = 0;
	long long n_same;
	for (int i = 0; i < n_number; ++i)
	{
		if (b[i] == b[i + 1])
		{
			n_same = i;
			while (b[i] == b[i + 1])
			{
				++i;
			}
			n_same = i - n_same + 1;
			if (n_same * b[i] > sum)
			{
				sum = n_same * b[i];
			}
		}
		else
		{
			if (b[i] > sum)
			{
				sum = b[i];
			}
		}
	}

	cout << sum << '\n';

	for (int i = 0; i < n_number; ++i)
	{
		cout << b[i] << ' ';
	}

	return 0;
}