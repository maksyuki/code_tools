/***********************************************
SPFA�㷨�Ƽ�ʹ���ڽӱ���Ϊ��ͼ�����ݽṹ
************************************************
@�ӿ�: void spfa (int s)
@����: ����Դ��s��ʼ�����·
@ʱ�临�Ӷ�: O(k * m)
@s: Դ��
************************************************/

//�ֱ��ʾ����v��w����һ���ڽӵ�λ��
struct Node
{
    int v, w, next;
};

Node edge[maxn*maxn];
int head[maxn], edgelen;//�ֱ��ʾ����ı�ͷ�ڵ�ͱߵ�����

//�����е��������ʼ��Ϊ-1
void Init ()
{
    memset (head, -1, sizeof (head));
    memset (edge, -1, sizeof (edge));
    edgelen = 0;
}

//ʹ��ͷ�巨����
void AddEdge (int u, int v, int w)
{
    edge[edgelen].v = v;
    edge[edgelen].w = w;
    edge[edgelen].next = head[u];
    head[u] = edgelen++;
}

//�ֱ��ʾԴ�㵽�����������̾��롢�����Ƿ��ڶ����е��ж����顢��������еĴ����Ͷ������
int dis[maxn], inq[maxn], cnt[maxn];
int n;

//��ʾ�Ƿ���ڸ�Ȩֵ��·��true��ʾ�����ڣ�false��ʾ����
bool is_valid;

//�����±��1��ʼ
void spfa (int s)
{
    for (int i = 1; i <= n; i++)//��ʼ��dis�����inq����
    {
        dis[i] = INF;
        inq[i] = cnt[i] = 0;
    }

    dis[s] = 0;//��Դ���dis����ֵ��ʼ��Ϊ0����Ҫ����
    is_valid = true;//��ʼ�����
    queue <int> qu;
    qu.push (s);
    inq[s]++;//��Դ���־Ϊ�ڶ�����
    cnt[s]++;
    while (!qu.empty ())
    {
        int tt = qu.front(); qu.pop (); inq[tt]--;

        if (cnt[tt] > n)
        {
            is_valid = false;
            return ;
        }

        int pa = head[tt];
        while (pa != -1)
        {
            int pb = edge[pa].v;
            if (dis[tt] < INF && dis[pb] > dis[tt] + edge[pa].w)//�ɳڲ���
            {
                dis[pb] = dis[tt] + edge[pa].w;
                if (!inq[pb])//������ɳڵĽڵ㲻�ڶ����У��򽫸ý����
                {
                    qu.push (pb);
                    inq[pb]++;
                    cnt[pb]++;
                }
            }
            pa = edge[pa].next;
        }
    }
}

