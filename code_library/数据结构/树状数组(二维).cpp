/***********************************************
************************************************
@接口: int lowbit (int val)
@时间复杂度: O (1)
@val: 树状数组的下标

@接口: void UpDate (int x, int y, int val)
@时间复杂度: O (logn * logm)
@x: 更新点的横坐标
@y: 更新点的纵坐标
@val: 更新值

@接口: int Query (int x, int y)
@时间复杂度: O (logn * logm)
@x: 查询区间(1,1)-(x, y)的横坐标
@y: 查询区间(1,1)-(x, y)的纵坐标
************************************************/
int c[maxn][maxn], n;

int lowbit (int val)
{
    return val & (-val);
}


void UpDate (int x, int y, int val)
{
    while (x <= n)
    {
        int temp = y;
        while (temp <= n)
        {
            c[x][temp] += val;
            temp += lowbit (temp);
        }
        x += lowbit (x);
    }
}

int Query (int x, int y)
{
    int sum = 0;
    while (x > 0)
    {
        int temp = y;
        while (temp > 0)
        {
            sum += c[x][temp];
            temp -= lowbit (temp);
        }
        x -= lowbit (x);
    }

return sum;
}
