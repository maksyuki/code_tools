/***********************************************
求解欧拉函数造val处的值，比直接试除要快(大数据时)
************************************************
@接口: void GetPrime ()
@功能:
@时间复杂度: O (n)


@接口: long long GetEuler (long long val)
@时间复杂度: O (x) x为sqrt (val)中的素数个数
************************************************/

bool prime[maxn+10];
long long primelist[maxn+10], prime_len;

//在调用GetEuler函数之前要先调用GetPrime来打出素数表
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

long long GetEuler (long long val)
{
    long long ans = val;
    for (long long i = 0; i < prime_len && primelist[i] * primelist[i] <= val; i++)
    {
        if (val % primelist[i] == 0)
        {
            ans -= ans / primelist[i];
            while (val % primelist[i] == 0)
            {
                val /= primelist[i];
            }
        }
    }

    if (val > 1)
        ans -= ans / val;

    return ans;
}
