/***********************************************
��ѯ�ڸ�������[1, n]�е���ֵ(����СֵΪ��)
************************************************
@�ӿ�: void RMQ_ST (int n)
@����: ST�Ľ���
@ʱ�临�Ӷ�: O (nlog(n))
@n: �������ֵ���еĳ���

@�ӿ�: inline int RMQ_Findmin (int L, int R)
@����: ��ѯ����[L, R]�е���Сֵ
@ʱ�临�Ӷ�: O (1)
@L: ������˵�
@R: �����Ҷ˵�
************************************************/


int dpmin[maxn][100], ans[maxn];

void RMQ_ST (int n)//����Ĵ������ֵ����Ҫ������С��1��ʼ
{
    for (int i = 1; i <= n; i++)
        dpmin[i][0] = ans[i];

    int m = (int) (log (n + 0.0) / log (2.0));
    for (int j = 1; j <= m; j++)
    {
        int t = n - (1 << j) + 1;
        for (int i = 1; i <= t; i++)
            dpmin[i][j] = min (dpmin[i][j-1], dpmin[i+(1<<(j-1))][j-1]);
    }
}

inline int RMQ_Findmin (int L, int R)
{
    int k = (int) (log (R - L + 1.0) / log (2.0));
    return min (dpmin[L][k], dpmin[R-(1<<k)+1][k]);
}
