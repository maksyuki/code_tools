/***********************************************
************************************************
@接口: void Combine (int k)
@功能:
@时间复杂度:
@k:

@接口: void Solve ()
@功能:
@时间复杂度: O (n ^ 2)
@:
************************************************/

int stone[maxn];//表示待合并的石子堆
int n, t, ans;//分别表示待合并的石子堆数、中间变量和答案

void Combine (int k)
{
    int temp = stone[k] + stone[k-1];
    ans += temp;
    for (int i = k; i < t - 1; i++)//将之后的数向前赋值
        stone[i] = stone[i+1];
    t--;

    int j = 0;
    for(j = k - 1; j > 0 && stone[j-1] < temp; j--)//从k-1开始向前找第一个比temp大的数，没找到则向后赋值
        stone[j] = stone[j-1];
    stone[j] = temp;                    //找到则将temp赋值到下标j的位置

    while (j >= 2 && stone[j] >= stone[j-2])//如果j >= 2，则继续递归求解下去
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
