/***********************************************
求解1 ~ maxn - 1之间的数的素因子个数，存储在dp中
其中dp[i]表示数字i的素因子个数，只能适用于maxn
不太大的场合
************************************************
@接口: void GetPrimeFactorNum ()
@功能:
@时间复杂度: O (n)
************************************************/

bool prime[maxn+10];
long long primelist[maxn+10], prime_len, dp[maxn+10];

void GetPrimeFactorNum ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;

    for (long long i = 2; i <= maxn - 6; i++)
    {
        if (prime[i])
        {
            primelist[prime_len++] = i;
            dp[i] = 1;
        }

        for (long long j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            dp[i*primelist[j]] = dp[i] + dp[primelist[j]];

            if (i % primelist[j] == 0)
                break;
        }
    }
}
