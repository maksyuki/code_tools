/***********************************************
���ŷ��������val����ֵ����ֱ���Գ�Ҫ��(������ʱ)
************************************************
@�ӿ�: void GetPrime ()
@����:
@ʱ�临�Ӷ�: O (n)


@�ӿ�: long long GetEuler (long long val)
@ʱ�临�Ӷ�: O (x) xΪsqrt (val)�е���������
************************************************/

bool prime[maxn+10];
long long primelist[maxn+10], prime_len;

//�ڵ���GetEuler����֮ǰҪ�ȵ���GetPrime�����������
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
