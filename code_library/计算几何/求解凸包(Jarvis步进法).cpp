/***********************************************
Jarvis步进法
************************************************
Jarvis步进法(卷包裹法)
求解的过程类似于用一个麻绳绑住一个外面的钉子，然后
拉着麻绳绕所有的钉子一圈。这个麻绳所挂住的点就是凸
包。具体做法是先确定一个凸包上的点（一般取左下角的
点），然后以这个点为端点的射线绕着这个点从右边逆时
针旋转，找第一个在这个射线上的离端点最远的点作为一
个凸包上的点，以此类推，直到最后找到的点是起点为止
。具体做法可以使用叉积来线性判断最靠近右边的点，若
使用点积来判断在同一条直线上最靠外的点
************************************************
@接口: int SS (int u)
@功能: 找到下一个凸包中点的下标
@时间复杂度: O (n)
@u: 表示当前凸包中点的下标

@接口: void Jarvis ()
@功能: 求解凸包点集
@时间复杂度: O (n * m) n表示点数，m表示凸包中点数
************************************************/

//分别表示点、点数
Point p[maxn];
int n;
bool vis[maxn];//表示当前点是否是凸包点集
vector <int> res;//存储凸包点集(下标)，从前至后逆时针存储

int SS (int u)
{
	int pos = -1;
	for (int i = 1; i <= n; i++)
		if (i != u && !vis[i])
		{
			if (pos == -1) pos = i;
			else
			{
				double tt1 = CrossMul (p[u], p[i], p[pos]);
				if (sgn (tt1) == 1) pos = i;
				else if (sgn (tt1) == 0)
				{
					double tt2 = DotMul (p[pos], p[u], p[i]);
					if (sgn (tt2) == -1) pos = i;
				}
			}
		}
	vis[pos] = true;
	return pos;
}

void Jarvis ()
{
	Point start = p[1];	
	int start_pos = 1;
	for (int i = 1; i <= n; i++)//寻找凸包中的第一个点(左下角的点)
		if (sgn (p[i].x - start.x) == -1 || (sgn (p[i].x - start.x) == 0 && sgn (p[i].y - start.y)))
			start = p[i], start_pos = i;
	
	res.clear ();
	if (n == 1) res.push_back (1);
	else if (n == 2) res.push_back (1), res.push_back (2);
	else
	{
		memset (vis, false, sizeof (vis));
		int now = start_pos, next;
		while (1)
		{
			next = SS (now);
			res.push_back (next);
			now = next;
			if (now == start_pos) break;
		}
	}
}