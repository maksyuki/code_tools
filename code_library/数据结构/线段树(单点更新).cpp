/***********************************************
************************************************
@�ӿ�: void PushUp (int rt)
@ʱ�临�Ӷ�: O (1)
@rt: �߶����ĸ��ڵ����

@�ӿ�: void Build (int rt, int l, int r)
@ʱ�临�Ӷ�: O (n)
@rt: �߶����ĸ��ڵ����
@l: ��ǰ�������˵�
@r: ��ǰ������Ҷ˵�

@�ӿ�: void UpDate (int rt, int l, int r, int val, int num)
@ʱ�临�Ӷ�: O (log (n))
@rt: �߶����ĸ��ڵ����
@l: ��ǰ�������˵�
@r: ��ǰ������Ҷ˵�
@val: ���µ�λ��
@num: ���µ�ֵ

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

const int maxn = 55555;
int sum[maxn<<2];

void PushUp (int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void Build (int rt, int l, int r)
{
	if (l == r)
    {
		scanf("%d", &sum[rt]);
		return ;
	}

	int m = (l + r) >> 1;
	Build (lson);
	Build (rson);
	PushUp (rt);
}

void UpDate (int rt, int l, int r, int p, int add)
{
	if (l == r)
    {
		sum[rt] += add;
		return ;
	}

	int m = (l + r) >> 1;
	if (p <= m) UpDate (lson, p, add);
	else UpDate (rson, p, add);
	PushUp (rt);
}

int Query (int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return sum[rt];

	int m = (l + r) >> 1, ans = 0;
	if (L <= m) ans += Query (lson, L, R);
	if (R > m)  ans += Query (rson, L, R);
	return ans;
}

