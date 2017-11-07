/***********************************************
查询在给定区间[1, n]中的最值(以最小值为例)
************************************************
@接口: void RMQ_ST (int n)
@功能: ST的建立
@时间复杂度: O (nlog(n))
@n: 带求解最值序列的长度

@接口: inline int RMQ_Findmin (int L, int R)
@功能: 查询区间[L, R]中的最小值
@时间复杂度: O (1)
@L: 区间左端点
@R: 区间右端点
************************************************/


int dpmin[maxn][100], ans[maxn];

void RMQ_ST (int n)//这里的带求解最值序列要从数组小标1开始
{
    for (int i = 1; i <= n; i++)
        dpmin[i][0] = ans[i];

    int m = (int) (log (n + 0.0) / log (2.0));
    for (int j = 1; j <= m; j++)
    {
        int t = n - (1 << j) + 1;
        for (int i = 1; i <= t; i++)
            dpmin[i][j] = min (dpmin[i][j-1], dpmin[i+(1<<(j-1))][j-1]);
    }
}

inline int RMQ_Findmin (int L, int R)
{
    int k = (int) (log (R - L + 1.0) / log (2.0));
    return min (dpmin[L][k], dpmin[R-(1<<k)+1][k]);
}
