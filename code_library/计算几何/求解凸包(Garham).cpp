/***********************************************
Garham扫描算法
************************************************
@接口: bool polarcmp (Point p1, Point p2)
@功能: 极角优先排序(若极角相同，则按极径排序)
@时间复杂度: O (1)
@p1: 待排序前一个点
@p2: 待排序后一个点

@接口: void Garham ()
@功能: 求凸包，凸包点集(下标)存储在栈sta中
@时间复杂度: O (nlogn) n表示点数
************************************************/

//分别表示点、点数
Point p[maxn];
int n;
stack <int> sta;//用来存储凸包点集，从栈顶到栈底依次顺时针存储凸包点集

//优先按照极角递增排序。若极角相等，则按照极径递增排序
bool polarcmp (Point p1, Point p2)
{
	double tt = (p1 - p[1]) ^ (p2 - p[1]);
	if (sgn (tt) == 1) return true;
	else if (sgn (tt) == 0 && sgn (Dist (p1, p[1]) - Dist (p2, p[1])) <= 0) return true;
	return false;
}

void Garham ()
{
	Point start = p[1];
	int start_pos = 1;
	for (int i = 1; i <= n; i++)//寻找凸包中第一个点(左下角的点)
		if (sgn (p[i].x - start.x) == -1 || (sgn (p[i].x - start.x) == 0 && sgn (p[i].y - start.y) == -1))
			start = p[i], start_pos = i;
	
	swap (p[start_pos], p[1]);
	sort (p + 2, p + n + 1, polarcmp);//相对于点p[1]进行极角排序
	while (!sta.empty ()) sta.pop ();

	if (n == 1) sta.push (1);
	else if (n == 2) sta.push (1), sta.push (2);
	else
	{
		sta.push (1), sta.push (2);
		for (int i = 3; i <= n; i++)
		{
			while (sta.size () >= 2)
			{
				int tt1 = sta.top (); sta.pop ();
				int tt2 = sta.top (); sta.pop ();
				if (sgn ((p[tt1] - p[tt2]) ^ (p[i] - p[tt2])) <= 0)//判断栈顶的两个点和当前点所构成的折线段是否拐向右侧
					sta.push (tt2);	
				else 
				{
					sta.push (tt2), sta.push (tt1);
					break;
				}
			}
			sta.push (i);
		}
	}
}