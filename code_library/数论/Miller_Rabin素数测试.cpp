/***********************************************
Miller_Rabin 算法进行素数测试
快速判断一个 < 2^63 的数是不是素数
************************************************
@接口:
@功能:
@时间复杂度:
@:
************************************************/

const int testnum = 8; //随机算法判定次数，一般8~10就够了
// 计算ret = (a*b)%c a,b,c < 2^63

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod, b %= mod;
    long long ans = 0, temp = a;
    while (b)
    {
        if (b & 1)
        {
            ans += temp;
            if (ans > mod) ans -= mod;//直接取模慢很多
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

// 通过 a^(n-1)=1(mod n)来判断n是不是素数
// n-1 = x*2^t 中间使用二次判断
// 是合数返回true, 不一定是合数返回false
bool check (long long a, long long n, long long x, long long t)
{
    long long ans = pow_mod (a, x, n);
    long long last = ans;
    for(int i = 1; i <= t; i++)
    {
        ans = mult_mod (ans, ans, n);
        if(ans == 1 && last != 1 && last != n - 1)
            return true;//合数
        last = ans;
    }

    if(ans != 1) return true;
    else return false;
}

//**************************************************
// Miller_Rabin算法
// 是素数返回true,(可能是伪素数)
// 不是素数返回false
//**************************************************
bool Miller_Rabin (long long n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;//偶数

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
