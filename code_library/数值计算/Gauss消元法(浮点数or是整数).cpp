/***********************************************
Guass��Ԫ��������Է�����(���Ǹ�����or����)
************************************************
@�ӿ�: int Guass (int row, int col)
@����:
@ʱ�临�Ӷ�: O (n ^ 3)
@row: ���̵ĸ���
#col: δ֪Ԫ�ĸ���
************************************************/

//�ֱ��ʾ��������������ͽ⼯
double a[maxn][maxn], x[maxn];

//return -1��ʾ�������޽⣬return 0��ʾ��������Ψһ�⣬return 1��ʾ�������������
int Guass (int row, int col)//row��ʾrow������,col��ʾcol��δ֪Ԫ
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

//���n��������
void OutPut (int n)
{
    int tt;
    for (int i = 1; i <= n; i++)
    {
        tt = x[i] + EPS;
        cout << tt << endl;
    }
}
