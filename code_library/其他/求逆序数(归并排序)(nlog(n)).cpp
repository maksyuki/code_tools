/***********************************************
�������[l, r]�е��������(���Գ����ظ�Ԫ��)
************************************************
@�ӿ�: void Merge (int l, int m, int r)
@����: ����������[l, m]��[m+1, r]�ϲ�����������[l, r]
@ʱ�临�Ӷ�: O(n)
@l: �������˵�
@m: ������е�
@r: ������Ҷ˵�

@�ӿ�: void Solve (int l, int r)
@����: �ݹ��������[l, r]
@ʱ�临�Ӷ�: O (log(n))
@l: �������˵�
@r: ������Ҷ˵�
************************************************/


int ans[maxn], temp[maxn];
long long tot;

void Merge (int l, int m, int r)
{
    int i, j, k;
    for (i = l, j = m + 1, k = 0; i <= m && j <= r; )
    {
        if (ans[i] > ans[j])
        {
            tot += m - i + 1;
            temp[k++] = ans[j++];
        }

        else
            temp[k++] = ans[i++];
    }

    while (i <= m) temp[k++] = ans[i++];
    while (j <= r) temp[k++] = ans[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        ans[i] = temp[k];
}


void Solve (int l, int r)
{
    if (l < r)
    {
        int m = (l + r) >> 1;
        Solve (l, m);
        Solve (m + 1, r);
        Merge (l, m, r);
    }
}
