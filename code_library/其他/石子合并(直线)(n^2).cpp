/***********************************************
���n��ʯ�Ӻϲ�֮������Ҫ����С(���)����(ֻ����
������ʯ�Ӻϲ�)
************************************************
@�ӿ�: int UnBoneMin (int n)
@����:
@ʱ�临�Ӷ�: O (n ^ 2)
@n: ���ϲ�ʯ�ӵĸ���
************************************************/

//�ֱ��ʾǰ׺�ͱ��������������ö��λ��
int sum[maxn], dp[maxn][maxn], p[maxn][maxn];


//�����±��1��ʼ���ڵ���UnBoneMin֮ǰ��Ҫ��ά��һ��
//ǰ׺�ͱ�
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
