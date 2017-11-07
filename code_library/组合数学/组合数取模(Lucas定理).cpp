/***********************************************
���C (n, m) % p��ֵ
************************************************
@�ӿ�: long long Lucas (long long n, long long m, long long p)
@����:  ���C (n, m) % p��ֵ
@ʱ�临�Ӷ�:
@:
************************************************/

const int maxn = 10000 + 66;

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
                ans -= mod;
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

long long fac[maxn];//ע��fac����Ĵ�Сһ��ҪС��ģֵp

//�ڵ���Lucas֮ǰһ��Ҫ�ȵ���GetFactor����
long long GetFactor (long long p)
{
    fac[0] = 1;
    for (long long i = 1; i <= p; i++)
        fac[i] = (fac[i-1] * i) % p;
}

long long Lucas (long long n, long long m, long long p)
{
    long long ret = 1;
    while (n && m)
    {
        long long a = n % p, b = m % p;
        if (a < b)
            return 0;

        ret = (ret * fac[a] * pow_mod (fac[b] * fac[a-b] % p, p - 2, p)) % p;
        n /= p;
        m /= p;
    }

return ret;
}
