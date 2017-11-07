/***********************************************
这种方法可以同时求解出最长子序列和长度
************************************************
@接口: int LIS ()
@功能: 求解ans中存储的序列的最长非递减子序列
@时间复杂度:O (n ^ 2)
@:

@接口: int LDS ()
@功能: 求解ans中存储的序列的最长非递增子序列
@时间复杂度:O (n ^ 2)
@:
************************************************/


const int maxn = 666666;

//ans数组存储带求解的数列，dp数组用来进行递推
int dp[maxn], ans[maxn];

//数组的下标从0开始
int LIS ()
{
    int maxval = -INF;
    memset (dp, 0, sizeof (dp));

    for (int i = 0; i < n; i++)
    {
        int tempmax = 0;
        for (int j = 0; j < i; j++)
            if (ans[i] >= ans[j] && tempmax < dp[j])
                tempmax = dp[j];

        dp[i] = tempmax + 1;
        maxval = max (maxval, dp[i]);
    }

return maxval;
}

int LDS ()
{
    int maxval = -INF;
    memset (dp, 0, sizeof (dp));

    for (int i = n - 1; i >= 0; i--)
    {
        int tempmax = 0;
        for (int j = n - 1; j > i; j--)
            if (ans[i] >= ans[j] && tempmax < dp[j])
                tempmax = dp[j];

        dp[i] = tempmax + 1;
        maxval = max (maxval, dp[i]);
    }

return maxval;
}
