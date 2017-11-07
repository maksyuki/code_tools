/***********************************************
HDU 1392
问题：求解平面所给点集的凸包的周长

Jarvis步进法(卷包裹法)
求解的过程类似于用一个麻绳绑住一个外面的钉子，然后
拉着麻绳绕所有的钉子一圈。这个麻绳所挂住的点就是凸
包。具体做法是先确定一个凸包上的点（一般取左下角的
点），然后以这个点为端点的射线绕着这个点从右边逆时
针旋转，找第一个在这个射线上的离端点最远的点作为一
个凸包上的点，以此类推，直到最后找到的点是起点为止
。具体做法可以使用叉积来线性判断最靠近右边的点，若
使用点积来判断在同一条直线上最靠外的点
************************************************/

#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <bitset>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;

#define CFF freopen ("aaa.txt", "r", stdin)
#define CPPFF ifstream cin ("aaa.txt")
#define	DB(ccc)	cout << #ccc << " = " << ccc << endl
#define PB push_back
#define MP(A, B) make_pair(A, B)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef pair <int, int> PII;
typedef pair <int, bool> PIB;

const int INF = 0x7F7F7F7F;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos (0.0);
const int maxn = 166 + 66;

int sgn (double val)
{
	if (fabs (val) < EPS) return 0;
	else if (val < 0) return -1;
	return 1;
}

struct Point
{
	double x, y;
	Point () {}
	Point (double xx, double yy) : x (xx), y (yy) {}

	Point operator + (const Point &a) const
	{
		return Point (x + a.x, y + a.y);
	}

	Point operator - (const Point &a) const
	{
		return Point (x - a.x, y - a.y);
	}

	double operator ^ (const Point &a) const
	{
		return x * a.y - y * a.x;
	}

	double operator * (const Point &a) const
	{
		return x * a.x + y * a.y;
	}
};

double Dist (Point p1, Point p2)
{
	return sqrt ((p2 - p1) * (p2 - p1));
}

double CrossMul (Point p0, Point p1, Point p2)
{
	return (p1 - p0) ^ (p2 - p0);	
}

double DotMul (Point p0, Point p1, Point p2)
{
	return (p1 - p0) * (p2 - p0);
}

Point p[maxn];
int n;
bool vis[maxn];

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

double Jarvis ()
{
	Point start = p[1];	
	int start_pos = 1;
	for (int i = 1; i <= n; i++)
		if (sgn (p[i].x - start.x) == -1 || (sgn (p[i].x - start.x) == 0 && sgn (p[i].y - start.y)))
			start = p[i], start_pos = i;

	if (n == 1) return 0;
	else if (n == 2) return Dist (p[1], p[2]);
	else
	{
		double res = 0;
		memset (vis, false, sizeof (vis));
		int now = start_pos, next;
		while (1)
		{
			next = SS (now);
			res += Dist (p[now], p[next]);
			now = next;
			if (now == start_pos) break;
		}
		return res;
	}
}

int main()
{
    //CFF;
    //CPPFF;
	while (scanf ("%d", &n) != EOF)
	{
		if (n == 0) break;

		for (int i = 1; i <= n; i++)
		{
			double x, y;
			scanf ("%lf%lf", &x, &y);
			p[i] = Point (x, y);
		}
		printf ("%.2lf\n", Jarvis ());
	}
    return 0;
}
