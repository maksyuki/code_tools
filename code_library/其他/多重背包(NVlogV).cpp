/***********************************************
************************************************
@�ӿ�: void SS ()
@����: �����ر�������
@ʱ�临�Ӷ�: O (N * log(V) * V)
************************************************/

//c[i]��ʾ��i����Ʒ�Ļ��� w[i]��ʾ��i����Ʒ�ļ�ֵ
//m[i]��ʾ��i����Ʒ������ dp[i]��ʾǰi��Ʒ��ɵ�����ֵ
int c[maxn], w[maxn], m[maxn], dp[maxn];
int V, N;//�ֱ��ʾ������������Ϳ�ѡ����Ʒ������

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

void SS ()//��������Ŀ�仯�������ʾ��������Ҫװ�������ֻ��dp[0]��ֵΪ0�����ʾǡ��װ��ʱ������ֵ
{
    memset (dp, 0, sizeof (dp));
    for (int i = 1; i <= N; i++)
        MultiPack (c[i], w[i], m[i]);
}



