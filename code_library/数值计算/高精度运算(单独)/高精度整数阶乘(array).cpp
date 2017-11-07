/***********************************************
�߾������n!�����д𰸴�������ans��
************************************************
@�ӿ�: void GetFactorial (int n)
@ʱ�临�Ӷ�: O (n)
@n: �׳��е�n
************************************************/

int ans[maxn], len;//maxn��ʾ�׳˽�����ܵ����λ����len��ʾ�׳˵�ʵ��λ��

void GetFactorial (int n)
{
    memset (ans, 0, sizeof (ans));
    len = 1;
    ans[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 0; j < len; j++)
        {
            int temp = ans[j] * i + k;
            ans[j] = temp % 10;
            k = temp / 10;
        }

        while (k)
        {
            ans[len++] = k % 10;
            k /= 10;
        }
    }
}
