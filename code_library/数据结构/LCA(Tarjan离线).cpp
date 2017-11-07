/***********************************************
************************************************
@�ӿ�: void AddEdge (int a, int b)
@����:
@ʱ�临�Ӷ�:
@a:
@b:

@�ӿ�: int UnFind (int val)
@����:
@ʱ�临�Ӷ�:
@:

@�ӿ�: void Merge (int x, int y)
@����:
@ʱ�临�Ӷ�:
@:

@�ӿ�: void Init ()
@����:
@ʱ�临�Ӷ�:
@:

@�ӿ�: void LCA (int rt)
@����:
@ʱ�临�Ӷ�:
@rt:
************************************************/

const int maxn = 10000 + 66;
//�ֱ��ʾ�ڽӱ��ͷ�ڵ����ȱ����ڵ��ʹ𰸱�
int head[maxn], ind[maxn], parent[maxn], ans[maxn];
int tot, vala, valb, n;//�ֱ��ʾ�Ѿ������ڽӱ��еĽڵ��������ѯ�Ľڵ�1����ѯ�Ľڵ�2�ͽڵ���ܸ���
bool visited[maxn];//��ʾ�ڵ��Ƿ��Ѿ����ʹ�

struct Node
{
    int to;
    int next;
}edge[maxn];

void AddEdge (int a, int b)
{
    edge[tot].to = b;
    edge[tot].next = head[a];
    head[a] = tot++;
}

int UnFind (int val)
{
    if (parent[val] == val)
        return val;

return parent[val] = UnFind (parent[val]);
}

void Merge (int x, int y)
{
    int a = UnFind (x);
    int b = UnFind (y);
    if (a == b)
        return ;

    parent[b] = a;
}

void Init ()
{
    tot = 0;//ʮ����Ҫ��һ��Ҫ��ס��ʼ��Ϊ0
    memset (head, -1, sizeof (head));
    memset (ind, 0, sizeof (ind));
    memset (visited, 0, sizeof (visited));

    for (int i = 1; i <= n; i++)
        parent[i] = i;
}


void LCA (int rt)
{
    ans[rt] = rt;
    for(int i = head[rt]; i != -1; i = edge[i].next)
    {
        LCA (edge[i].to);
        Merge (rt, edge[i].to);
        ans[UnFind(rt)] = rt;   //�п���rt�����������ĸ�������Ҫ�����
    }

    visited[rt] = true;
    if (rt == vala)
    {
        if (visited[valb])
            printf ("%d\n", ans[UnFind(valb)]);
    }

    else if (rt == valb)
    {
        if (visited[vala])
            printf("%d\n", ans[UnFind(vala)]);
    }
}

int main()
{
//    ifstream cin("aaa.txt");

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        Init ();

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            AddEdge (u, v);
            ind[v]++;
        }

        cin >> vala >> valb;
        for (int i = 1; i <= n; i++)
            if (!ind[i])
                LCA (i);
    }

return 0;
}
