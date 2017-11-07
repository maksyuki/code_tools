/***********************************************
筛选出素数表
************************************************
@接口: void GetPrime ()
@功能: 筛选出素数表
@时间复杂度: O (n)
************************************************/

//定义素数判断表和素数表
bool prime[maxn+10];
long long primelist[maxn+10], prime_len;

void GetPrime ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    for (long long i = 2; i <= maxn; i++)
    {
        if (prime[i])
            primelist[prime_len++] = i;

        for (long long j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            if (i % primelist[j] == 0)
                break;
        }
    }
}
