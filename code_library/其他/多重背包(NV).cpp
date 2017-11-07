/***********************************************
************************************************
@接口: void SS ()
@功能: 求解多重背包问题
@时间复杂度: O (N * V)
************************************************/

//c[i]表示第i个物品的花费 w[i]表示第i个物品的价值
//m[i]表示第i个物品的数量 dp[i]表示前i物品组成的最大价值
int c[maxn], w[maxn], m[maxn], dp[maxn];
int V, N;//分别表示背包的总体积和可选的物品的种数

void ZeroOnePack (int c, int w)
{
    for (int i = V; i >= c; i--)
        dp[i] = max (dp[i], dp[i-c] + w);
}

void CompletePack (int c, int w)
{
    for (int i = c; i <= V; i++)
        dp[i] = max (dp[i], dp[i-c] + w);
}

int qua[maxn], qub[maxn];//队列的大小maxn至少要有V / c这么大
void Multipack (int c, int w, int m)
{
	if (m == 1)
		ZeroOnePack (c, w);

	else if (c * m >= V)
		CompletePack (c, w);

	else
	{
		for (int i = 0; i < c; i++)
		{
			int pafront = 0, paback = -1;
			int pbfront = 0, pbback = -1;
			for (int j = 0, k = i; k <= V; j++, k += c)
			{
				if (pafront + m == paback)
				{
					if (qua[pafront] == qub[pbfront]) pbfront++;
					pafront++;
				}
				int tt = dp[k] - j * w;
				qua[++paback] = tt;
				while (pbback >= pbfront && qub[pbback] < tt) pbback--;
				qub[++pbback] = tt;
				dp[k] = qub[pbfront] + j * w;
			}
		}
	}
}

void SS ()
{
	memset (dp, 0, sizeof (dp));
	for (int i = 1; i <= N; i++)
		Multipack (c[i], w[i], m[i]);
}
