/***********************************************
���a ^ b mod p��ֵ(ʹ��acdreamer���ܵ������Ԫ
�ķ���) ��a / b mod (p) = a mod (pb) / b
************************************************
@�ӿ�: long long GetFactorSum (long long a, long long b, long long mod)
@����: ���a ^ b mod p��ֵ
@ʱ�临�Ӷ�: O (sqrt (a))
@a: ����
@b: ָ��
@mod: ģֵ
************************************************/

bool prime[maxn+10];
long long primelist[maxn+10], prime_len;

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

long long GetFactorSum (long long a, long long b, long long mod)
{
    long long ans = 1;

    for (long long i = 0; primelist[i] * primelist[i] <= a; i++)
    {
        if (a % primelist[i] == 0)
        {
            long long tempsum = 0;
            while (a % primelist[i] == 0)
            {
                tempsum++;
                a /= primelist[i];
            }

            long long m = (primelist[i] - 1) * mod;
            ans *= (pow_mod (primelist[i], tempsum * b + 1, m) + m - 1) / (primelist[i] - 1);
            ans %= mod;
        }
    }

    if (a > 1)
    {
        long long m = (a - 1) * mod;
        ans *= (pow_mod (a, b + 1, m) + m - 1) / (a - 1);
        ans %= mod;
    }

return ans;
}
