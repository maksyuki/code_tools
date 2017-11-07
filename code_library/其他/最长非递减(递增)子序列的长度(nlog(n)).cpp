/***********************************************
这种方法不能够求解出最长递增子序列，只能求出长度
************************************************
@接口: int Search (int num,int low,int high)
@功能: 二分查找
@时间复杂度: O (log(n))
@:

@接口: int LIS (int n)
@功能:
@时间复杂度: O (n * log(n))
@n: 序列的长度(下标从1开始)

@接口: int LDS (int n)
@功能:
@时间复杂度: O (n * log(n))
@n: 序列的长度(下标从1开始)
************************************************/

//分别用来存储序列和动态更新最长子序列长度
int ans[maxn], b[maxn];

//用二分查找的方法找到一个位置，使得num>b[i-1] 并且num<b[i],并用num代替b[i]
int Search (int num, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(num >= b[mid])  low = mid + 1;
        else   high = mid - 1;
    }
return low;
}

//数组的下标从1开始
int LIS (int n)
{
    int i, len, pos;
    b[1] = ans[1];
    len = 1;
    for (i = 2; i <= n; i++)
    {
        if(ans[i] >= b[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
        {
            len++;
            b[len] = ans[i];
        }

        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        {
            pos = Search (ans[i], 1, len);
            b[pos] = ans[i];
        }
    }

return len;
}

//数组的下标从1开始
int LDS (int n)
{
    int i, len, pos;
    b[1] = ans[n];
    len = 1;
    for (i = n - 1; i >= 1; i--)
    {
        if(ans[i] >= b[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
        {
            len++;
            b[len] = ans[i];
        }

        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        {
            pos = Search (ans[i], 1, len);
            b[pos] = ans[i];
        }
    }

return len;
}
