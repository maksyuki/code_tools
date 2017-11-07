/***********************************************
求解多项式乘法中的系数
************************************************
@接口: void GenerFunction (long long expnum, long long upp)
@功能:
@时间复杂度: O (n ^ 3)
@expnum: 表达式的个数
@upp: 多项式的指数最高值
************************************************/

const int maxn = 100 + 66;//注意maxn要大于多项式指数的最高值
const int step[] = {6666, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21
, 22, 23, 24, 25, 26};//每个表达式的步长

//step数组可以按照题目要求是预先定义好，还是由程序读入！！！！！！

//coeff数组存储每一指数值下的系数值，temp数组存储当前两个多项式相乘的系数值，ans数组存储各个多项式的个数
long long coeff[maxn], temp[maxn], ans[maxn];

//ans数组可以按照题目的要求是表示每一个多项式中数的个数，是否由程序读入，还是
//使用两个数组s[maxn]和e[maxn]表示指数的上下界

void Init ()
{
    memset (coeff, 0, sizeof (coeff));
    memset (temp, 0, sizeof (temp));
}

//在调用GenerFunction之前一定先调用Init函数
void GenerFunction (long long expnum, long long upp)//所有数组的下标从1开始
{
    for (long long i = 0; i <= ans[1] * step[1]; i += step[1]) //初始化第一个多项式的系数值
        coeff[i] = 1;

    for (long long i = 2; i <= expnum; i++)
    {
        for (long long j = 0; j <= upp; j++)
        {
            for (long long k = 0; j + k <= upp && k <= ans[i] * step[i]; k += step[i])
                temp[k+j] += coeff[j];//x ^ k * x ^ j = x ^ (k + j)的系数值
        }

        for (long long j = 0; j <= upp; j++)
        {
            coeff[j] = temp[j];
            temp[j] = 0;
        }
    }
}
