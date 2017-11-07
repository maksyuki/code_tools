/***********************************************
************************************************
@接口: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@时间复杂度: O (log (n))

@接口: long long CRT ()
@时间复杂度: O (n * log (n))
************************************************/

//CRT中方程组的组数、剩余值和模值
long long n, a[maxn+10], m[maxn+10];

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

//数组下标从1开始
long long CRT ()
{
    long long M = 1;
    long long Mi, x, y, d, res = 0;
    for (long long i = 1; i <= n; i++)
        M *= m[i];

    for (long long i = 1; i <= n; i++)
    {
        Mi = M / m[i];
        d = gcd_ex (Mi, m[i], x, y);
        res = (res + a[i] * Mi * x) % M;
    }
    res = (res % M + M) % M;
    return res;
}
