/***********************************************
��ʽǰ��������������ͼ(��ʵҲ����������ͼ)
��һ���ڽӱ�ľ�̬ʵ�֣���ֱ��ʹ��vectorҪ��
Ĭ�Ϲ�����ǳ��߱�
************************************************
@�ӿ�: void Init ()
@����: ��ʼ������
@ʱ�临�Ӷ�: O (1)

@�ӿ�: void AddEdge (int u, int v, int w)
@����: ������ʽǰ����
@ʱ�临�Ӷ�: O (1)
@u: ʼ��
@v: �յ�
@w: ��Ȩ
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
