/***********************************************
�����ڷֽ�С����
************************************************
@�ӿ�:
@����:
@ʱ�临�Ӷ�:
@:
************************************************/

long long factor[maxn+10], fac_len;//�����ӱ�ͱ�ĳ���

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
