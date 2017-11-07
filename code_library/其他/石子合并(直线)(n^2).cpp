/***********************************************
求解n堆石子合并之后所需要的最小(最大)花费(只能相
邻两堆石子合并)
************************************************
@接口: int UnBoneMin (int n)
@功能:
@时间复杂度: O (n ^ 2)
@n: 待合并石子的个数
************************************************/

//分别表示前缀和表、递推数组和最优枚举位置
int sum[maxn], dp[maxn][maxn], p[maxn][maxn];


//数组下标从1开始，在调用UnBoneMin之前需要先维护一个
//前缀和表
int UnBoneMin (int n)
{
    memset (dp, 0, sizeof (dp));
    for (int i = 1; i <= n; i++)
        p[i][i] = i;


    for (int v = 1; v <= n; v++)
    {
        for(int i = 1; i + v <= n; i++)
        {
            int j = i + v;
            dp[i][j] = INF;

            int temp = sum[j] - (i > 0 ? sum[i-1] : 0);

            for(int k = p[i][j-1]; k <= p[i+1][j]; k++)
                if (dp[i][j] > dp[i][k] + dp[k+1][j] + temp)
                {
                    dp[i][j] = dp[i][k] + dp[k+1][j] + temp;
                    p[i][j] = k;
                }
        }
    }

return dp[1][n];
}
