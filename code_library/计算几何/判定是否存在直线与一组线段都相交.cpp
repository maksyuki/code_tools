/***********************************************
POJ 3304
问题：判定是否存在直线与一组线段都相交

方法是枚举线段的两个端点连一条直线，再判断所有的线
段是否都和这条直线有交点。证明:若有直线L和所有线段
相交，则可保持L和所有线段相交，左右平移L到和某一线
段交于端点停止（“移不动了”）。然后绕这个交点旋转。
也是转到“转不动了”（和另一线段交于其一个端点）为止
。这样就找到了一个新的L满足题意，而且经过其中两线段
的端点。
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
	else return 1;
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

struct Line
{
	Point s, e;
	Line () {}
	Line (Point ss, Point ee) : s (ss), e (ee) {}
};

Line line[maxn];
int n;

bool SegInerLine (Line l1, Line l2)
{
	return sgn ((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn ((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}

bool check (Point a, Point b)
{
	if (sgn (a.x - b.x) == 0 && sgn (a.y - b.y) == 0) return false;
	Line tt = Line (a, b);
	for (int i = 1; i <= n; i++)
		if (!SegInerLine (tt, line[i]))
			return false;
	return true;
}

int main()
{
    //CFF;
    //CPPFF;
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			double x1, y1, x2, y2;
			scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			line[i] = Line (Point (x1, y1), Point (x2, y2));
		}

		bool is_have = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (check (line[i].s, line[j].s) || check (line[i].s, line[j].e) 
					|| check (line[i].e, line[j].s) || check (line[i].e, line[j].e))
				{
					is_have = true;
					break;
				}
			}

		if (is_have) puts ("Yes!");
		else puts ("No!");
	}
    return 0;
}
