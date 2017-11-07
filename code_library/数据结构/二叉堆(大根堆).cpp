/***********************************************
�Դ����Ϊ��
************************************************
@�ӿ�: bool IsEmpty ()
@����: ���ص�ǰ������Ƿ�Ϊ��
@ʱ�临�Ӷ�: O (1)

@�ӿ�: int GetMax ()
@����: ���ش���ѶѶ�Ԫ��
@ʱ�临�Ӷ�: O (1)

@�ӿ�: void Insert ()
@����: ����Ԫ��
@ʱ�临�Ӷ�: O (logn)

@�ӿ�: void Del ()
@����: ɾ��Ԫ��
@ʱ�临�Ӷ�: O (logn)

@�ӿ�: void Build (int n)
@����: ���������
@ʱ�临�Ӷ�: O (nlogn)
@n: ��ʾ��������е�Ԫ�صĸ���
************************************************/

int maxheap[maxn], len;

bool IsEmpty () {return ((len - 1) == 0);}
int GetMax () {return maxheap[1];}

void Insert (int val)
{
    int tt = len, par = tt >> 1;
    maxheap[len++] = val;
    while (par && maxheap[tt] > maxheap[par])//par != 0���ж϶��Ƿ񵽴���ڵ�λ��
    {
        swap (maxheap[tt], maxheap[par]);
        tt = par;
        par = tt >> 1;
    }
}

void Del ()
{
    maxheap[1] = 0;//ɾ������
    int tt = 1;
    swap (maxheap[1], maxheap[--len]);
    while ((tt << 1) < len)
    {
        int tmp = tt << 1;
        if (maxheap[tt] > maxheap[tmp] && maxheap[tt] > maxheap[tmp+1])
            break;

        else if (maxheap[tt] > maxheap[tmp] && maxheap[tt] < maxheap[tmp+1])
            swap (maxheap[tt], maxheap[tmp+1]);

        else if (maxheap[tt] < maxheap[tmp] && maxheap[tt] > maxheap[tmp+1])
            swap (maxheap[tt], maxheap[tmp]);

        else
        {
            if (maxheap[tmp] > maxheap[tmp+1])
                swap (maxheap[tt], maxheap[tmp]);

            else
                swap (maxheap[tt], maxheap[tmp+1]);
        }
        tt <<= 1;
    }
}

void Build (int n)
{
    len = 1;
    int tt;
    memset (maxheap, 0, sizeof (maxheap));//��ʼ���Ǳ���ģ�������ΪInsert�бȽ��ϸ�������Ƚϵ�maxheap[0]
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &tt);
        Insert (tt);
    }
}
