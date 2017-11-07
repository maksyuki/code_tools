/***********************************************
���a * x + b * y = gcd (a, b)�Ľ�x��y
************************************************
@�ӿ�: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@���ܣ����a * x + b * y = gcd (a, b)�Ľ�x��y
@ʱ�临�Ӷ�: O (b)
@a: ��ͬ��������
@b: ��ͬ��������
@x: ��ͬ��������
@y: ��ͬ��������
************************************************/

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}
