/***********************************************
************************************************
@�ӿ�: void Init ()
@����: ��ʼ���ڽӾ���
@ʱ�临�Ӷ�: O (n^2)
@:

@�ӿ�: long long Prim (int s)
@����: �����С������
@ʱ�临�Ӷ�: O (n^2)
@s: Դ��
************************************************/

const int maxn = 100 + 66;

bool vis[maxn];//��ʾ�ڵ��Ƿ�����С��������
//�ֱ��ʾ�ڽӾ��󡢽ڵ������С�������ľ���Ͷ���ĸ���
int edge[maxn][maxn], dis[maxn], n;

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

long long Prim (int s)
{
    memset (vis, false, sizeof (vis));
    long long res = 0;
    vis[s] = true;

    for (int i = 1; i <= n; i++)//��ʼ��Դ�����ڽӵĽڵ����С����������
        dis[i] = edge[s][i];

    for (int i = 2; i <= n; i++)
    {
        int minval = INF, minpos = s;
        for (int j = 1; j <= n; j++)//��������δ��MST�о�����С����ĵĽڵ��ҵ�
            if (j != s && !vis[j] && minval > dis[j])
            {
                minval = dis[j];
                minpos = j;
            }

        vis[minpos] = true;//���ʸýڵ�
        res += minval;//�ۼӱ�Ȩ

        for (int j = 1; j <= n; j++)//��������minpos�ڵ���뵽MST���µ���С����仯
            if (j != s && !vis[j] && edge[minpos][j] < dis[j])
                dis[j] = edge[minpos][j];
    }

    return res;
}
