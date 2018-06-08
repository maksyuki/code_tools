/***********************************************
************************************************
@�ӿ�: vod Init ()
@ʱ�临�Ӷ�: O (n)

@�ӿ�: int UnFind (int val)
@ʱ�临�Ӷ�: O (n)
@val: �ڵ�����
************************************************/

void Init() {
    for(int i = 0; i < maxn; i++)
        par[i] = i;
}


int UnFind(int v) {
    if(par[v] == v) return v;
    return par[v] = UnFind(par[v]);
}
