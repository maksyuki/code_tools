/***********************************************
����Դ�㵽�����ڵ�����·��ע��������㷨����
������ͼ������ͼ��ֻ�Ƕ�������ͼ��˵�ڹ���߱�ʱ
ͬһ����Ҫ��������
************************************************
@�ӿ�: void bellman_ford (int s)
@ʱ�临�Ӷ�: O (n * m)
@s: Դ��
************************************************/

int dis[maxn], path[maxn];

void Bellman_ford (int s)
{
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
        path[i] = -1;
    }

    dis[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[edge[j].u] < INF && dis[edge[j].v] > dis[edge[j].u] + edge[j].w)
            {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
                path[edge[j].v] = edge[j].u;
            }
        }
    }
}
