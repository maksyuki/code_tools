/***********************************************
以HDU1512为例
************************************************
@接口: void Init ()
@功能: 初始化堆节点变量
@时间复杂度: O (n)

@接口: int Merge (int a, int b)
@功能: 将堆顶元素编号是a和b的两个堆合并成一个堆
@时间复杂度: O (logn)
@a: 一个堆堆顶元素的标号
@b: 另一个堆堆顶元素的标号

@接口: int DelRoot (int a)
@功能: 删去堆顶元素标号是a的堆顶元素，返回删除之后得到的新堆的堆顶元素标号
@时间复杂度: O (logn)
@a:堆顶元素标号

@接口: int Del (int a)
@功能: 删去堆顶元素标号是a的堆内元素，返回删除之后得到的新堆的堆顶元素标号
@时间复杂度: O (logn)
@a:堆中元素标号
************************************************/

//分别表示当前节点的值、左孩子节点标号、右孩子标号、父节点标号和NPL值
struct node
{
    int key, lson, rson, par, dis;
};

node tr[maxn];

//并查集查询根节点并进行路径压缩
int UnFind (int rt)
{
    if (tr[rt].par == rt) return rt;
    else return tr[rt].par = UnFind (tr[rt].par);
}

//初始化堆内元素
void Init ()
{
    for (int i = 0; i < maxn; i++)
    {
        tr[i].key = tr[i].lson = tr[i].rson = -1;
        tr[i].par = i;
    }
}

//合并两个堆，注意在合并两个堆的时候要先判断a和b是否在同一个堆中！！！
int Merge (int a, int b)
{
    if (a == -1) return b;
    if (b == -1) return a;
    if (tr[a].key < tr[b].key) swap (a, b);

    tr[a].rson = Merge (tr[a].rson, b);
    tr[tr[a].rson].par = a;

    if (tr[tr[a].rson].dis > tr[tr[a].lson].dis)
        swap (tr[a].rson, tr[a].lson);

    tr[a].dis = tr[tr[a].rson].dis + 1;
    return a;
}

//删去堆顶元素
int DelRoot (int a)
{
    int lch = tr[a].lson, rch = tr[a].rson;
    tr[lch].par = lch, tr[rch].par = rch;
    tr[a].lson = tr[a].rson = tr[a].dis = -1;
    return Merge (lch, rch);
}

//删去堆内的任意元素
int Del (int a)
{
    int ta = tr[a].par, lch = tr[a].lson, rch = tr[a].rson;
    tr[lch].par = lch, tr[rch].par = rch;
    tr[a].lson = tr[a].rson = tr[a].dis = -1;
    int tb = Merge (tr[a].lson, tr[a].rson);

    if (ta != -1) tr[tb].par = ta;
    else tr[tb].par = tb;

    if (ta != -1 && tr[ta].lson == a) tr[ta].lson = tb;
    if (ta != -1 && tr[ta].rson == a) tr[ta].rson = tb;

    while (ta != -1)
    {
        if (tr[tr[ta].lson].dis < tr[tr[ta].rson].dis)
            swap (tr[ta].lson, tr[ta].rson);

        if (tr[tr[ta].rson].dis + 1 == tr[ta].dis)
            break;

        tr[ta].dis = tr[tr[ta].rson].dis + 1;
        ta = tr[ta].par;
    }
    return tb;
}
