
bool vis[maxn];
int out[maxn], len, dfstack[maxn], slen;

void sdfs (int val)
{
	slen = len = 0, dfstack[slen++] = val;
	memset (vis, 0, sizeof (vis));
	while (slen > 0)
	{
		int tt = dfstack[--slen];
		bool is_find = false;
		for (int i = head[tt]; i != -1; i = edge[i].nxt)
			if (!vis[edge[i].w])
			{
				vis[edge[i].w] = true;
				dfstack[slen++] = tt;
				dfstack[slen++] = edge[i].v;
				is_find = true;
				break;
			}
		if (!is_find)
			out[len++] = tt;
	}
}

