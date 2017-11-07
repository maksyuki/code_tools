/***********************************************
ʹ��dfs�������㣬�����ڳ���ͼ
************************************************
@�ӿ�: void Init ()
@����: ��ʼ���ڽӾ���
@ʱ�临�Ӷ�: O (n ^ 2)

@�ӿ�: int dfs (int u)
@����: ����dfs����
@ʱ�临�Ӷ�:
@u: ��ʾһ���Ǳ��͵�

@�ӿ�: long long MaxMatch ()
@����: ���β��ҷǱ��͵����ƥ�䳢��
@ʱ�临�Ӷ�: O (n ^ 3)
************************************************/

//�ֱ��ʾ�ڽӾ���Ͷ���ķ��ʱ�־
int edge[maxn][maxn], vis[maxn];
int cx[maxn], cy[maxn], cxlen, cylen;//cx[i]��ʾ����cx����iƥ���cy�����еĽڵ�ͼ����е�ĸ���

void Init ()//��ʼ���ڽӾ���
{
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            edge[i][j] = INF;
}

//����dfs����
int dfs (int u)
{
    for (int v = 1; v <= cylen; v++)
        if (edge[u][v] < INF && !vis[v])
        {
            vis[v] = 1;
            if (cy[v] == -1 || dfs (cy[v]))
            {
                cy[v] = u;
                cx[u] = v;
                return 1;
            }
        } 
    return 0;
}

//�����±��1��ʼ
long long MaxMatch ()
{
    long long res = 0;
    memset (cx, -1, sizeof (cx));//��ʼ������cx
    memset (cy, -1, sizeof (cy));//��ʼ������cy
    for (int i = 1; i <= cxlen; i++)
        if (cx[i] == -1)
        {
            memset (vis, 0, sizeof (vis));
            res += dfs (i);
        }
    return res;
}
