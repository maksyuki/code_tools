/***********************************************
************************************************
@�ӿ�:
@����:
@ʱ�临�Ӷ�:
@:
************************************************/

long long factor[maxn+10], fac_len;//�����ӱ�ͱ�ĳ��ȣ�ע���ĳ���Ҫ��ʼ��Ϊ0

const int testnum = 8; //����㷨�ж�������һ��8~10�͹���
// ����ret = (a*b)%c a,b,c < 2^63

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod;
    b %= mod;
    long long ans = 0;
    long long temp = a;

    while (b)
    {
        if (b & 1)
        {
            ans += temp;
            if (ans > mod)
                ans -= mod;//ֱ��ȡģ���ܶ�
        }

        temp <<= 1;
        if (temp > mod)
            temp -= mod;
        b >>= 1;
    }

return ans;
}

long long pow_mod (long long a,long long n,long long mod)
{
    long long ans = 1;
    long long temp = a % mod;
    while (n)
    {
        if (n & 1)
            ans = mult_mod (ans, temp, mod);

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

    if(ans != 1)
        return true;

    else
        return false;
}

//**************************************************
// Miller_Rabin�㷨
// ����������true,(������α����)
// ������������false
//**************************************************
bool Miller_Rabin (long long n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if ((n&1) == 0)
        return false;//ż��

    long long x = n - 1;
    long long t = 0;

    while ((x&1) == 0)
    {
        x >>= 1; t++;
    }

//    srand (time (NULL));

    for (int i = 0; i < testnum; i++)
    {
        long long a = rand () % (n - 1) + 1;
        if (check (a, n, x, t))
            return false;
    }

return true;
}


long long gcd (long long a, long long b)
{
    if (a == 0)
        return 1;

    if (a < 0)
        return gcd (-a, b);

    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }

return a;
}

long long Pollard_Rho (long long x, long long c)
{
    long long i = 1, k = 2;
    long long x0 = rand () % x;
    long long y = x0;

    while (1)
    {
        i++;
        x0 = (mult_mod (x0, x0, x) + c) % x;
        long long d = gcd (y - x0, x);

        if (d != 1 && d != x)
            return d;

        if (y == x0)
            return x;

        if (i == k)
        {
            y = x0;k += k;
        }
    }
}

//��n���������ӷֽ�
void FindFac (long long n)
{
    if (Miller_Rabin (n))//����
    {
        factor[fac_len++] = n;
        return ;
    }

    long long p = n;
    while (p >= n)
        p = Pollard_Rho (p, rand () % (n - 1) + 1);

    FindFac (p);
    FindFac (n / p);
}
