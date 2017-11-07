/***********************************************
快速求解整数a ^ n % mod
************************************************
@接口: long long mult_mod (long long a,long long b,long long mod)
@功能: 快速计算(a * b) % mod
@时间复杂度: O (log (n))
@a:乘数
@b:乘数
@mod:取模的值

@接口: long long pow_mod (long long a,long long n,long long mod)
@时间复杂度: O (log (n))
@a:底数
@b:指数
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

//如果a是负数，还需要将其转换成最小非负值来计算
long long pow_mod (long long a,long long n,long long mod)
{
    long long ans = 1;
    long long temp = (a % mod + mod) % mod;//对于a为负值时的考虑
    while (n)
    {
        if (n & 1)
            ans = mult_mod (ans, temp, mod);

        temp = mult_mod (temp, temp, mod);
        n >>= 1;
    }
    return ans;
}
