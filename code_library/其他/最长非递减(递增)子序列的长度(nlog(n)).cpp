/***********************************************
���ַ������ܹ���������������У�ֻ���������
************************************************
@�ӿ�: int Search (int num,int low,int high)
@����: ���ֲ���
@ʱ�临�Ӷ�: O (log(n))
@:

@�ӿ�: int LIS (int n)
@����:
@ʱ�临�Ӷ�: O (n * log(n))
@n: ���еĳ���(�±��1��ʼ)

@�ӿ�: int LDS (int n)
@����:
@ʱ�临�Ӷ�: O (n * log(n))
@n: ���еĳ���(�±��1��ʼ)
************************************************/

//�ֱ������洢���кͶ�̬����������г���
int ans[maxn], b[maxn];

//�ö��ֲ��ҵķ����ҵ�һ��λ�ã�ʹ��num>b[i-1] ����num<b[i],����num����b[i]
int Search (int num, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(num >= b[mid])  low = mid + 1;
        else   high = mid - 1;
    }
return low;
}

//������±��1��ʼ
int LIS (int n)
{
    int i, len, pos;
    b[1] = ans[1];
    len = 1;
    for (i = 2; i <= n; i++)
    {
        if(ans[i] >= b[len])//���a[i]��b[]��������󻹴�ֱ�Ӳ��뵽���漴��
        {
            len++;
            b[len] = ans[i];
        }

        else//�ö��ֵķ�����b[]�������ҳ���һ����a[i]���λ�ò�����a[i]������λ��
        {
            pos = Search (ans[i], 1, len);
            b[pos] = ans[i];
        }
    }

return len;
}

//������±��1��ʼ
int LDS (int n)
{
    int i, len, pos;
    b[1] = ans[n];
    len = 1;
    for (i = n - 1; i >= 1; i--)
    {
        if(ans[i] >= b[len])//���a[i]��b[]��������󻹴�ֱ�Ӳ��뵽���漴��
        {
            len++;
            b[len] = ans[i];
        }

        else//�ö��ֵķ�����b[]�������ҳ���һ����a[i]���λ�ò�����a[i]������λ��
        {
            pos = Search (ans[i], 1, len);
            b[pos] = ans[i];
        }
    }

return len;
}
