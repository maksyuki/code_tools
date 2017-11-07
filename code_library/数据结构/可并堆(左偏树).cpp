/***********************************************
��HDU1512Ϊ��
************************************************
@�ӿ�: void Init ()
@����: ��ʼ���ѽڵ����
@ʱ�临�Ӷ�: O (n)

@�ӿ�: int Merge (int a, int b)
@����: ���Ѷ�Ԫ�ر����a��b�������Ѻϲ���һ����
@ʱ�临�Ӷ�: O (logn)
@a: һ���ѶѶ�Ԫ�صı��
@b: ��һ���ѶѶ�Ԫ�صı��

@�ӿ�: int DelRoot (int a)
@����: ɾȥ�Ѷ�Ԫ�ر����a�ĶѶ�Ԫ�أ�����ɾ��֮��õ����¶ѵĶѶ�Ԫ�ر��
@ʱ�临�Ӷ�: O (logn)
@a:�Ѷ�Ԫ�ر��

@�ӿ�: int Del (int a)
@����: ɾȥ�Ѷ�Ԫ�ر����a�Ķ���Ԫ�أ�����ɾ��֮��õ����¶ѵĶѶ�Ԫ�ر��
@ʱ�临�Ӷ�: O (logn)
@a:����Ԫ�ر��
************************************************/

//�ֱ��ʾ��ǰ�ڵ��ֵ�����ӽڵ��š��Һ��ӱ�š����ڵ��ź�NPLֵ
struct node
{
    int key, lson, rson, par, dis;
};

node tr[maxn];

//���鼯��ѯ���ڵ㲢����·��ѹ��
int UnFind (int rt)
{
    if (tr[rt].par == rt) return rt;
    else return tr[rt].par = UnFind (tr[rt].par);
}

//��ʼ������Ԫ��
void Init ()
{
    for (int i = 0; i < maxn; i++)
    {
        tr[i].key = tr[i].lson = tr[i].rson = -1;
        tr[i].par = i;
    }
}

//�ϲ������ѣ�ע���ںϲ������ѵ�ʱ��Ҫ���ж�a��b�Ƿ���ͬһ�����У�����
int Merge (int a, int b)
{
    if (a == -1) return b;
    if (b == -1) return a;
    if (tr[a].key < tr[b].key) swap (a, b);

    tr[a].rson = Merge (tr[a].rson, b);
    tr[tr[a].rson].par = a;

    if (tr[tr[a].rson].dis > tr[tr[a].lson].dis)
        swap (tr[a].rson, tr[a].lson);

    tr[a].dis = tr[tr[a].rson].dis + 1;
    return a;
}

//ɾȥ�Ѷ�Ԫ��
int DelRoot (int a)
{
    int lch = tr[a].lson, rch = tr[a].rson;
    tr[lch].par = lch, tr[rch].par = rch;
    tr[a].lson = tr[a].rson = tr[a].dis = -1;
    return Merge (lch, rch);
}

//ɾȥ���ڵ�����Ԫ��
int Del (int a)
{
    int ta = tr[a].par, lch = tr[a].lson, rch = tr[a].rson;
    tr[lch].par = lch, tr[rch].par = rch;
    tr[a].lson = tr[a].rson = tr[a].dis = -1;
    int tb = Merge (tr[a].lson, tr[a].rson);

    if (ta != -1) tr[tb].par = ta;
    else tr[tb].par = tb;

    if (ta != -1 && tr[ta].lson == a) tr[ta].lson = tb;
    if (ta != -1 && tr[ta].rson == a) tr[ta].rson = tb;

    while (ta != -1)
    {
        if (tr[tr[ta].lson].dis < tr[tr[ta].rson].dis)
            swap (tr[ta].lson, tr[ta].rson);

        if (tr[tr[ta].rson].dis + 1 == tr[ta].dis)
            break;

        tr[ta].dis = tr[tr[ta].rson].dis + 1;
        ta = tr[ta].par;
    }
    return tb;
}
