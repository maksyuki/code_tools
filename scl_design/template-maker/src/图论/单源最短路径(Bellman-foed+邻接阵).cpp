/***********************************************
************************************************
@�ӿ�: void Init ()
@����:  ��ʼ���ڽӾ���
@ʱ�临�Ӷ�: O (n ^ 2)

@�ӿ�: void Bellman_ford (int s)
@����: ���ӿ�ʼ�ĵ�Դ���·
@ʱ�临�Ӷ�:  O (n ^ 3)
@s: Դ��
************************************************/

//�ֱ��ʾ�ڵ㵽Դ�����̾��롢�ڽӾ���Ͷ������
int dis[maxn], edge[maxn][maxn], n;

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
void Bellman_ford (int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    dis[s] = 0;
    for (int i = 1; i < n; i++)//����n-1��
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != s)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (dis[k] < INF && edge[k][j] < INF && dis[k] + edge[k][j] < dis[j])
                        dis[j] = dis[k] + edge[k][j];
                }
            }
        }
    }
    //�жϸ�Ȧ�Ļ���Ҫ�ٽ���һ�ε��������Ƿ����һ����v��dis[v]���ٴα��ɳ�
    //������ڣ���˵��ͼ�д��ڸ�Ȧ
}
