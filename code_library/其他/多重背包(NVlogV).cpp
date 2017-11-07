/***********************************************
************************************************
@接口: void SS ()
@功能: 求解多重背包问题
@时间复杂度: O (N * log(V) * V)
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

void MultiPack (int c, int w, int m)
{
    if (c * m >= V)
    {
        CompletePack (c, w);
        return ;
    }

    int k = 1;
    while (k < m)
    {
        ZeroOnePack (k * c, k * w);
        m -= k;
        k <<= 1; 
    }
    ZeroOnePack (m * c, m * w);
}

void SS ()//可依照题目变化，这里表示背包不需要装满，如果只有dp[0]赋值为0，则表示恰好装满时的最大价值
{
    memset (dp, 0, sizeof (dp));
    for (int i = 1; i <= N; i++)
        MultiPack (c[i], w[i], m[i]);
}



