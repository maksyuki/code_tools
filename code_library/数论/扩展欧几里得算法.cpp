/***********************************************
求解a * x + b * y = gcd (a, b)的解x和y
************************************************
@接口: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@功能：求解a * x + b * y = gcd (a, b)的解x和y
@时间复杂度: O (b)
@a: 义同上述方程
@b: 义同上述方程
@x: 义同上述方程
@y: 义同上述方程
************************************************/

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}
