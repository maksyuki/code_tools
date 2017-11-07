/***********************************************
************************************************
@�ӿ�: void PushUp (int rt)
@ʱ�临�Ӷ�: O (1)
@rt: �߶����ĸ��ڵ����

@�ӿ�: void PushDown (int rt, int l, int m, int r)
@ʱ�临�Ӷ�: O (1)
@rt: �߶����ĸ��ڵ����
@l: ��ǰ�������˵�
@m: ��ǰ������е�
@r: ��ǰ������Ҷ˵�

@�ӿ�: void Build (int rt, int l, int r)
@ʱ�临�Ӷ�: O (n)
@rt: �߶����ĸ��ڵ����
@l: ��ǰ�������˵�
@r: ��ǰ������Ҷ˵�

@�ӿ�: void UpDate (int rt, int l, int r, int L, int R, int val)
@ʱ�临�Ӷ�: O (log (n))
@rt: �߶����ĸ��ڵ����
@l: ��ǰ�������˵�
@r: ��ǰ������Ҷ˵�
@L: �����������˵�
@R: ����������Ҷ˵�
@val: ���µ�ֵ

@�ӿ�: void Query (int rt, int l, int r, int L, int R)
@ʱ�临�Ӷ�: O (log (n))
@rt: �߶����ĸ��ڵ����
@l: ��ǰ�������˵�
@r: ��ǰ������Ҷ˵�
@L: ��ѯ�������˵�
@R: ��ѯ������Ҷ˵�
************************************************/

#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r

const int maxn = 100000 + 66;
long long lazy[maxn<<2];
long long sum[maxn<<2];

void PushUp (int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown (int rt, int l, int m, int r)
{
    if (lazy[rt])
    {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        sum[rt<<1] += lazy[rt] * (m - l + 1);
        sum[rt<<1|1] += lazy[rt] * (r - m);
        lazy[rt] = 0;
    }
}

void Build (int rt, int l, int r)
{
    lazy[rt] = 0;
    if (l == r)
    {
        scanf ("%lld", &sum[rt]);
        return ;
    }

    int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
	Build (lson);
	Build (rson);
	PushUp (rt);
}

void UpDate (int rt, int l, int r, int L, int R, int add)
{
	if (L <= l && r <= R)
    {
		lazy[rt] += add;
		sum[rt] += add * (r - l + 1);
		return ;
	}

	int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
    if (L <= m) UpDate (lson, L, R, add);
    if (R > m)  UpDate (rson, L, R, add);
    PushUp (rt);
}

long long Query (int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }

    int m = (l + r) >> 1;
    PushDown (rt, l, m, r);
    long long ans = 0;
    if (L <= m) ans += Query (lson, L, R);
    if (R > m) ans += Query (rson, L, R);
    return ans;
}

