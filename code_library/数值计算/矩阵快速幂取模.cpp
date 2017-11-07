/***********************************************
快速求解矩阵A ^ n % p
************************************************
@接口: A * B
@时间复杂度: O (n ^ 3)

@接口: A ^ B
@时间复杂度: O (n ^ 2)
************************************************/

const int MOD = 1e9 + 7;
const int maxn = 2;
long long n = 2;//表示方阵的尺寸，必须恰好为运算的大小

//申请变量
struct Mat
{
    long long mat[maxn][maxn];
};


//重载Mat乘法运算
Mat operator * (Mat a, Mat b)
{
    Mat c;
    memset (c.mat, 0, sizeof (c.mat));
    for (long long k = 0; k < n; k++)
    {
        for (long long i = 0; i < n; i++)
        {
            if (a.mat[i][k] == 0) continue;
            for (long long j = 0; j < n; j++)
            {
                if (b.mat[k][j] == 0) continue;
                c.mat[i][j] = (c.mat[i][j] + ((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD) % MOD)) % MOD;
            }
        }
    }
	return c;
}

//重载Mat乘幂运算
Mat operator ^ (Mat a, long long k)
{
    Mat c;
    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < n; j++)
            c.mat[i][j] = (i == j);

    while (k)
    {
        if (k & 1) c = c * a;
        a = a * a;
        k >>= 1;
    }
	return c;
}
