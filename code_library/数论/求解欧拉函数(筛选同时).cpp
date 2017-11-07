/***********************************************
************************************************
@接口: void GetPrimeAndEuler ()
@功能:
@时间复杂度:
@:
************************************************/

//定义素数判断表、素数表和欧拉函数表
bool prime[maxn+10];
long long primelist[maxn+10], prime_len;
long long euler[maxn+10], sum[maxn+10];

void GetPrimeAndEuler ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;

    for (long long i = 2; i <= maxn; i++)
    {
        if (prime[i])
        {
            primelist[prime_len++] = i;
            euler[i] = i - 1;
        }

        for (long long j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            if (i % primelist[j] == 0)
            {
                euler[i*primelist[j]] = euler[i] * primelist[j];
                break;
            }

            else
                euler[i*primelist[j]] = euler[i] * (primelist[j] - 1);
        }
    }
}
