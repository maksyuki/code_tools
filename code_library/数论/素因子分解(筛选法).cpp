/***********************************************
���ٽ�С�������зֽ⣬��ֱ��ʹ���Գ���Ҫ��
************************************************
@�ӿ�: void GetPrime (long long val)
@����: ��2 ~ sqrt (val)�е��������
@ʱ�临�Ӷ�: O (k * n)

@�ӿ�: void GetFactor (long long val)
@����: ���val��������
@ʱ�临�Ӷ�: O (k * n)
@val: ���ֽ���
************************************************/

long long factor[maxn+10], fac_len;//�����ӱ�ͱ�ĳ���
bool prime[maxn+10];//�ж�2~maxn�е����Ƿ�Ϊ����
long long primelist[maxn+10], prime_len;//������ͱ�ĳ���

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

//�ڵ���GetFactor֮ǰ��Ҫ�ȴ��������
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
