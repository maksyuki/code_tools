/***********************************************
旋转卡壳(求平面最大三角形面积)

************************************************
@接口: double RotatingCalipers ()
@功能: 求解平面点对最大三角形面积
@时间复杂度: O (n)
************************************************/

//pp逆时针存储凸包点集，下标为0 ~ len - 1
Point pp[maxn];
int len;

double RotatingCalipers ()
{
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		int j = (i + 1) % len, k = (j + 1) % len;
		while (j != i && k != i)
		{
			res = max (res, abs ((pp[j] - pp[i]) ^ (pp[k] - pp[i])));
			while (((pp[i] - pp[j]) ^ (pp[(k+1)%len] - pp[k])) < 0)
				k = (k + 1) % len;
			j = (j + 1) % len;
		}
	}
	return (double) res / 2.0; 
}
