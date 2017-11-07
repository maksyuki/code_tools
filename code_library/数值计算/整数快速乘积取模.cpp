/***********************************************
�������(a * b) % mod
************************************************
@�ӿ�: long long mult_mod (long long a,long long b,long long mod)
@ʱ�临�Ӷ�: O (log (n))
@a:����
@b:����
@mod:ȡģ��ֵ
************************************************/

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod; b %= mod;
    long long ans = 0, temp = a;
    while (b)
    {
        if (b & 1)
        {
            ans += temp;
            if (ans > mod) ans -= mod;//ֱ��ȡģ���ܶ�
        }
        temp <<= 1;
        if (temp > mod) temp -= mod;
        b >>= 1;
    }
    return ans;
}
