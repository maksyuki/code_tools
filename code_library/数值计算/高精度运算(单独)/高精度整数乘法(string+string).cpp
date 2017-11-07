/***********************************************
************************************************
@接口: string Mul (string a, string b)
@功能:
@时间复杂度: O (n ^ 2)
@:
************************************************/

string Mul (string a, string b)//高精度乘法a,b,均为非负整数
{
    string s;// maxn表示相乘的数的最大可能位数
    int na[maxn], nb[maxn], nc[maxn], La = a.size (), Lb = b.size ();//na存储被乘数，nb存储乘数，nc存储积

    fill (na, na + maxn, 0); fill (nb, nb + maxn, 0); fill (nc, nc + maxn, 0);//将na,nb,nc都置为0

    for(int i = La - 1; i >= 0; i--)
        na[La-i] = a[i] - '0';//将字符串表示的大整形数转成i整形数组表示的大整形数

    for (int i = Lb - 1; i >= 0; i--)
        nb[Lb-i] = b[i] - '0';

    for (int i = 1; i <= La; i++)
        for (int j = 1; j <= Lb; j++)
            nc[i+j-1] += na[i] * nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）

    for (int i = 1; i <= La + Lb; i++)
    {
        nc[i+1] += nc[i] / 10;
        nc[i] %= 10;//统一处理进位
    }

    if (nc[La+Lb])
        s += nc[La+Lb] + '0';//判断第i+j位上的数字是不是0

    for (int i = La + Lb - 1; i >= 1; i--)
        s += nc[i] + '0';//将整形数组转成字符串

return s;
}
