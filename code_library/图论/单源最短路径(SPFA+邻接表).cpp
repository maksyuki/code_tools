/***********************************************
SPFA�㷨�Ƽ�ʹ���ڽӱ���Ϊ��ͼ�����ݽṹ
************************************************
@�ӿ�: bool spfa (int s)
@����: ����Դ��s��ʼ�����·�����޽��򷵻�false
@ʱ�临�Ӷ�: O(k * m)
@s: Դ��
************************************************/

//�ֱ��ʾ����v��w����һ���ڽӵ�λ��
struct Node
{
    int v, w, nxt;
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
    edge[edgelen].nxt = head[u];
    head[u] = edgelen++;
}

//�ֱ��ʾԴ�㵽�����������̾��롢�����Ƿ��ڶ����е��ж����顢��������еĴ����Ͷ������
int dis[maxn], inq[maxn], cnt[maxn];
int n;

//��ʾ�Ƿ���ڸ�Ȩֵ��·��true��ʾ�����ڣ�false��ʾ����
//bool is_valid;

//�����±��1��ʼ
bool spfa (int s)
{
    for (int i = 1; i <= n; i++)//��ʼ��dis�����inq����
    {
        dis[i] = INF;
        inq[i] = cnt[i] = 0;
    }

    dis[s] = 0;//��Դ���dis����ֵ��ʼ��Ϊ0����Ҫ����
    //is_valid = true;//��ʼ�����
    queue <int> qu;
    qu.push (s);
    inq[s]++, cnt[s]++;//��Դ���־Ϊ�ڶ�����
    while (!qu.empty ())
    {
        int u = qu.front(); qu.pop (); inq[u]--;
        if (cnt[u] > n) return false;

        for (int i = head[u]; i != -1; i = edge[i].nxt)
        {
            int v = edge[i].v;
            if (dis[u] < INF && dis[v] > dis[u] + edge[i].w)//�ɳڲ���
            {
                dis[v] = dis[u] + edge[i].w;
                if (!inq[v])//������ɳڵĽڵ㲻�ڶ����У��򽫸ý����
                {
                    qu.push (v);
                    inq[v]++, cnt[v]++;
                }
            }
        }
    }
	return true;
}
