/***********************************************
数值型和字符型hash(可用于拉链法解决冲突)
************************************************
@接口: long long NumHash (long long val)
@功能: 将一个数字映射到一个地址(边表数组下标)
@时间复杂度: o (1)
@val: 待映射的数字

接口: long long BKDRHash (char *val)
@功能: 将一个字符串映射到一个地址(边表数组下标)
@时间复杂度: O (1)
@val: 待映射的字符串

接口: void AddEdge (long long val)
@功能: 向散列表中添加元素val
@时间复杂度: O (k)
@val: 待添加的数值型元素或者是字符型元素

接口: long long Find (long long val)
@功能: 在散列表中查找元素val
@时间复杂度: o (k)
@val: 待查找的数值型元素或者是字符型元素
************************************************/

const int maxn = 3999972;

//定义Hash表头和边表数据类型
struct Node
{
    long long v, nxt, num; //可以按照题目的不同而改变
};

Node edge[maxn];//边表
long long head[maxn];//头表
long long tot;//插入的不同种元素的个数

//数值型hash，使用直接模上大素数的hash函数
long long NumHash (long long val)
{
    return (val + 3899971) % 3999971;
}

//字符型hash
long long BKDRHash (char *val)
{
	long long sed = 131, hashval = 0;
	while (*val) hashval = hashval * sed + (*val++);
	return hashval % maxn;
}

void Init ()
{
    tot = 0;
    memset (head, -1, sizeof (head));
    for (long long i = 0; i < maxn; i++)
        edge[i].nxt = -1;
}

//向Hash表中添加数据，可以是数值型的，也可以是字符型的，这里以数值型为例。
//在调用AddEdge之前一定要先调用初始化Init函数！！！！！！
void AddEdge (long long val)
{
    long long key = NumHash (val);//数值型hash，也可以使用字符型hash
    for (long long i = head[key]; i != -1; i = edge[i].nxt)
        if (edge[i].v == val)
        {
            edge[i].num++;//可以按照题目的不同而改变
            return ;
        }

    edge[tot].v = val;
    edge[tot].num = 1; //可以按照题目的不同而改变
    edge[tot].nxt = head[key];
    head[key] = tot++;
}

//查询数据val是否在hash表中,可以是数值型的，也可以是字符型的，这里以数值型为例。
//如果在则返回出现的次数(因题而异)，否则返回-1
long long Find (long long val)
{
    long long key = NumHash (val);//同上
    for (long long i = head[key]; i != -1; i = edge[i].nxt)
        if (edge[i].v == val)
            return edge[i].num;//可以按照题目的不同而改变
	return -1;
}
