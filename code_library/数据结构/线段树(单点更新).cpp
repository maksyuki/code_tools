/***********************************************
************************************************
@接口: void PushUp (int rt)
@时间复杂度: O (1)
@rt: 线段树的根节点序号

@接口: void Build (int rt, int l, int r)
@时间复杂度: O (n)
@rt: 线段树的根节点序号
@l: 当前区间的左端点
@r: 当前区间的右端点

@接口: void UpDate (int rt, int l, int r, int val, int num)
@时间复杂度: O (log (n))
@rt: 线段树的根节点序号
@l: 当前区间的左端点
@r: 当前区间的右端点
@val: 更新的位置
@num: 更新的值

@接口: void Query (int rt, int l, int r, int L, int R)
@时间复杂度: O (log (n))
@rt: 线段树的根节点序号
@l: 当前区间的左端点
@r: 当前区间的右端点
@L: 查询区间的左端点
@R: 查询区间的右端点
************************************************/

#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r

const int maxn = 55555;
int sum[maxn<<2];

void PushUp (int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void Build (int rt, int l, int r)
{
	if (l == r)
    {
		scanf("%d", &sum[rt]);
		return ;
	}

	int m = (l + r) >> 1;
	Build (lson);
	Build (rson);
	PushUp (rt);
}

void UpDate (int rt, int l, int r, int p, int add)
{
	if (l == r)
    {
		sum[rt] += add;
		return ;
	}

	int m = (l + r) >> 1;
	if (p <= m) UpDate (lson, p, add);
	else UpDate (rson, p, add);
	PushUp (rt);
}

int Query (int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return sum[rt];

	int m = (l + r) >> 1, ans = 0;
	if (L <= m) ans += Query (lson, L, R);
	if (R > m)  ans += Query (rson, L, R);
	return ans;
}

