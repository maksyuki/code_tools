/***********************************************
求解整数expnum拆分的个数
************************************************
@接口: void GenerFunction (long long expnum, long long val)
@时间复杂度: o (n ^ 3)
@val: 待拆分的数
@expnum: 多项式的个数
************************************************/

const int maxn = 100 + 66;//maxn要大于待拆分数

int coeff[maxn], temp[maxn];//coeff数组存储多项式各次幂的系数，temp数组存储当前两个多项式相乘的临时结果

void Init ()
{
    memset (coeff, 0, sizeof (coeff));
    memset (temp, 0, sizeof (temp));
}

void GenerFunction (long long expnum, long long val)//在调用GenerFunction之前一定先调用Init函数
{
    for (long long i = 0; i <= val * 1; i += 1)
        coeff[i] = 1;

    for (long long i = 2; i <= expnum; i++)
    {
        for (long long j = 0; j <= val; j++)
        {
            for (long long k = 0; k + j <= val; k += i)
                temp[k+j] += coeff[j];
        }

        for (long long j = 0; j <= val; j++)
        {
            coeff[j] = temp[j];
            temp[j] = 0;
        }
    }
}
