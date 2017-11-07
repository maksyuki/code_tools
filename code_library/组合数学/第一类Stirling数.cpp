/***********************************************
���S (0, 0) ~ S (n, n)�����еĵ�һ��Stirling��
************************************************
@�ӿ�: void GetFirStir (long long n)
@ʱ�临�Ӷ�:
@n:
************************************************/
const int maxn = 10000 + 66;

long long stir1[maxn][maxn];

//���Ƽ���ʱ���ܻ�long long�������ʱ��Ҫ��������ȡģ����
void GetFirStir (long long n)
{
    memset (stir1, 0, sizeof (stir1));
    stir1[1][1] = 1;

    for (long long i = 2; i < n; i++)
    {
        for (long long j = 1; j <= i; j++)
            stir1[i][j] = stir1[i-1][j-1] + stir1[i-1][j] * (i - 1);
    }
}
