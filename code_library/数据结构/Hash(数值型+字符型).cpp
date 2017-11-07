/***********************************************
��ֵ�ͺ��ַ���hash(�����������������ͻ)
************************************************
@�ӿ�: long long NumHash (long long val)
@����: ��һ������ӳ�䵽һ����ַ(�߱������±�)
@ʱ�临�Ӷ�: o (1)
@val: ��ӳ�������

�ӿ�: long long BKDRHash (char *val)
@����: ��һ���ַ���ӳ�䵽һ����ַ(�߱������±�)
@ʱ�临�Ӷ�: O (1)
@val: ��ӳ����ַ���

�ӿ�: void AddEdge (long long val)
@����: ��ɢ�б������Ԫ��val
@ʱ�临�Ӷ�: O (k)
@val: ����ӵ���ֵ��Ԫ�ػ������ַ���Ԫ��

�ӿ�: long long Find (long long val)
@����: ��ɢ�б��в���Ԫ��val
@ʱ�临�Ӷ�: o (k)
@val: �����ҵ���ֵ��Ԫ�ػ������ַ���Ԫ��
************************************************/

const int maxn = 3999972;

//����Hash��ͷ�ͱ߱���������
struct Node
{
    long long v, nxt, num; //���԰�����Ŀ�Ĳ�ͬ���ı�
};

Node edge[maxn];//�߱�
long long head[maxn];//ͷ��
long long tot;//����Ĳ�ͬ��Ԫ�صĸ���

//��ֵ��hash��ʹ��ֱ��ģ�ϴ�������hash����
long long NumHash (long long val)
{
    return (val + 3899971) % 3999971;
}

//�ַ���hash
long long BKDRHash (char *val)
{
	long long sed = 131, hashval = 0;
	while (*val) hashval = hashval * sed + (*val++);
	return hashval % maxn;
}

void Init ()
{
    tot = 0;
    memset (head, -1, sizeof (head));
    for (long long i = 0; i < maxn; i++)
        edge[i].nxt = -1;
}

//��Hash����������ݣ���������ֵ�͵ģ�Ҳ�������ַ��͵ģ���������ֵ��Ϊ����
//�ڵ���AddEdge֮ǰһ��Ҫ�ȵ��ó�ʼ��Init����������������
void AddEdge (long long val)
{
    long long key = NumHash (val);//��ֵ��hash��Ҳ����ʹ���ַ���hash
    for (long long i = head[key]; i != -1; i = edge[i].nxt)
        if (edge[i].v == val)
        {
            edge[i].num++;//���԰�����Ŀ�Ĳ�ͬ���ı�
            return ;
        }

    edge[tot].v = val;
    edge[tot].num = 1; //���԰�����Ŀ�Ĳ�ͬ���ı�
    edge[tot].nxt = head[key];
    head[key] = tot++;
}

//��ѯ����val�Ƿ���hash����,��������ֵ�͵ģ�Ҳ�������ַ��͵ģ���������ֵ��Ϊ����
//������򷵻س��ֵĴ���(�������)�����򷵻�-1
long long Find (long long val)
{
    long long key = NumHash (val);//ͬ��
    for (long long i = head[key]; i != -1; i = edge[i].nxt)
        if (edge[i].v == val)
            return edge[i].num;//���԰�����Ŀ�Ĳ�ͬ���ı�
	return -1;
}
