#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

char str_a[666], str_b[666];
int zhen_a[666], zhen_b[666], fu_a[666], fu_b[666];

int main()
{
	ifstream cin ("aaa.txt");

	while (cin >> str_a >> str_b)
	{
		memset (zhen_a, 0, sizeof (zhen_a));
		memset (zhen_b, 0, sizeof (zhen_b));
		memset (fu_a, 0, sizeof (fu_a));
		memset (fu_b, 0, sizeof (fu_b));

		int point_a = strlen (str_a);
		int len_a = strlen (str_a);
		int point_b = strlen (str_b);
		int len_b = strlen (str_b);

		int i;
		for (i = 0; i < len_a; i++)
			if (str_a[i] == '.')
			{
				point_a = i;
				break;
			}

		for (i = 0; i < len_b; i++)
			if (str_b[i] == '.')
			{
				point_b = i;
				break;
			}

		int k = 0;
		for (i = point_a - 1; i >= 0; i--)
			zhen_a[k++] = str_a[i] - '0';

		k = 0;
		for (i = point_b - 1; i >= 0; i--)
			zhen_b[k++] = str_b[i] - '0';

		k = 1;		//important!!!!!!
		if (point_a + 1 < len_a)
		{
			for (i = point_a + 1; i < len_a; i++)
				fu_a[k++] = str_a[i] - '0';
		}

		k = 1;
		if (point_b + 1 < len_b)
		{
			for (i = point_b + 1; i < len_b; i++)
				fu_b[k++] = str_b[i] - '0';
		}

		int wei_fu = max (len_a - point_a, len_b - point_b);
		for (i = wei_fu; i >= 1; i--)
		{
			fu_a[i] += fu_b[i];

			if (fu_a[i] > 9)
			{
				fu_a[i] -= 10;
				fu_a[i-1]++;
			}
		}
	
		zhen_a[0] += fu_a[0];

		int wei_zhen = max (point_a - 1, point_b - 1);
		for (i = 0; i <= wei_zhen; i++)
		{
			zhen_a[i] += zhen_b[i];
			if (zhen_a[i] > 9)
			{
				zhen_a[i] -= 10;
				zhen_a[i+1]++;
			}
		}

		if (zhen_a[wei_zhen+1] > 0)
			cout << zhen_a[wei_zhen+1];

		for (i = wei_zhen; i >= 0; i--)
			cout << zhen_a[i];
		
		for (i = wei_fu; i >= 1; i--)
			if (fu_a[i] != 0)
				break;

		if (i != 0)
		{
			cout << ".";
			int j;
			for (j = 1; j <= i; j++)
				cout << fu_a[j];
			cout << endl;
		}

		else
			cout << endl;
	}

return 0;
}