/***********************************************
求解形如A ^ x = B (mod C)的高次同余方程
************************************************
@接口: void Insert (long long a, long long b)
@功能:
@时间复杂度:
@:

@接口: long long Find (long long b)
@功能:
@时间复杂度:
@:

@接口: long long gcd (long long a, long long b)
@功能:
@时间复杂度:
@:

@接口: long long gcd_ex (long long a, long long b, long long &x, long long &y)
@功能:
@时间复杂度:
@:

@接口: long long q_mul_mod (long long a, long long b, long long p)
@功能:
@时间复杂度:
@:

@接口: long long BabyStep_GiantStep (long long A, long long B, long long C)
@功能:
@时间复杂度:
@:
************************************************/

const int maxn = 110000 + 66;

struct HashNode
{
    long long data, id, next;
};

HashNode Hash[maxn<<1];
bool flag[maxn<<1];
long long top;

void Insert (long long a, long long b)
{
    long long k = b & maxn;
    if (flag[k] == false)
    {
        flag[k] = true;
        Hash[k].next = -1;
        Hash[k].id = a;
        Hash[k].data = b;
        return ;
    }

    while (Hash[k].next != -1)
    {
        if (Hash[k].data == b)
            return ;
        k = Hash[k].next;
    }

    if (Hash[k].data == b)
        return ;

    Hash[k].next = ++top;
    Hash[top].next = -1;
    Hash[top].id = a;
    Hash[top].data = b;
}

long long Find (long long b)
{
    long long k = b & maxn;
    if (flag[k] == false)
        return -1;

    while (k != -1)
    {
        if (Hash[k].data == b)
            return Hash[k].id;
        k = Hash[k].next;
    }

return -1;
}

long long gcd (long long a, long long b)
{
    return b ? gcd (b, a % b) : a;
}

long long gcd_ex (long long a, long long b, long long &x, long long &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = gcd_ex (b, a % b, y, x);
    y = y - a / b * x;
    return d;
}


long long q_mul_mod (long long a, long long b, long long p)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ((ans % p) * (a % p)) % p;
            b--;
        }

        b = b >> 1;
        a = ((a % p) * (a % p)) % p;
    }

return ans;
}

long long BabyStep_GiantStep (long long A, long long B, long long C)
{
    top = maxn;  B %= C;
    long long tmp = 1, i;

    for (i = 0; i <= 100; tmp = tmp * A % C, i++)
        if (tmp == B % C)
            return i;

    long long D = 1, cnt = 0;
    while ((tmp = gcd(A, C)) != 1)
    {
        if(B % tmp)
            return -1;

        C /= tmp;
        B /= tmp;
        D = D * A / tmp % C;
        cnt++;
    }

    long long M = (long long) ceil (sqrt (C + 0.0));

    for (tmp = 1, i = 0; i <= M; tmp = tmp * A % C, i++)
        Insert (i, tmp);

    long long x, y, K = q_mul_mod (A, M, C);
    for (i = 0; i <= M; i++)
    {
        gcd_ex (D, C, x, y); // D * X = 1 ( mod C )
        tmp = ((B * x) % C + C) % C;

        if((y = Find(tmp)) != -1)
            return i * M + y + cnt;

        D = D * K % C;
    }

return -1;
}

int main()
{
//    ifstream cin ("aaa.txt");

    long long A, B, C;
    while(cin >> A >> C >> B)
    {
        memset (flag, 0, sizeof(flag)); //要初始化flag数组
        long long ans = BabyStep_GiantStep (A, B, C);

        if (ans == -1)
            cout << "No Solution" << endl;

        else
            cout << ans << endl;
    }

return 0;
}
