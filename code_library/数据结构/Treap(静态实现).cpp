/***********************************************
以BZOJ3224为例
************************************************
@接口: void Init ()
@功能: 初始化Treap
@时间复杂度: O (1)

@接口: void UpDate (int rt)
@功能: 更新根节点的子节点个数
@时间复杂度: O (1)
@rt: 当前节点的标号

@接口: void lturn (int &rt)
@功能: 左旋操作
@时间复杂度: O (1)
@rt: 当前要被调整的(根)节点

@接口: void rturn (int &rt)
@功能: 右旋操作
@时间复杂度: O (1)
@rt: 当前要被调整的(根)节点

@接口: void Insert (int &rt, int x)
@功能: 将值为x的节点插入到Treap中
@时间复杂度: O(logn)
@rt: 当前的根节点
@x: 待插入到Treap中的节点的值

@接口: void Del (int &rt, int x)
@功能: 删除值为x的节点
@时间复杂度: O (logn)
@rt: 当前的根节点
@x: 待删除的节点的值

接口: int QueryRank (int rt, int x)
@功能: 查询当前值为x的节点的rank
@时间复杂度: O (logn)
@rt: 当前的根节点
@x: 待查询的节点的值

接口: int QueryNum (int rt, int x)
@功能: 查询第x大的节点的值
@时间复杂度: O (logn)
@rt: 当前的根节点
@x: 待查询的节点的rank

接口: void QueryPro (int rt, int x)
@功能: 查询值为x的节点的最近前继节点
@时间复杂度: O (logn)
@rt: 当前的根节点
@x: 待查询的节点的值

接口: void QuerySub (int rt, int x)
@功能: 查询值为x的节点的最近后继节点
@时间复杂度: O (logn)
@rt: 当前的根节点
@x: 待查询的节点的值
************************************************/

struct node
{
	int l, r, v, size, rnd, w;
}tr[maxn];

//分别表示节点的个数、标号变量、根节点和最终的结果
int n, size, root, res;

void Init ()
{
    root = size = 0;
    memset (tr, 0, sizeof (tr));
}

void UpDate (int rt)//更新结点信息
{
	tr[rt].size = tr[tr[rt].l].size + tr[tr[rt].r].size + tr[rt].w;
}

void lturn (int &rt)
{
	int tt = tr[rt].r; tr[rt].r = tr[tt].l; tr[tt].l = rt;
	tr[tt].size = tr[rt].size; UpDate(rt); rt = tt;
}

void rturn (int &rt)
{
	int tt = tr[rt].l; tr[rt].l = tr[tt].r; tr[tt].r = rt;
	tr[tt].size = tr[rt].size; UpDate(rt); rt = tt;
}

void Insert (int &rt, int x)
{
	if (rt == 0)
	{
		rt = ++size;
		tr[rt].size = tr[rt].w = 1; tr[rt].v = x; tr[rt].rnd = rand();
		return ;
	}

	tr[rt].size++;
    if (tr[rt].v == x) tr[rt].w++;//每个结点顺便记录下与该节点相同值的数的个数

	else if (x > tr[rt].v)
	{
		Insert (tr[rt].r, x);
		if (tr[tr[rt].r].rnd < tr[rt].rnd) lturn (rt);//维护堆性质
	}

	else
	{
		Insert (tr[rt].l, x);
		if (tr[tr[rt].l].rnd < tr[rt].rnd) rturn (rt);
	}
}

void Del (int &rt, int x)
{
    if (rt == 0) return ;

	if (tr[rt].v == x)
	{
		if (tr[rt].w > 1)
		{
			tr[rt].w--; tr[rt].size--; return ;//若不止相同值的个数有多个，删去一个
		}

		if (tr[rt].l * tr[rt].r == 0) rt = tr[rt].l + tr[rt].r;//有一个儿子为空

		else if (tr[tr[rt].l].rnd < tr[tr[rt].r].rnd)
			rturn (rt), Del (rt, x);

		else lturn (rt), Del (rt, x);
	}

	else if (x > tr[rt].v)
		tr[rt].size--, Del (tr[rt].r, x);

	else tr[rt].size--, Del (tr[rt].l, x);
}

int QueryRank (int rt, int x)
{
    if (rt == 0) return 0;

	if (tr[rt].v == x) return tr[tr[rt].l].size + 1;

	else if (x > tr[rt].v)
		return tr[tr[rt].l].size + tr[rt].w + QueryRank (tr[rt].r, x);

	else return QueryRank (tr[rt].l, x);
}

int QueryNum (int rt, int x)
{
    if (rt == 0) return 0;

	if (x <= tr[tr[rt].l].size)
		return QueryNum (tr[rt].l, x);

    else if (x > tr[tr[rt].l].size + tr[rt].w)
		return QueryNum (tr[rt].r, x - tr[tr[rt].l].size - tr[rt].w);

    else return tr[rt].v;
}

//最终的结果使用res变量返回
void QueryPro (int rt, int x)
{
    if (rt == 0) return ;

    if (tr[rt].v < x)
	{
		res = rt; QueryPro (tr[rt].r, x);
	}

    else QueryPro (tr[rt].l, x);
}

//最终的结果使用res变量返回
void QuerySub (int rt, int x)
{
	if (rt == 0) return ;

	if (tr[rt].v > x)
	{
		res = rt; QuerySub (tr[rt].l, x);
	}

	else QuerySub (tr[rt].r, x);
}
