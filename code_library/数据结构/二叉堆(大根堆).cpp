/***********************************************
以大根堆为例
************************************************
@接口: bool IsEmpty ()
@功能: 返回当前大根堆是否为空
@时间复杂度: O (1)

@接口: int GetMax ()
@功能: 返回大根堆堆顶元素
@时间复杂度: O (1)

@接口: void Insert ()
@功能: 插入元素
@时间复杂度: O (logn)

@接口: void Del ()
@功能: 删除元素
@时间复杂度: O (logn)

@接口: void Build (int n)
@功能: 构建大根堆
@时间复杂度: O (nlogn)
@n: 表示待插入堆中的元素的个数
************************************************/

int maxheap[maxn], len;

bool IsEmpty () {return ((len - 1) == 0);}
int GetMax () {return maxheap[1];}

void Insert (int val)
{
    int tt = len, par = tt >> 1;
    maxheap[len++] = val;
    while (par && maxheap[tt] > maxheap[par])//par != 0是判断堆是否到达根节点位置
    {
        swap (maxheap[tt], maxheap[par]);
        tt = par;
        par = tt >> 1;
    }
}

void Del ()
{
    maxheap[1] = 0;//删除操作
    int tt = 1;
    swap (maxheap[1], maxheap[--len]);
    while ((tt << 1) < len)
    {
        int tmp = tt << 1;
        if (maxheap[tt] > maxheap[tmp] && maxheap[tt] > maxheap[tmp+1])
            break;

        else if (maxheap[tt] > maxheap[tmp] && maxheap[tt] < maxheap[tmp+1])
            swap (maxheap[tt], maxheap[tmp+1]);

        else if (maxheap[tt] < maxheap[tmp] && maxheap[tt] > maxheap[tmp+1])
            swap (maxheap[tt], maxheap[tmp]);

        else
        {
            if (maxheap[tmp] > maxheap[tmp+1])
                swap (maxheap[tt], maxheap[tmp]);

            else
                swap (maxheap[tt], maxheap[tmp+1]);
        }
        tt <<= 1;
    }
}

void Build (int n)
{
    len = 1;
    int tt;
    memset (maxheap, 0, sizeof (maxheap));//初始化是必须的，这是因为Insert中比较上浮操作会比较到maxheap[0]
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &tt);
        Insert (tt);
    }
}
