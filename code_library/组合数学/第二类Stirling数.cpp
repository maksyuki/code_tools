/***********************************************
���S (0, 0) ~ S (n, n)�����еĵڶ���Stirling��
************************************************
@�ӿ�: void GetSecStir (long long n)
@ʱ�临�Ӷ�:
@n:
************************************************/
long long stir2[maxn][maxn];

//���Ƽ���ʱ���ܻ�long long�������ʱ��Ҫ��������ȡģ����

void GetSecStir (long long n)
{
    memset (stir2, 0, sizeof (stir2));
    stir2[1][1] = 1;

    for (long long i = 2; i < n; i++)
    {
        for (long long j = 1; j <= i; j++)
            stir2[i][j] = stir2[i-1][j-1] + stir2[i-1][j] * j;
    }
}
