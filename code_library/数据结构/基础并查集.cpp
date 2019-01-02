/***********************************************
************************************************
@Interface: void Init()
@time: O(n)

@Interface: int UnFind(int v)
@time: O(n)
@v: vertex index 
************************************************/

void Init() {
    for(int i = 0; i < maxn; i++)
        par[i] = i;
}

int UnFind(int v) {
    if(par[v] == v) return v;
    return par[v] = UnFind(par[v]);
}
