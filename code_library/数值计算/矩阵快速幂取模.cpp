/***********************************************
����������A ^ n % p
************************************************
@�ӿ�: A * B
@ʱ�临�Ӷ�: O (n ^ 3)

@�ӿ�: A ^ B
@ʱ�临�Ӷ�: O (n ^ 2)
************************************************/

const int MOD = 1e9 + 7;
const int maxn = 2;
long long n = 2;//��ʾ����ĳߴ磬����ǡ��Ϊ����Ĵ�С

//�������
struct Mat
{
    long long mat[maxn][maxn];
};


//����Mat�˷�����
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

//����Mat��������
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
