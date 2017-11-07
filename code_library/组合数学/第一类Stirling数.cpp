/***********************************************
求解S (0, 0) ~ S (n, n)中所有的第一类Stirling数
************************************************
@接口: void GetFirStir (long long n)
@时间复杂度:
@n:
************************************************/
const int maxn = 10000 + 66;

long long stir1[maxn][maxn];

//递推计算时可能会long long溢出，此时需要依照题意取模计算
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
