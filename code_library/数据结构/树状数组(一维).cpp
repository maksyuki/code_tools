/***********************************************
************************************************
@接口: int lowbit (int x)
@时间复杂度: O (1)
@x: 树状数组的下标

@接口: int GetSum (int x)
@时间复杂度: O (logn)
@x: 查询区间(0,x)的上界位置

@接口: void UpDate (int x, int v)
@时间复杂度: O (logn)
@x: 更新区间(0,x)的上界位置
@v: 更新值
************************************************/

int bit[maxn];
//取x低位一共有多少个0
inline int lowbit (int x) {return x & (-x);}

//求前缀和
inline int GetSum (int x) {
    int res;
    for (res = 0; x; x -= lowbit (x)) res += bit[x];
    return res;
}

//单点更新
inline void UpDate (int x, int v) {
    for (; x <= n; x += lowbit (x)) bit[x] += v;
}
