/***********************************************
求解 C (0, 0) ~ C (val, val)中的值模上mod
************************************************
@接口: void GetComMod (long long val, long long mod)
@时间复杂度: O (n ^ 2)
@val: C (0, 0) ~ C (val, val)中的val
@mod:模值
************************************************/
const int maxn = 666;

long long C[maxn][maxn];

void GetComMod (long long val, long long mod)
{
    memset (C, 0, sizeof (C));
    for (long long i = 0; i <= val; i++)
    {
        for (long long j = 0; j <= i; j++)
        {
            if (!j || i == j)
                C[i][j] = 1 % mod;

            else
                C[i][j] = (C[i-1][j-1] % mod + C[i-1][j] % mod) % mod;
        }
    }

C[0][0] = 0 % mod;
}
