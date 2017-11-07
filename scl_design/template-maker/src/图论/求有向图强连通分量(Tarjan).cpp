/***********************************************
求解有向图强连通分量的Tarjan算法
复杂度为O (n + m)

Tarjan算法本质上是构建一个dfs优先生成树，然后在
树上通过引入回边的概念来求解

求法：
在进行dfs搜索时，把当前搜索树中未处理的顶点压入
栈中，回溯时判定。当dfn[u] == low[u]时，则以u为
根的子树上的所有节点是一个强连通分量。重点是如何
判定一个边是dfs生成树的边、回边还是交叉边。方法
是若顶点u的邻接点v还未访问，则<u,v>是生成树的边。
否则v已经访问了，不是生成树的边了。接着若邻接点v
还在栈中，即顶点u和v在一个强连通分量中，v是u的祖
先，则<u,v>是回边。反之，邻接点v不在栈中，即顶点
u和v不在一个强连通分量中，则<u,v>是交叉边
************************************************
@接口: void Init (int rt)
@功能:初始化邻接表
@时间复杂度: O (n)

@接口: void dfs (int u)
@功能: dfs求解所有节点的dfn和low值
@时间复杂度: O (n + m)
@u: 当前节点

@接口: void SS ()
@功能: 求解给定有向图的强连通分量(原图可以不连通)
@时间复杂度: O (n + m)
************************************************/

//分别表示顶点的dfn值、low值和顶点所属的强连通分量标号
int dfn[maxn], low[maxn], belong[maxn];
bool instack[maxn];//表示顶点是否在栈中
stack <int> sta;
vector <int> g[maxn];//邻接表存图
int n, m, id, tot;//分别表示顶点数、边数、dfs优先生成树的全局标记和强连通分量的个数

void Init ()
{
	for (int i = 0; i < maxn; i++)
		g[i].clear ();
}

void dfs (int u)
{
	dfn[u] = low[u] = ++id;
	sta.push (u);
	instack[u] = true;
	for (int i = 0; i < g[u].size (); i++)
	{
		int v = g[u][i];
		if (!dfn[v])
		{
			dfs (v);
			low[u] = min (low[u], low[v]);
		}
		else if (instack[v])
			low[u] = min (low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		tot++;
		int tt;
		do
		{
			tt = sta.top (); sta.pop ();
			instack[tt] = false;
			belong[tt] = tot;
		} while (!sta.empty () && tt != u);
	}
}

void SS ()
{
	memset (dfn, 0, sizeof (dfn));
	memset (low, 0, sizeof (low));
	memset (instack, false, sizeof (instack));
	while (!sta.empty ()) sta.pop ();
	tot = id = 0;	
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			dfs (i);
}
