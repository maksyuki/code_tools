/***********************************************
************************************************
@�ӿ�: void Init ()
@����: ��ʼ���ڽӾ���
@ʱ�临�Ӷ�: O (n ^ 2)
@:

@�ӿ�: void Dijkstra (int s)
@����: ����s��ʼ�����·
@ʱ�临�Ӷ�: O(nlogn)
@s: Դ��
************************************************/
typedef pair <int, int> PII;

const int maxn = 1000 + 66;
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
    fill (dis, dis + maxn, INF);
    dis[s] = 0;//Դ�㵽�Լ������·��0��ʮ����Ҫ!!!
    priority_queue <PII, vector <PII>, greater <PII> > qu;
    qu.push (PII (0, s));
    while (!qu.empty ())
    {
        PII tt = qu.top (); qu.pop ();
        int ta = tt.second, tb = tt.first;
        if (dis[ta] < tb) continue;
        for (int i = 1; i <= n; i++)
            if (i != s && edge[ta][i] < INF && dis[i] > edge[ta][i] + dis[ta])
            {
                dis[i] = edge[ta][i] + dis[ta];
                qu.push (PII (dis[i], i));
            }
    }
}
