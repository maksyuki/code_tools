/***********************************************
筛选出素数表
************************************************
@接口: void GetPrime ()
@功能: 筛选出素数表
@时间复杂度: O (nloglog (n))
************************************************/

//定义素数判断表和素数表
bool prime[maxn+10];
long long primelist[maxn+10], prime_len;

//Eratosthenes筛法
void GetPrime ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    for (long long i = 2; i <= maxn; i++)
        if (prime[i])
        {
            primelist[prime_len++] = i;
            for (long long j = 2; j * i <= maxn; j++)
                prime[j*i] = false;
        }
}
