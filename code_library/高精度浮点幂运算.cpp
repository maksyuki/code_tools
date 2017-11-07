#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int maxn = 1000 + 6;

char str[16];
int ans[maxn], num_a[maxn], num_b[maxn];
int len_a, len_b;

void mul ()
{
	memset (ans, 0, sizeof (ans));
	int i, j;
	for (i = 1; i <= len_a; i++)
		for (j = 1; j <= len_b; j++)
		{
			ans[i+j-1] += num_a[i] * num_b[j];

			if (ans[i+j-1] > 9)
			{
				ans[i+j] += ans[i+j-1] / 10;
				ans[i+j-1] %= 10;
			}
		}

	if (ans[len_a+len_b-1] > 9)
	{
		ans[len_a+len_b] += ans[len_a+len_b-1] / 10;
		ans[len_a+len_b-1] %= 10;
	}
	
	len_a += len_b;
	for (i = 1; i <= len_a; i++)
		num_a[i] = ans[i];

}

int main()
{
	//ifstream cin ("aaa.txt");

	int n;
	while (cin >> str >> n)
	{
		int dot = -1, up, down;
		
		memset (num_a, 0, sizeof (num_a));
		memset (num_b, 0, sizeof (num_b));

		int i, j;
		for (i = 5, j = 1; i >= 0; i--)
		{
			if (str[i] != '.' && str[i])
			{
				num_a[j] = str[i] - '0';
				num_b[j] = str[i] - '0';
				j++;
			}

			else if (str[i] == '.')
				dot = i;
		}
	
		if (dot == -1)
			len_a = len_b = 6;

		else
			len_a = len_b = 5;

		for (i = 1; i < n; i++)
			mul ();

		if (dot == -1)
		{
			int j;
			for (j = len_a; j >= 1; j--)
				if (num_a[j])
					break;

			for (i = j; i >= 1; i--)
				cout << num_a[i];

			cout << endl;
		}

		else
		{
			dot = 5 - dot;
			dot *= n; 
			for (i = len_a; i >= 1; i--)
				if (num_a[i])
				{
					up = i;
					break;
				}

			for (i = 1; i <= len_a; i++)
			{
				if (num_a[i])
				{
					down = i;
					break;
				}
			}

			int j;
			i = up;
			if (up < dot)
				i = dot;

			j = down;
			if (down > dot)
				j = dot + 1;

			for (; i >= j; i--)
			{
				if (i == dot)
					cout << ".";

				cout << num_a[i];
			}
			cout << endl;
		}
	}

return 0;
}