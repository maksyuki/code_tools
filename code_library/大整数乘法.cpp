#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char ch_a[666], ch_b[666];
int ans[666];
int num_a[666], num_b[666];

void char_to_number (char ch[], int val[])
{
	int len = strlen (ch);

	int i;
	for (i = 0; i < len; i++)
		val[i] = ch[len-1-i] - '0';

}

int main()
{
	ifstream cin ("aaa.txt");

	while (cin >> ch_a)
	{
		cin >> ch_b;

		memset (num_a, 0, sizeof (num_a));
		memset (num_b, 0, sizeof (num_b));

		char_to_number (ch_a, num_a);
		char_to_number (ch_b, num_b);

		int len_a = strlen (ch_a);
		int len_b = strlen (ch_b);
		
		int i, j, start;
		for (i = 0; i < len_b; i++)
			for (j = 0, start = i; j < len_a; j++)
				ans[start++] += num_a[j] * num_b[i];

		for (i = 0; i < 666; i++)
			if (ans[i] > 9)
			{
				ans[i+1] += ans[i] / 10;
				ans[i] = ans[i] % 10;
			}

		for (i = 666 - 1; i >= 0; i--)
			if (ans[i])
				break;

		for (j = i; j >= 0; j--)
			cout << ans[j];
		cout << endl;
	}

return 0;
}