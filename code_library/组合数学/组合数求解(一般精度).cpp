/***********************************************
************************************************
@接口: long long Com (long long n, long long r)
@时间复杂度: O (n)
@n:组合数系数
@r:组合数系数
************************************************/

long long Com (long long n, long long r)
{
    if(n - r < r)
        r = n - r;

    long long s = 1;
    long long j = 1, i;

    for(i = 0;i < r; i++)
    {
        s *= (n - i);
        while (j <= r && s % j == 0)
        {
            s /= j;
            j++;
        }
    }

return s;
}
