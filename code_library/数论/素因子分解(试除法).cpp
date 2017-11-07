/***********************************************
适用于分解小合数
************************************************
@接口:
@功能:
@时间复杂度:
@:
************************************************/

long long factor[maxn+10], fac_len;//素因子表和表的长度

void GetFactor (long long val)
{
    fac_len = 0;
    for (long long i = 2; i * i <= val; i++)
    {
        while (val % i == 0)
        {
            factor[fac_len++] = i;
            val /= i;
        }
    }

    if (val != 1)
        factor[fac_len++] = val;
}
