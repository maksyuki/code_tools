/***********************************************
求解区间[l, r]中的逆序对数(可以出现重复元素)
************************************************
@接口: void Merge (int l, int m, int r)
@功能: 将有序区间[l, m]和[m+1, r]合并成有序区间[l, r]
@时间复杂度: O(n)
@l: 区间的左端点
@m: 区间的中点
@r: 区间的右端点

@接口: void Solve (int l, int r)
@功能: 递归二分区间[l, r]
@时间复杂度: O (log(n))
@l: 区间的左端点
@r: 区间的右端点
************************************************/


int ans[maxn], temp[maxn];
long long tot;

void Merge (int l, int m, int r)
{
    int i, j, k;
    for (i = l, j = m + 1, k = 0; i <= m && j <= r; )
    {
        if (ans[i] > ans[j])
        {
            tot += m - i + 1;
            temp[k++] = ans[j++];
        }

        else
            temp[k++] = ans[i++];
    }

    while (i <= m) temp[k++] = ans[i++];
    while (j <= r) temp[k++] = ans[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        ans[i] = temp[k];
}


void Solve (int l, int r)
{
    if (l < r)
    {
        int m = (l + r) >> 1;
        Solve (l, m);
        Solve (m + 1, r);
        Merge (l, m, r);
    }
}
