/***********************************************
************************************************
@�ӿ�: long long Com (long long n, long long r)
@ʱ�临�Ӷ�: O (n)
@n:�����ϵ��
@r:�����ϵ��
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
