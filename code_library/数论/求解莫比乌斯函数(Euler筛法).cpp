/***********************************************
求解莫比乌斯函数在1 ~ maxn上的函数值
************************************************
@接口: void GetMobi ()
@功能:
@时间复杂度: O (n)
@:
************************************************/

//定义素数判断表、素数表和莫比乌斯数组
bool prime[maxn+10];
long long primelist[maxn+10], prime_len, mu[maxn+10];

void GetMobi ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    mu[1] = 1;
    for (long long i = 2; i <= maxn; i++)
    {
        if (prime[i])
        {
            primelist[prime_len++] = i;
            mu[i] = -1;
        }

        for (long long j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            if (i % primelist[j] == 0)
            {
                mu[i*primelist[j]] = 0;
                break;
            }

            else
                mu[i*primelist[j]] = -mu[i];
        }
    }
}
