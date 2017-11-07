/***********************************************
快速求解(a * b) % mod
************************************************
@接口: long long mult_mod (long long a,long long b,long long mod)
@时间复杂度: O (log (n))
@a:乘数
@b:乘数
@mod:取模的值
************************************************/

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod; b %= mod;
    long long ans = 0, temp = a;
    while (b)
    {
        if (b & 1)
        {
            ans += temp;
            if (ans > mod) ans -= mod;//直接取模慢很多
        }
        temp <<= 1;
        if (temp > mod) temp -= mod;
        b >>= 1;
    }
    return ans;
}
