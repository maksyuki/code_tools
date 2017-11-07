/***********************************************
求解S (0, 0) ~ S (n, n)中所有的第二类Stirling数
************************************************
@接口: void GetSecStir (long long n)
@时间复杂度:
@n:
************************************************/
long long stir2[maxn][maxn];

//递推计算时可能会long long溢出，此时需要依照题意取模计算

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
