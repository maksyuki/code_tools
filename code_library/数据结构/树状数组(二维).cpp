/***********************************************
************************************************
@�ӿ�: int lowbit (int val)
@ʱ�临�Ӷ�: O (1)
@val: ��״������±�

@�ӿ�: void UpDate (int x, int y, int val)
@ʱ�临�Ӷ�: O (logn * logm)
@x: ���µ�ĺ�����
@y: ���µ��������
@val: ����ֵ

@�ӿ�: int Query (int x, int y)
@ʱ�临�Ӷ�: O (logn * logm)
@x: ��ѯ����(1,1)-(x, y)�ĺ�����
@y: ��ѯ����(1,1)-(x, y)��������
************************************************/
int c[maxn][maxn], n;

int lowbit (int val)
{
    return val & (-val);
}


void UpDate (int x, int y, int val)
{
    while (x <= n)
    {
        int temp = y;
        while (temp <= n)
        {
            c[x][temp] += val;
            temp += lowbit (temp);
        }
        x += lowbit (x);
    }
}

int Query (int x, int y)
{
    int sum = 0;
    while (x > 0)
    {
        int temp = y;
        while (temp > 0)
        {
            sum += c[x][temp];
            temp -= lowbit (temp);
        }
        x -= lowbit (x);
    }

return sum;
}
