/***********************************************
���1 ~ maxn - 1֮������������Ӹ������洢��dp��
����dp[i]��ʾ����i�������Ӹ�����ֻ��������maxn
��̫��ĳ���
************************************************
@�ӿ�: void GetPrimeFactorNum ()
@����:
@ʱ�临�Ӷ�: O (n)
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
