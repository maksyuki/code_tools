/***********************************************
快速将小合数进行分解，比直接使用试除法要快
************************************************
@接口: void GetPrime (long long val)
@功能: 将2 ~ sqrt (val)中的素数打表
@时间复杂度: O (k * n)

@接口: void GetFactor (long long val)
@功能: 获得val的素因子
@时间复杂度: O (k * n)
@val: 待分解数
************************************************/

long long factor[maxn+10], fac_len;//素因子表和表的长度
bool prime[maxn+10];//判断2~maxn中的数是否为素数
long long primelist[maxn+10], prime_len;//素数表和表的长度

void GetPrime ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;
    for (long long i = 2; i * i <= maxn; i++)
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

//在调用GetFactor之前需要先打出素数表
void GetFactor (long long val)
{
    fac_len = 0;
    for (long long i = 0; i < prime_len && primelist[i] * primelist[i] <= val; i++)
    {
        while (val % primelist[i] == 0)
        {
            factor[fac_len++] = primelist[i];
            val /= primelist[i];
        }
    }

    if (val != 1)
        factor[fac_len++] = val;
}
