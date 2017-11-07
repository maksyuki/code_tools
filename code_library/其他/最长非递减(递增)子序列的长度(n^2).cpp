/***********************************************
���ַ�������ͬʱ����������кͳ���
************************************************
@�ӿ�: int LIS ()
@����: ���ans�д洢�����е���ǵݼ�������
@ʱ�临�Ӷ�:O (n ^ 2)
@:

@�ӿ�: int LDS ()
@����: ���ans�д洢�����е���ǵ���������
@ʱ�临�Ӷ�:O (n ^ 2)
@:
************************************************/


const int maxn = 666666;

//ans����洢���������У�dp�����������е���
int dp[maxn], ans[maxn];

//������±��0��ʼ
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
