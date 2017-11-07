/***********************************************
高精度求解n!，其中答案存在数组ans中
************************************************
@接口: void GetFactorial (int n)
@时间复杂度: O (n)
@n: 阶乘中的n
************************************************/

int ans[maxn], len;//maxn表示阶乘结果可能的最大位数，len表示阶乘的实际位数

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
