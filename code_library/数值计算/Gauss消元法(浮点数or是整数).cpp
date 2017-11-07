/***********************************************
Guass消元法求解线性方程组(解是浮点数or整数)
************************************************
@接口: int Guass (int row, int col)
@功能:
@时间复杂度: O (n ^ 3)
@row: 方程的个数
#col: 未知元的个数
************************************************/

//分别表示方程组的增广矩阵和解集
double a[maxn][maxn], x[maxn];

//return -1表示方程组无解，return 0表示方程组有唯一解，return 1表示方程组有无穷解
int Guass (int row, int col)//row表示row个方程,col表示col个未知元
{
    int k, xx, yy, mx = 0;
    double sum = 0;
    for(xx = 1, yy = 1; xx <= row && yy <= col; xx++, yy++)
    {
        mx = xx;
        for (int i = xx + 1; i <= row; i++)
            if (fabs(a[i][yy]) > fabs (a[mx][yy]))
                mx = i;

        if (mx != xx)
        {
            for (int i = yy; i <= col + 1; i++)
                swap(a[xx][i], a[mx][i]);
        }

        if (fabs(a[xx][yy]) < EPS)
        {
            xx--;
            continue;
        }

        for (int i = xx + 1; i <= row; i++)
        {
            if (fabs(a[i][yy]) < EPS) continue ;

            for (int j = yy + 1; j <= col + 1; j++)
                a[i][j] = (a[i][j] * a[xx][yy] - a[xx][j] * a[i][yy]) / a[xx][yy];
            a[i][yy] = 0;
        }
    }

    for (int i = xx; i <= row; i++)
        if (fabs(a[i][yy]) > EPS)
            return -1;

    if (xx <= col)
        return 1;

    for (int i = col; i >= 1; i--)
    {
        sum = 0;
        for (int j = i + 1; j <= col; j++)
            sum += a[i][j] * x[j];

        x[i] = (a[i][col+1] - sum) / a[i][i];
    }
    return 0;
}

//输出n个整数解
void OutPut (int n)
{
    int tt;
    for (int i = 1; i <= n; i++)
    {
        tt = x[i] + EPS;
        cout << tt << endl;
    }
}
