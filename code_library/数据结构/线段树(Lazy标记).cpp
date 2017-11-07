/***********************************************
************************************************
@接口: void PushUp (int rt)
@时间复杂度: O (1)
@rt: 线段树的根节点序号

@接口: void PushDown (int rt, int l, int m, int r)
@时间复杂度: O (1)
@rt: 线段树的根节点序号
@l: 当前区间的左端点
@m: 当前区间的中点
@r: 当前区间的右端点

@接口: void Build (int rt, int l, int r)
@时间复杂度: O (n)
@rt: 线段树的根节点序号
@l: 当前区间的左端点
@r: 当前区间的右端点

@接口: void UpDate (int rt, int l, int r, int L, int R, int val)
@时间复杂度: O (log (n))
@rt: 线段树的根节点序号
@l: 当前区间的左端点
@r: 当前区间的右端点
@L: 更新区间的左端点
@R: 更新区间的右端点
@val: 更新的值

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

const int maxn = 100000 + 66;
long long lazy[maxn<<2];
long long sum[maxn<<2];

void PushUp (int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown (int rt, int l, int m, int r)
{
    if (lazy[rt])
    {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        sum[rt<<1] += lazy[rt] * (m - l + 1);
        sum[rt<<1|1] += lazy[rt] * (r - m);
        lazy[rt] = 0;
    }
}

void Build (int rt, int l, int r)
{
    lazy[rt] = 0;
    if (l == r)
    {
        scanf ("%lld", &sum[rt]);
        return ;
    }

    int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
	Build (lson);
	Build (rson);
	PushUp (rt);
}

void UpDate (int rt, int l, int r, int L, int R, int add)
{
	if (L <= l && r <= R)
    {
		lazy[rt] += add;
		sum[rt] += add * (r - l + 1);
		return ;
	}

	int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
    if (L <= m) UpDate (lson, L, R, add);
    if (R > m)  UpDate (rson, L, R, add);
    PushUp (rt);
}

long long Query (int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }

    int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
    long long ans = 0;
    if (L <= m) ans += Query (lson, L, R);
    if (R > m) ans += Query (rson, L, R);
    return ans;
}

