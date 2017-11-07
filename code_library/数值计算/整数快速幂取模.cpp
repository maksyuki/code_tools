/***********************************************
�����������a ^ n % mod
************************************************
@�ӿ�: long long mult_mod (long long a,long long b,long long mod)
@����: ���ټ���(a * b) % mod
@ʱ�临�Ӷ�: O (log (n))
@a:����
@b:����
@mod:ȡģ��ֵ

@�ӿ�: long long pow_mod (long long a,long long n,long long mod)
@ʱ�临�Ӷ�: O (log (n))
@a:����
@b:ָ��
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

//���a�Ǹ���������Ҫ����ת������С�Ǹ�ֵ������
long long pow_mod (long long a,long long n,long long mod)
{
    long long ans = 1;
    long long temp = (a % mod + mod) % mod;//����aΪ��ֵʱ�Ŀ���
    while (n)
    {
        if (n & 1)
            ans = mult_mod (ans, temp, mod);

        temp = mult_mod (temp, temp, mod);
        n >>= 1;
    }
    return ans;
}
