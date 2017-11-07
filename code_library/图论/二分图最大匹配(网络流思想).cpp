/***********************************************
ʹ��dfs�������㣬�����ڳ���ͼ
ע�⣺����㷨��˼��ǳ��������������㷨����Ҫ��
���ܽ�˼��
************************************************
@�ӿ�: int dfs (int u)
@����: ����dfs����
@ʱ�临�Ӷ�:
@u: ��ʾһ���Ǳ��͵�

@�ӿ�: int MaxMatch ()
@����: ���β��ҷǱ��͵����ƥ�䳢��
@ʱ�临�Ӷ�: O (n ^ 3)
************************************************/

//�ֱ��ʾ�����ƥ������Ͷ���ķ��ʱ�־
int match[maxn], vis[maxn];
vector <int> g[maxn];//ʹ���ڽӱ��ͼ

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
