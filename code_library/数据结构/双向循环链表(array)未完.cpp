

int Left[maxn], Right[maxn], val[maxn];

void Build (int n)//建立下标从1~n的双向循环链表
{
    for (int i = 2; i <= n; i++)
    {
        Left[i] = i - 1;
        if (i == n - 1)
            Right[i] = n;

        else
            Right[i] = (i + 1) % n;
    }

    Left[1] = n;
    Right[1] = 2;
}

int Find (int p, int k)//查找从下标p开始的第k个元素的下标
{
    int cnt = 0;
    while (cnt < k - 1)
    {
        p = Right[p];
        cnt++;
    }

return p;
}

void Link (int L, int R)
{
    Left[R] = L;
    Right[L] = R;
}
