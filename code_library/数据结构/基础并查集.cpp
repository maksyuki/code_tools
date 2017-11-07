/***********************************************
************************************************
@�ӿ�: vod Init ()
@ʱ�临�Ӷ�: O (n)

@�ӿ�: int UnFind (int val)
@ʱ�临�Ӷ�: O (n)
@val: �ڵ�����
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
