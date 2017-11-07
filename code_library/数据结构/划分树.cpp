/***********************************************
以POJ2104为例
************************************************
@接口: void build (int dep, int l,int r)
@功能: 根据读入的数据建立划分树
@时间复杂度: O (nlogn)		
@dep: 当前划分的深度
@l: 当前划分区间的左端点
@r: 当前划分区间的右端点

@接口: int query (int dep, int L, int R, int l, int r, int k)
@功能: 查询[l,r]区间内第k大的值
@时间复杂度: O (logn)		
@dep: 当前划分的深度
@L: 当前区间的左端点
@R: 当前区间的右端点
@l: 当前划分区间的左端点
@r: 当前划分区间的右端点
@k: 查询的第k大
************************************************/

//注意若要多次创建划分树，则需要对下面的数组初始化(全初始化为0)！！！
int tree[30][maxn];//表示每层每个位置的值
int sorted[maxn];//已经排序的数
int toleft[30][maxn];//toleft[p][i]表示第i层从1到i有多少个数分入左边

void build (int dep, int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    int same = mid - l + 1;//表示等于中间值而且被分入左边的个数
    for (int i = l; i <= r; i++)
      if (tree[dep][i] < sorted[mid])
         same--;

    int lpos = l, rpos = mid + 1;
    for (int i = l; i <= r; i++)
    {
        if (tree[dep][i] < sorted[mid])//比中间的数小，分入左边
             tree[dep+1][lpos++] = tree[dep][i];
        else if (tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep+1][lpos++] = tree[dep][i];
            same--;
        }
        else  //比中间值大分入右边
            tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1] + lpos - l;//从1到i放左边的个数
    }
    build (dep + 1, l, mid);
    build (dep + 1, mid + 1, r);
}

//查询区间第k大的数，[L,R]是大区间，[l,r]是要查询的小区间
int query (int dep, int L, int R, int l, int r, int k)
{
    if (l == r) return tree[dep][l];
    int mid = (L + R) >> 1;
    int cnt = toleft[dep][r] - toleft[dep][l-1];//[l,r]中位于左边的个数
    if (cnt >= k)
    {
        //L+要查询的区间前被放在左边的个数
        int newl = L + toleft[dep][l-1] - toleft[dep][L-1];
        //左端点加上查询区间会被放在左边的个数
        int newr = newl + cnt - 1;
        return query (dep + 1, L, mid, newl, newr, k);
    }
    else
    {
         int newr = r + toleft[dep][R] - toleft[dep][r];
         int newl = newr - (r - l - cnt);
         return query (dep + 1, mid + 1, R, newl, newr, k - cnt);
    }
}

int main()
{
    //CFF;
    //CPPFF;
	int n, q;
	while (scanf ("%d%d", &n, &q) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf ("%d", &tree[0][i]);
			sorted[i] = tree[0][i];
		}
		sort (sorted + 1, sorted + 1 + n);
		build (0, 1, n);
		
		for (int i = 1; i <= q; i++)
		{
			int ll, rr, kk;
			scanf ("%d%d%d", &ll, &rr, &kk);
			printf ("%d\n", query (0, 1, n, ll, rr, kk));
		}
	}
    return 0;
}
