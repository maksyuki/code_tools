/***********************************************
************************************************
@接口: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@功能: 求解不定方程a * x + b * y = gcd (a, b)的解x和y
@时间复杂度: O (log (n))

@接口: long long mod_equ_set ()
@时间复杂度: O (n * log (n))
************************************************/

//n表示方程组的组数，a[i], m[i]分别表示x = ai (mod mi)中ai和mi的值
long long n, m[maxn+10], a[maxn+10];

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

long long mod_equ_set ()
{
    long long M = m[1], A = a[1], x, y, d;
    for (long long i = 2; i <= n; i++)
    {
        d = gcd_ex (M, m[i], x, y);

        if ((a[i] - A) % d) return -1;

        x = (a[i] - A) / d * x % (m[i] / d);
        x = (x + (m[i] / d)) % (m[i] / d);
        A += x * M;
        M = M * m[i] / d;
        A %= M;
    }
    return (A + M) % M;
}
