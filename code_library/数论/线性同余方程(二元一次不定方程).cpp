/***********************************************
求解形如a * x + b * y = c的解集x和y
************************************************
@接口: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@功能: 求解a * x + b * y = gcd (a, b)的一组解x和y
@时间复杂度: O (b)
@a: 义同上述方程
@b: 义同上述方程
@x: 义同上述方程
@y: 义同上述方程

@接口: long long mod_equ (long long a, long long b, long long c)
@功能: 求解a * x + b * y = c的最小非负解x
@时间复杂度: O (b)
@a: 义同上述方程
@b: 义同上述方程
@c: 义同上述方程

@接口: long long mod_equ (long long a, long long b, long long c)
@功能: 求解a * x + b * y = c的解集x和y
@时间复杂度: O (b)
@a: 义同上述方程
@b: 义同上述方程
@c: 义同上述方程
************************************************/
//存储方程的解集
long long solx[maxn+10], soly[maxn+10];

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

//求解的是不定方程的最小非负值
long long mod_equ (long long a, long long b, long long c)
{
    long long x, y;
    long long d = gcd_ex (a, b, x, y);

    if (c % d)
        return -1;

    x = (x * c / d) % (b / d);
    x = (x + (b / d)) % (b / d);
//  if (x < 0)          对于ZOJ3609这道题，要求的是最小正值，而不是最小非负值，所以需要将判断条件进行修改
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
//  if (x < 0)          对于ZOJ3609这道题，要求的是最小正值，而不是最小非负值，所以需要将判断条件进行修改
//      x += b / d;

//  y = (y * c / d) % (a / d);
//  y = (y + (a / d)) % (a / d);
//  if (y < 0)          对于ZOJ3609这道题，要求的是最小正值，而不是最小非负值，所以需要将判断条件进行修改
//      y += a / d;

    y = (c - a * x) / b;
    for (long long i = 0; i < d; i++)
    {
        solx[i] = x + i * (b / d);
        soly[i] = y - i * (a / d);
    }
    return 1;
}
