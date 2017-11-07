/***********************************************
************************************************
@接口: vod Init ()
@时间复杂度: O (n)

@接口: int UnFind (int val)
@时间复杂度: O (n)
@val: 节点的序号
************************************************/

void Init ()
{
    for (int i = 0; i < maxn; i++)
        parent[i] = i;
}


int UnFind (int val)
{
    if (parent[val] == val) return val;
    return parent[val] = UnFind (parent[val]);
}
