/***********************************************
��ȫԴ���·��������ʹ���ڽӾ���������ڽӱ�����
ʼ����̾�������
************************************************
@�ӿ�: void floyd ()
@����: ��ȫԴ���·��
@ʱ�临�Ӷ�: O (n^3)
************************************************/

//�ֱ��ʾ�ڽӾ������̾�������
int edge[maxn][maxn], dis[maxn][maxn];
//�ֱ��ʾ��������ͱ���
int n, m;

//��ʼ���ڽӾ���
void Init ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                edge[i][j] = 0;

            else
                edge[i][j] = INF;
        }
}

//�����±��1��ʼ
void floyd ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = edge[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == k || j == k)
                    continue;

                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
            }
}
