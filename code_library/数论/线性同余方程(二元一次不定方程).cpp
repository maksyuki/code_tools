/***********************************************
�������a * x + b * y = c�Ľ⼯x��y
************************************************
@�ӿ�: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@����: ���a * x + b * y = gcd (a, b)��һ���x��y
@ʱ�临�Ӷ�: O (b)
@a: ��ͬ��������
@b: ��ͬ��������
@x: ��ͬ��������
@y: ��ͬ��������

@�ӿ�: long long mod_equ (long long a, long long b, long long c)
@����: ���a * x + b * y = c����С�Ǹ���x
@ʱ�临�Ӷ�: O (b)
@a: ��ͬ��������
@b: ��ͬ��������
@c: ��ͬ��������

@�ӿ�: long long mod_equ (long long a, long long b, long long c)
@����: ���a * x + b * y = c�Ľ⼯x��y
@ʱ�临�Ӷ�: O (b)
@a: ��ͬ��������
@b: ��ͬ��������
@c: ��ͬ��������
************************************************/
//�洢���̵Ľ⼯
long long solx[maxn+10], soly[maxn+10];

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

//�����ǲ������̵���С�Ǹ�ֵ
long long mod_equ (long long a, long long b, long long c)
{
    long long x, y;
    long long d = gcd_ex (a, b, x, y);

    if (c % d)
        return -1;

    x = (x * c / d) % (b / d);
    x = (x + (b / d)) % (b / d);
//  if (x < 0)          ����ZOJ3609����⣬Ҫ�������С��ֵ����������С�Ǹ�ֵ��������Ҫ���ж����������޸�
//      x += b / d;
    return x;
}

long long mod_equ (long long a, long long b, long long c)
{
    long long x, y;
    long long d = gcd_ex (a, b, x, y);

    if (c % d)
        return -1;

    x = (x * c / d) % (b / d);
    x = (x + (b / d)) % (b / d);
//  if (x < 0)          ����ZOJ3609����⣬Ҫ�������С��ֵ����������С�Ǹ�ֵ��������Ҫ���ж����������޸�
//      x += b / d;

//  y = (y * c / d) % (a / d);
//  y = (y + (a / d)) % (a / d);
//  if (y < 0)          ����ZOJ3609����⣬Ҫ�������С��ֵ����������С�Ǹ�ֵ��������Ҫ���ж����������޸�
//      y += a / d;

    y = (c - a * x) / b;
    for (long long i = 0; i < d; i++)
    {
        solx[i] = x + i * (b / d);
        soly[i] = y - i * (a / d);
    }
    return 1;
}
