/***********************************************
************************************************
@�ӿ�: long long GetComMod (long long n, long long m, long long p)
@����:
@ʱ�临�Ӷ�:
@:
************************************************/

bool prime[maxn];//ע��maxn��ֵҪ���ڵ���������е�n������������
long long primelist[maxn], prime_len;

void GetPrime ()
{
    memset (prime, true, sizeof (prime));
    prime_len = 0;

    long long i;
    for (i = 2; i <= maxn; i++)
    {
        if (prime[i])
            primelist[prime_len++] = i;

        long long j;
        for (j = 0; j < prime_len; j++)
        {
            if (i * primelist[j] > maxn)
                break;

            prime[i*primelist[j]] = false;
            if (i % primelist[j] == 0)
                break;
        }
    }
}

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod;
    b %= mod;
    long long ans = 0;
    long long temp = a;

    while (b)
    {
        if (b & 1)
        {
            ans += temp;
            if (ans > mod)
                ans -= mod;//ֱ��ȡģ���ܶ�
        }

        temp <<= 1;
        if (temp > mod)
            temp -= mod;
        b >>= 1;
    }

return ans;
}

long long pow_mod (long long a,long long n,long long mod)
{
    long long ans = 1;
    long long temp = a % mod;
    while (n)
    {
        if (n & 1)
            ans = mult_mod (ans, temp, mod);

        temp = mult_mod (temp, temp, mod);
        n >>= 1;
    }

return ans;
}

long long Work (long long n, long long p)
{
    long long ans = 0;
    while (n)
    {
        ans += n / p;
        n /= p;
    }

return ans;
}

long long GetComMod (long long n, long long m, long long p)//�ڵ���GetComMod����֮ǰ��Ҫ�ȵ���GetPrime����
{
    long long ans = 1;
    for(long long i = 0; i < prime_len && primelist[i] <= n; i++)
    {
        long long x = Work (n, primelist[i]);
        long long y = Work (n - m, primelist[i]);
        long long z = Work (m, primelist[i]);
        x -= (y + z);
        ans *= pow_mod (primelist[i], x, p);
        ans %= p;
    }

return ans;
}


