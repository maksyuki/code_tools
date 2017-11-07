/***********************************************
Miller_Rabin �㷨������������
�����ж�һ�� < 2^63 �����ǲ�������
************************************************
@�ӿ�:
@����:
@ʱ�临�Ӷ�:
@:
************************************************/

const int testnum = 8; //����㷨�ж�������һ��8~10�͹���
// ����ret = (a*b)%c a,b,c < 2^63

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod, b %= mod;
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

long long pow_mod (long long a,long long n,long long mod)
{
    long long ans = 1, temp = a % mod;
    while (n)
    {
        if (n & 1) ans = mult_mod (ans, temp, mod);
        temp = mult_mod (temp, temp, mod);
        n >>= 1;
    }
	return ans;
}

// ͨ�� a^(n-1)=1(mod n)���ж�n�ǲ�������
// n-1 = x*2^t �м�ʹ�ö����ж�
// �Ǻ�������true, ��һ���Ǻ�������false
bool check (long long a, long long n, long long x, long long t)
{
    long long ans = pow_mod (a, x, n);
    long long last = ans;
    for(int i = 1; i <= t; i++)
    {
        ans = mult_mod (ans, ans, n);
        if(ans == 1 && last != 1 && last != n - 1)
            return true;//����
        last = ans;
    }

    if(ans != 1) return true;
    else return false;
}

//**************************************************
// Miller_Rabin�㷨
// ����������true,(������α����)
// ������������false
//**************************************************
bool Miller_Rabin (long long n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;//ż��

    long long x = n - 1, t = 0;
    while ((x & 1) == 0) x >>= 1, t++;

    srand (time (NULL));
    for (int i = 0; i < testnum; i++)
    {
        long long a = rand () % (n - 1) + 1;
        if (check (a, n, x, t))
            return false;
    }
	return true;
}
