/***********************************************
************************************************
@接口: int UnBoneMin (int n)
@功能:
@时间复杂度: O(n ^ 3)
@n: 表示待合并石子的堆数
************************************************/

//分别表示前缀和表和递推数组
int sum[maxn], dp[maxn][maxn];

//在调用UnBoneMin之前需要先维护一个前缀和表
//数组下标从0开始
int UnBoneMin (int n)
{
    memset (dp, 0, sizeof (dp));

    for (int v = 1; v < n; v++)
    {
        for(int i = 0; i + v < n; i++)
        {
            int j = i + v;
            dp[i][j] = INF;
            int temp = sum[j] - (i > 0 ? sum[i-1] : 0);

            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + temp);
        }
    }

return dp[0][n-1];
}
