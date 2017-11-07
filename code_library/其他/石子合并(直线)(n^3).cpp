/***********************************************
************************************************
@�ӿ�: int UnBoneMin (int n)
@����:
@ʱ�临�Ӷ�: O(n ^ 3)
@n: ��ʾ���ϲ�ʯ�ӵĶ���
************************************************/

//�ֱ��ʾǰ׺�ͱ�͵�������
int sum[maxn], dp[maxn][maxn];

//�ڵ���UnBoneMin֮ǰ��Ҫ��ά��һ��ǰ׺�ͱ�
//�����±��0��ʼ
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
