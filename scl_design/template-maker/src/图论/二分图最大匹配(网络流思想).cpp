/***********************************************
使用dfs进行增广，适用于稠密图
注意：这个算法的思想非常类似于匈牙利算法，需要好
好总结思考
************************************************
@接口: int dfs (int u)
@功能: 进行dfs增广
@时间复杂度:
@u: 表示一个非饱和点

@接口: int MaxMatch ()
@功能: 依次查找非饱和点进行匹配尝试
@时间复杂度: O (n ^ 3)
************************************************/

//分别表示顶点的匹配情况和顶点的访问标志
int match[maxn], vis[maxn];
vector <int> g[maxn];//使用邻接表存图

int dfs (int u)
{
	vis[u] = true;
	for (int i = 0; i < g[u].size (); i++)
	{
		int v = g[u][i], t = match[v];
		if (t < 0 || (!vis[t] && dfs (t)))
		{
			match[u] = v;
			match[v] = u;
			return 1; 
		}
	}
	return 0;
}

int maxmatch ()
{
	int res = 0;
	memset (match, -1, sizeof (match));
	for (int i = 0; i < n; i++)
		if (match[i] == -1)
		{
			memset (vis, 0, sizeof (vis));
			res += dfs (i);
		}
	return res;
}
