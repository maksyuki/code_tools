/***********************************************
************************************************
@�ӿ�: void Solve ()
@����:
@ʱ�临�Ӷ�:
@:
************************************************/

//c[i]��ʾ��i����Ʒ�Ļ��� w[i]��ʾ��i����Ʒ�ļ�ֵ
//dp[i]��ʾǰi��Ʒ��ɵ�����ֵ
int c[maxn], w[maxn], dp[maxn];
int V, N;//�ֱ��ʾ������������Ϳ�ѡ����Ʒ������

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
