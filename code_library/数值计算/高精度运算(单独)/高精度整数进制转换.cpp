/***********************************************
求解M进制到N进制的高精度转换
************************************************
@接口: int GetNum (char c)
@功能: 将字符转化成数字
@时间复杂度: O (1)
@c: 待转换成数字的字符

@接口: char GetChar (int val)
@功能: 将数字转换成字符
@时间复杂度: O (1)
@val: 待转换成字符的数字

@接口: void Change ()
@功能: 将输入的字符串的各个数位还原为数字形式
@时间复杂度: O (n)

@接口: void Solve ()
@功能: 处理主函数
@时间复杂度: O (n ^ 2)

@接口: void Output ()
@功能: 按照相应进制输出结果
@时间复杂度: O (n)
************************************************/

const int maxn = 100000 + 66;

char str[maxn];//输入字符串
int start[maxn], ans[maxn], res[maxn];//被除数，商，余数
int oldBase, newBase;//转换前后的进制


int GetNum (char c)//这里进制字符是先数字，后大写字母，后小写字母的
{
    if(c >= '0' && c <= '9') return c - '0';//数字
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;//大写字母
    return c - 'a' + 36;//小写字母
}


char GetChar (int i)//数字得到字符
{
    if (i >= 0 && i <= 9) return i + '0';
    if (i >= 10 && i <= 35) return i - 10 + 'A';
    return i - 36 + 'a';
}

void Change ()//把输入的字符串的各个数位还原为数字形式
{
    int i;
    start[0] = strlen (str);//数组的0位存的是数组长度
    for(i = 1; i <= start[0]; i++)
        start[i] = GetNum (str[i-1]);
}

void Solve ()
{
    memset (res, 0, sizeof (res));//余数初始化为空
    int y, i, j;
    //模n取余法，(总体规律是先余为低位，后余为高位)
    while (start[0] >= 1)
    {//只要被除数仍然大于等于1，那就继续“模2取余”
        y = 0;
        i = 1;
        ans[0] = start[0];
        //
        while (i <= start[0])
        {
            y = y * oldBase + start[i];
            ans[i++] = y / newBase;
            y %= newBase;
        }
        res[++res[0]] = y;//这一轮运算得到的余数
        i = 1;
        //找到下一轮商的起始处
        while ((i <= ans[0]) && (ans[i] == 0)) i++;
        //清除这一轮使用的被除数
        memset (start, 0, sizeof(start));
        //本轮得到的商变为下一轮的被除数
        for(j = i;j <= ans[0]; j++)
            start[++start[0]] = ans[j];
        memset (ans, 0, sizeof(ans)); //清除这一轮的商，为下一轮运算做准备
    }
}

void Output ()//从高位到低位逆序输出
{
    int i;
    for (i = res[0]; i >= 1; i--)
        printf ("%c", GetChar (res[i]));
    printf ("\n");
}

