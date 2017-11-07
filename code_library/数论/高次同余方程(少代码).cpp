const int maxn = 110000 + 66;

struct hashtable
{
    long long key[maxn];
    long long value[maxn];

    void Init()
    {
        for (long long i = 0; i < maxn; i++)
        {
            key[i] = -1, value[i] = -1;
        }
    }

    void Insert (long long k, long long v)
    {
        long long kk = k % maxn;

        while (key[kk] != -1 && key[kk] != k)
            kk = (kk + 1) % maxn;

        key[kk] = k,value[kk] = v;
    }

    long long Find (long long k)
    {
        long long kk = k % maxn;

        while (key[kk] != -1 && key[kk] != k)
            kk = (kk + 1) % maxn;

        return value[kk];
    }
}Hash;


long long baby_giant (long long x, long long k, long long z)
{
    x %= z,k %= z;
    long long m = (long long) ceil (sqrt (1.0 * z)), pre = 1;

    Hash.Init();Hash.Insert (k, 0);

    for (long long i = 1; i <= m; i++)
    {
        pre = (1ll * pre * x) % z;
        Hash.Insert ((1ll * pre * k) % z, i);
    }

    for (long long i = 0,xm = pre, y = 1; i * m <= z; i++)
    {
        long long j = Hash.Find (y);

        if (j >= 0 && i * m - j >= 0)
            return i * m - j;

        y = (1ll * y * xm) % z;
    }

return -1;
}


int main()
{
//    ifstream cin ("aaa.txt");

    long long A, B, C;

    while(cin >> A >> C >> B)
    {
        if (A == 0 && B == 0 && C == 0)
            break;

        long long ans = baby_giant(A, B, C);

        if(ans > 0)
            cout << ans << endl;

        else
            cout<<"No Solution"<<endl;
    }

return 0;
}
