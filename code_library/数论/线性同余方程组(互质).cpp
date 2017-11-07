/***********************************************
************************************************
@�ӿ�: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@ʱ�临�Ӷ�: O (log (n))

@�ӿ�: long long CRT ()
@ʱ�临�Ӷ�: O (n * log (n))
************************************************/

//CRT�з������������ʣ��ֵ��ģֵ
long long n, a[maxn+10], m[maxn+10];

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

//�����±��1��ʼ
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
