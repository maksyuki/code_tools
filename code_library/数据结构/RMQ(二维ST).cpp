/***********************************************
************************************************
@�ӿ�: void RMQ_ST (int n, int m)
@����: ��άST��Ľ���
@ʱ�临�Ӷ�: O(n * n * log(n) * log(n))
@:

@�ӿ�: int RMQ_Findmax (int x1, int y1, int x2, int y2)
@����: ��ѯ[x1, y1]-[x2, y2]����Ӿ����е����ֵ
@ʱ�临�Ӷ�: O (1)
@:
************************************************/

int ans[maxn][maxn];
int dpmax[maxn][maxn][9][9];//���ֵ

void RMQ_ST (int n, int m)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dpmax[i][j][0][0] = ans[i][j];

    int mx = log(double(n)) / log(2.0);
    int my = log(double(m)) / log(2.0);
    for (int i = 0; i <= mx; i++)
    {
        for (int j = 0; j <= my; j++)
        {
            if (i == 0 && j ==0) continue;

            for (int p = 1; p + (1 << i) - 1 <= n; p++)
            {
                for(int q = 1; q + (1 << j) - 1 <= m; q++)
                {
                    if (i == 0)//y�����
                        dpmax[p][q][i][j] = max (dpmax[p][q][i][j-1], dpmax[p][q+(1<<(j-1))][i][j-1]);

                    else//x�����
                        dpmax[p][q][i][j] = max (dpmax[p][q][i-1][j], dpmax[p+(1<<(i-1))][q][i-1][j]);
                }
            }
        }
    }
}

int RMQ_Findmax (int x1, int y1, int x2, int y2)
{
    int kx = log(double(x2-x1+1)) / log(2.0);
    int ky = log(double(y2-y1+1)) / log(2.0);
    int m1 = dpmax[x1][y1][kx][ky];
    int m2 = dpmax[x2-(1<<kx)+1][y1][kx][ky];
    int m3 = dpmax[x1][y2-(1<<ky)+1][kx][ky];
    int m4 = dpmax[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
    return max (max(m1, m2), max (m3, m4));
}
