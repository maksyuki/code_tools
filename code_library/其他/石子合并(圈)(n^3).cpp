/***********************************************
************************************************
@�ӿ�: int GetSum (int i, int j)
@����: ���[i,j]֮�����ĺ�(ѭ����)
@ʱ�临�Ӷ�:
@i:
@j:

@�ӿ�: void Solve (int n)
@����:
@ʱ�临�Ӷ�: O (n ^ 3)
@n: ���еĳ���
************************************************/

//�ֱ��ʾ�������Сֵ�ĵ������顢���ֵ�ĵ��������ǰ׺�ͱ�
int dpmin[maxn][maxn], dpmax[maxn][maxn], sum[maxn];
int minval, maxval, n;//��ʾ���кϲ������е���Сֵ�����ֵ�ʹ��ϲ����еĳ���

int GetSum (int i, int j)
{
    if (i + j >= n) return GetSum (i, n - i - 1) + GetSum (0, (i + j) % n);
    else return sum[i+j] - (i > 0 ? sum[i-1] : 0);
}

//������±��0��ʼ
void Solve (int n)
{
    for (int i = 0;i < n; i++)
        dpmin[i][0] = dpmax[i][0] = 0;

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            dpmin[i][j] = INF;
            dpmax[i][j] = 0;
            for (int k = 0; k < j; k++)
            {
                dpmin[i][j] = min (dpmin[i][j], dpmin[i][k] + dpmin[(i+k+1)%n][j-k-1] + GetSum (i, j));
                dpmax[i][j] = max (dpmax[i][j], dpmax[i][k] + dpmax[(i+k+1)%n][j-k-1] + GetSum (i, j));
            }
        }
    }
    minval = dpmin[0][n-1];
    maxval = dpmax[0][n-1];
    for (int i = 0; i < n; i++)
    {
        minval = min (minval, dpmin[i][n-1]);
        maxval = max (maxval, dpmax[i][n-1]);
    }
}
