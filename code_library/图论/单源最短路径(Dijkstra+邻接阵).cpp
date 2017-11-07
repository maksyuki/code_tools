/***********************************************
************************************************
@�ӿ�: void Init ()
@����: ��ʼ���ڽӾ���
@ʱ�临�Ӷ�: O (n ^ 2)
@:

@�ӿ�: void Dijkstra (int s)
@����: ����s��ʼ�����·
@ʱ�临�Ӷ�: O(n��^ 2)
@s: Դ��
************************************************/

const int maxn = 1000 + 66;

bool vis[maxn];//��ʾ�ڵ�����·�Ƿ��Ѿ��õ�
//�ֱ��ʾ�ڽӾ��󡢽ڵ����·�ĳ��ȺͶ���ĸ���
int edge[maxn][maxn], dis[maxn], n;

void Init ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j) edge[i][j] = 0;
            else edge[i][j] = INF;
        }
}

void Dijkstra (int s)
{
    memset (vis, false, sizeof (vis));;
    vis[s] = true;
    for (int i = 1; i <= n; i++)//��ʼ��Դ�����ڽӵĽڵ����̾���
        dis[i] = edge[s][i];

    dis[s] = 0;//Դ�㵽�Լ������·��0��ʮ����Ҫ!!!
    for (int i = 2; i <= n; i++)
    {
        int minval = INF, minpos = s;
        for (int j = 1; j <= n; j++)//��������δȷ�����·�Ľڵ��о�����С����ĵĽڵ��ҵ�
            if (j != s && !vis[j] && minval > dis[j])
            {
                minval = dis[j];
                minpos = j;
            }

        vis[minpos] = true;//���ʸýڵ�
        for (int j = 1; j <= n; j++)//��������minpos�ڵ�ȷ�����·֮���µ���С����仯
            if (j != s && !vis[j] && edge[minpos][j] < INF && edge[minpos][j] + dis[minpos] < dis[j])
                dis[j] = edge[minpos][j] + dis[minpos];
    }
}
