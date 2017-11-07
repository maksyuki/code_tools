/***********************************************
************************************************
@接口: void AddEdge (int a, int b)
@功能:
@时间复杂度:
@a:
@b:

@接口: int UnFind (int val)
@功能:
@时间复杂度:
@:

@接口: void Merge (int x, int y)
@功能:
@时间复杂度:
@:

@接口: void Init ()
@功能:
@时间复杂度:
@:

@接口: void LCA (int rt)
@功能:
@时间复杂度:
@rt:
************************************************/

const int maxn = 10000 + 66;
//分别表示邻接表的头节点表、入度表、父节点表和答案表
int head[maxn], ind[maxn], parent[maxn], ans[maxn];
int tot, vala, valb, n;//分别表示已经插入邻接表中的节点个数、查询的节点1、查询的节点2和节点的总个数
bool visited[maxn];//表示节点是否已经访问过

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
    tot = 0;//十分重要，一定要记住初始化为0
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
        ans[UnFind(rt)] = rt;   //有可能rt并不是新树的根，所以要加这句
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
