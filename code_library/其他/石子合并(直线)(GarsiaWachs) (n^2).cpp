/***********************************************
************************************************
@�ӿ�: void Combine (int k)
@����:
@ʱ�临�Ӷ�:
@k:

@�ӿ�: void Solve ()
@����:
@ʱ�临�Ӷ�: O (n ^ 2)
@:
************************************************/

int stone[maxn];//��ʾ���ϲ���ʯ�Ӷ�
int n, t, ans;//�ֱ��ʾ���ϲ���ʯ�Ӷ������м�����ʹ�

void Combine (int k)
{
    int temp = stone[k] + stone[k-1];
    ans += temp;
    for (int i = k; i < t - 1; i++)//��֮�������ǰ��ֵ
        stone[i] = stone[i+1];
    t--;

    int j = 0;
    for(j = k - 1; j > 0 && stone[j-1] < temp; j--)//��k-1��ʼ��ǰ�ҵ�һ����temp�������û�ҵ������ֵ
        stone[j] = stone[j-1];
    stone[j] = temp;                    //�ҵ���temp��ֵ���±�j��λ��

    while (j >= 2 && stone[j] >= stone[j-2])//���j >= 2��������ݹ������ȥ
    {
        int d = t - j;//
        Combine (j - 1);
        j = t - d;
    }
}

void Solve ()
{
    t = 1, ans = 0;
    for (int i = 1; i < n; i++)
    {
        stone[t++] = stone[i];
        while (t >= 3 && stone[t-3] <= stone[t-1])
            Combine (t - 2);
    }
    while (t > 1) Combine (t - 1);
}
