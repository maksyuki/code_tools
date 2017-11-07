/***********************************************
************************************************
@接口: void Solve ()
@功能:
@时间复杂度:
@:
************************************************/

//c[i]表示第i个物品的花费 w[i]表示第i个物品的价值
//dp[i]表示前i物品组成的最大价值
int c[maxn], w[maxn], dp[maxn];
int V, N;//分别表示背包的总体积和可选的物品的种数

void ZeroOnePack (int c, int w)
{
    for (int i = V; i >= c; i--)
        dp[i] = max (dp[i], dp[i-c] + w);
}

void Solve ()
{
    memset (dp, 0, sizeof (dp));
    for (int i = 0; i < N; i++)
        ZeroOnePack (c[i], w[i]);
}
