
void GetNextPermutation (int *ans, int n)
{
	int i = n - 1;

	while (i > 0 && ans[i-1] >= ans[i])
		i--;

	if (i == 0)
	{
		sort (ans, ans + n);
		return ;
	}

	else
	{
		int mp = i;
		int j;
		for (j = i + 1; j < n; j++)
		{
			if (ans[j] <= ans[i-1])		//important!!!!!!
				continue;

			if (ans[j] < ans[mp])		//important!!!!!!
				mp = j;
		}

		int temp = ans[mp];
		ans[mp] = ans[i-1];
		ans[i-1] = temp;

		sort (ans + i, ans + n);
	}
}
