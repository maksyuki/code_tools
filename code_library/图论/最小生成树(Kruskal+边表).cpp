/***********************************************
************************************************
@接口: int UnFind (int val)
@时间复杂度: O (n)
@val: 节点的序号

@接口: void kruskal
@时间复杂度: O (n)
************************************************/

const int maxn = 1e6+66;

struct Node
{
    int u, v, w;
};

Node a[maxn];
int parent[maxn], n, r;

bool cmp (Node aa, Node bb)
{
	return aa.w < bb.w;
}

int UnFind (int val)
{
	if (parent[val] == val)
		return val;

	return parent[val] = UnFind (parent[val]);
}

long long kruskal ()
{
    long long remain = n, res = 0;
    for (int i = 1; i <= r && remain > 1; i++)
	{
        if (UnFind (a[i].u) != UnFind(a[i].v))
		{
            parent[UnFind(a[i].u)] = UnFind (a[i].v);
            remain--;
            res += a[i].w;
		}
	}

return res;
}
