/***********************************************
************************************************
@�ӿ�: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@����: ��ⲻ������a * x + b * y = gcd (a, b)�Ľ�x��y
@ʱ�临�Ӷ�: O (log (n))

@�ӿ�: long long mod_equ_set ()
@ʱ�临�Ӷ�: O (n * log (n))
************************************************/

//n��ʾ�������������a[i], m[i]�ֱ��ʾx = ai (mod mi)��ai��mi��ֵ
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
