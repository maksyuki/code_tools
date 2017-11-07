/***********************************************
��BZOJ3224Ϊ��
************************************************
@�ӿ�: void Init ()
@����: ��ʼ��Treap
@ʱ�临�Ӷ�: O (1)

@�ӿ�: void UpDate (int rt)
@����: ���¸��ڵ���ӽڵ����
@ʱ�临�Ӷ�: O (1)
@rt: ��ǰ�ڵ�ı��

@�ӿ�: void lturn (int &rt)
@����: ��������
@ʱ�临�Ӷ�: O (1)
@rt: ��ǰҪ��������(��)�ڵ�

@�ӿ�: void rturn (int &rt)
@����: ��������
@ʱ�临�Ӷ�: O (1)
@rt: ��ǰҪ��������(��)�ڵ�

@�ӿ�: void Insert (int &rt, int x)
@����: ��ֵΪx�Ľڵ���뵽Treap��
@ʱ�临�Ӷ�: O(logn)
@rt: ��ǰ�ĸ��ڵ�
@x: �����뵽Treap�еĽڵ��ֵ

@�ӿ�: void Del (int &rt, int x)
@����: ɾ��ֵΪx�Ľڵ�
@ʱ�临�Ӷ�: O (logn)
@rt: ��ǰ�ĸ��ڵ�
@x: ��ɾ���Ľڵ��ֵ

�ӿ�: int QueryRank (int rt, int x)
@����: ��ѯ��ǰֵΪx�Ľڵ��rank
@ʱ�临�Ӷ�: O (logn)
@rt: ��ǰ�ĸ��ڵ�
@x: ����ѯ�Ľڵ��ֵ

�ӿ�: int QueryNum (int rt, int x)
@����: ��ѯ��x��Ľڵ��ֵ
@ʱ�临�Ӷ�: O (logn)
@rt: ��ǰ�ĸ��ڵ�
@x: ����ѯ�Ľڵ��rank

�ӿ�: void QueryPro (int rt, int x)
@����: ��ѯֵΪx�Ľڵ�����ǰ�̽ڵ�
@ʱ�临�Ӷ�: O (logn)
@rt: ��ǰ�ĸ��ڵ�
@x: ����ѯ�Ľڵ��ֵ

�ӿ�: void QuerySub (int rt, int x)
@����: ��ѯֵΪx�Ľڵ�������̽ڵ�
@ʱ�临�Ӷ�: O (logn)
@rt: ��ǰ�ĸ��ڵ�
@x: ����ѯ�Ľڵ��ֵ
************************************************/

struct node
{
	int l, r, v, size, rnd, w;
}tr[maxn];

//�ֱ��ʾ�ڵ�ĸ�������ű��������ڵ�����յĽ��
int n, size, root, res;

void Init ()
{
    root = size = 0;
    memset (tr, 0, sizeof (tr));
}

void UpDate (int rt)//���½����Ϣ
{
	tr[rt].size = tr[tr[rt].l].size + tr[tr[rt].r].size + tr[rt].w;
}

void lturn (int &rt)
{
	int tt = tr[rt].r; tr[rt].r = tr[tt].l; tr[tt].l = rt;
	tr[tt].size = tr[rt].size; UpDate(rt); rt = tt;
}

void rturn (int &rt)
{
	int tt = tr[rt].l; tr[rt].l = tr[tt].r; tr[tt].r = rt;
	tr[tt].size = tr[rt].size; UpDate(rt); rt = tt;
}

void Insert (int &rt, int x)
{
	if (rt == 0)
	{
		rt = ++size;
		tr[rt].size = tr[rt].w = 1; tr[rt].v = x; tr[rt].rnd = rand();
		return ;
	}

	tr[rt].size++;
    if (tr[rt].v == x) tr[rt].w++;//ÿ�����˳���¼����ýڵ���ֵͬ�����ĸ���

	else if (x > tr[rt].v)
	{
		Insert (tr[rt].r, x);
		if (tr[tr[rt].r].rnd < tr[rt].rnd) lturn (rt);//ά��������
	}

	else
	{
		Insert (tr[rt].l, x);
		if (tr[tr[rt].l].rnd < tr[rt].rnd) rturn (rt);
	}
}

void Del (int &rt, int x)
{
    if (rt == 0) return ;

	if (tr[rt].v == x)
	{
		if (tr[rt].w > 1)
		{
			tr[rt].w--; tr[rt].size--; return ;//����ֹ��ֵͬ�ĸ����ж����ɾȥһ��
		}

		if (tr[rt].l * tr[rt].r == 0) rt = tr[rt].l + tr[rt].r;//��һ������Ϊ��

		else if (tr[tr[rt].l].rnd < tr[tr[rt].r].rnd)
			rturn (rt), Del (rt, x);

		else lturn (rt), Del (rt, x);
	}

	else if (x > tr[rt].v)
		tr[rt].size--, Del (tr[rt].r, x);

	else tr[rt].size--, Del (tr[rt].l, x);
}

int QueryRank (int rt, int x)
{
    if (rt == 0) return 0;

	if (tr[rt].v == x) return tr[tr[rt].l].size + 1;

	else if (x > tr[rt].v)
		return tr[tr[rt].l].size + tr[rt].w + QueryRank (tr[rt].r, x);

	else return QueryRank (tr[rt].l, x);
}

int QueryNum (int rt, int x)
{
    if (rt == 0) return 0;

	if (x <= tr[tr[rt].l].size)
		return QueryNum (tr[rt].l, x);

    else if (x > tr[tr[rt].l].size + tr[rt].w)
		return QueryNum (tr[rt].r, x - tr[tr[rt].l].size - tr[rt].w);

    else return tr[rt].v;
}

//���յĽ��ʹ��res��������
void QueryPro (int rt, int x)
{
    if (rt == 0) return ;

    if (tr[rt].v < x)
	{
		res = rt; QueryPro (tr[rt].r, x);
	}

    else QueryPro (tr[rt].l, x);
}

//���յĽ��ʹ��res��������
void QuerySub (int rt, int x)
{
	if (rt == 0) return ;

	if (tr[rt].v > x)
	{
		res = rt; QuerySub (tr[rt].l, x);
	}

	else QuerySub (tr[rt].r, x);
}
