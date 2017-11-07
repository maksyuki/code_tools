/***********************************************
基础计算几何
************************************************

************************************************/

const double EPS = 1e-10;
const double PI = 2 * acos (0.0);

//判断a的正负性，若a == 0，则返回0。若a < 0，则返回-1。若a > 0，则返回1
int sgn (double a)
{
	if (fabs (a) < EPS) return 0;
	else if (a < 0) return -1;
	else return 1;
}

struct Point
{
	double x, y;
	Point () {}
	Point (double xx, double yy) : x (xx), y (yy) {}
	//矢量相加
	Point operator + (const Point &a) const
	{
		return Point (x + a.x, y + a.y);
	}
	//矢量相减
	Point operator - (const Point &a) const
	{
		return Point (x - a.x, y - a.y);
	}
	//叉积
	double operator ^ (const Point &a) const
	{
		return x * a.y - y * a.x;
	}
	//点积
	double operator * (const Point &a) const
	{
		return x * a.x + y * a.y;	
	}
	//绕原点旋转角度ang(弧度制)之后X和Y的变化
	void TransXY (double ang)
	{
		double tx = x, ty = y;
		x = tx * cos (ang) - ty * sin (ang);
		y = tx * sin (ang) + ty * cos (ang);
	}
};

struct Line
{
	Point s, e;
	Line () {}
	Line (Point ss, Point ee) : s (ss), e (ee) {}
	//两直线相交求交点
	//第一个值为0表示直线重合，为1表示直线平行，为2表示相交，只有2是符合条件的
	pair <int, Point> operator & (const Line &a) const
	{
		Point res = s;
		if (sgn ((s - e) ^ (a.s - a.e)) == 0)
		{
			if (sgn ((s - a.e) ^ (a.s - a.e)) == 0)
				return make_pair (0, res);
			else return make_pair (1, res);
		}
		double t = ((s - a.s) ^ (a.s - a.e)) / ((s - e) ^ (a.s - a.e));
		res.x += (e.x - s.x) * t;
		res.y += (e.y - s.y) * t;
		return make_pair (2, res);
	}
};

//返回两点间距离
double Dist (Point p1, Point p2)
{
	return sqrt ((p2 - p1) * (p2 - p1));
}
//返回矢量p1p0和p2p0的叉积
double CrossMul (Point p0, Point p1, Point p2)
{
	return (p1 - p0) ^ (p2 - p0);	
}
//返回矢量p1p0和p2p0的点积
double DotMul (Point p0, Point p1, Point p2)
{
	return (p1 - p0) * (p2 - p0);
}

//点到直线距离
//返回为result,是点到直线最近的点
Point PointToLine (Point P, Line L)
{
	Point result;
	double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
	result.x = L.s.x + (L.e.x - L.s.x) * t;
	result.y = L.s.y + (L.e.y - L.s.y) * t;
	return result;
}


//点到线段的距离
//返回点到线段最近的点
Point NearestPointToLineSeg (Point P, Line L)
{
	Point result;
	double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
	if (t >= 0 && t <= 1)
	{
		result.x = L.s.x + (L.e.x - L.s.x) * t;
		result.y = L.s.y + (L.e.y - L.s.y) * t;
	}
	else
	{
		if (dist (P, L.s) < dist (P, L.e))
			result = L.s;
		else 
			result = L.e;
	}
	return result;
}


//判断点在线段上
bool OnSeg (Point P, Line L)
{
	return
	sgn ((L.s - P) ^ (L.e - P)) == 0 &&
	sgn ((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn ((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

//判断点在凸多边形内
//点形成一个凸包，而且按逆时针排序（如果是顺时针把里面的<0改为>0）
//点的编号:0~n-1
//返回值：
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inConvexPoly (Point a, Point p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (sgn ((p[i] - a) ^ (p[(i+1)%n] - a)) < 0) return -1;
		else if (OnSeg (a, Line (p[i], p[(i+1)%n]))) return 0;
	}
	return 1;
}


//判断点在任意多边形内
//射线法，poly[]的顶点数要大于等于3,点的编号0~n-1
//返回值
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inPoly (Point p, Point poly[], int n)
{
	int cnt;
	Line ray, side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -100000000000.0;//-INF,注意取值防止越界
	for (int i = 0; i < n; i++)
	{
		side.s = poly[i];
		side.e = poly[(i+1)%n];
		if (OnSeg (p, side)) return 0;
		//如果平行轴则不考虑
		if (sgn (side.s.y - side.e.y) == 0) continue;
		if (OnSeg (side.s, ray))
		{
			if (sgn (side.s.y - side.e.y) > 0) cnt++;
		}
		else if (OnSeg (side.e, ray))
		{
			if (sgn (side.e.y - side.s.y) > 0) cnt++;
		}
		else if (inter (ray, side))
			cnt++;
	}

	if (cnt % 2 == 1) return 1;
	else return -1;
}

//判断线段相交
bool inter (Line l1, Line l2)
{
	return
	max (l1.s.x, l1.e.x) >= min (l2.s.x, l2.e.x) &&
	max (l2.s.x, l2.e.x) >= min (l1.s.x, l1.e.x) &&
	max (l1.s.y, l1.e.y) >= min (l2.s.y, l2.e.y) &&
	max (l2.s.y, l2.e.y) >= min (l1.s.y, l1.e.y) &&
	sgn ((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn ((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
	sgn ((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn ((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

//判断直线和线段相交
bool SegInterLine (Line l1, Line l2) //判断直线l1和线段l2是否相交
{
	return sgn ((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn ((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}

//判断凸多边形
//允许共线边
//点可以是顺时针给出也可以是逆时针给出
//点的编号1~n-1
bool isConvex (Point poly[], int n)
{
	bool s[3];
	memset (s, false, sizeof(s));
	for (int i = 0; i < n; i++)
	{
		s[sgn((poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]))+1] = true;
		if (s[0] && s[2]) return false;
	}
	return true;
}

//计算多边形面积
//点的编号从0 ~ n-1
double calcArea (Point p[], int n)
{
	double res = 0;
	for(int i = 0; i < n; i++)
		res += (p[i] ^ p[(i+1)%n]) / 2;
	return fabs (res);
}
