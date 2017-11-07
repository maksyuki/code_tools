/***********************************************
************************************************
@接口: int GetSum (int i, int j)
@功能: 求解[i,j]之间数的和(循环的)
@时间复杂度:
@i:
@j:

@接口: void Solve (int n)
@功能:
@时间复杂度: O (n ^ 3)
@n: 序列的长度
************************************************/

//分别表示区间的最小值的递推数组、最大值的递推数组和前缀和表
int dpmin[maxn][maxn], dpmax[maxn][maxn], sum[maxn];
int minval, maxval, n;//表示序列合并过程中的最小值、最大值和待合并序列的长度

int GetSum (int i, int j)
{
    if (i + j >= n) return GetSum (i, n - i - 1) + GetSum (0, (i + j) % n);
    else return sum[i+j] - (i > 0 ? sum[i-1] : 0);
}

//数组的下标从0开始
void Solve (int n)
{
    for (int i = 0;i < n; i++)
        dpmin[i][0] = dpmax[i][0] = 0;

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            dpmin[i][j] = INF;
            dpmax[i][j] = 0;
            for (int k = 0; k < j; k++)
            {
                dpmin[i][j] = min (dpmin[i][j], dpmin[i][k] + dpmin[(i+k+1)%n][j-k-1] + GetSum (i, j));
                dpmax[i][j] = max (dpmax[i][j], dpmax[i][k] + dpmax[(i+k+1)%n][j-k-1] + GetSum (i, j));
            }
        }
    }
    minval = dpmin[0][n-1];
    maxval = dpmax[0][n-1];
    for (int i = 0; i < n; i++)
    {
        minval = min (minval, dpmin[i][n-1]);
        maxval = max (maxval, dpmax[i][n-1]);
    }
}
