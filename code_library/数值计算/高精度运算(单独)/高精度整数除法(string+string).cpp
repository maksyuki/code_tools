/***********************************************
************************************************
@接口: string Div (string n1, string n2, int nn)
@时间复杂度: O (n * 2)
@:
************************************************/

int Sub (int *a, int *b, int La, int Lb)
{
    if (La < Lb)
        return -1;//如果a小于b，则返回-1

    if (La == Lb)
    {
        for (int i = La - 1; i >= 0; i--)
        {
            if (a[i] > b[i])
                break;

            else if (a[i] < b[i])
                return -1;//如果a小于b，则返回-1
        }
    }

    for (int i = 0; i < La; i++)//高精度减法
    {
        a[i] -= b[i];
        if (a[i] < 0)
        {
            a[i] += 10;
            a[i+1]--;
        }
    }

    for (int i = La - 1; i >= 0; i--)
        if (a[i])
        return i + 1;//返回差的位数

return 0;//返回差的位数
}

string Div (string n1, string n2, int nn)//n1,n2是字符串表示的被除数，除数,nn是选择返回商还是余数
{//nn == 1表示返回商, n == 2表示返回余数

    if (nn == 1 && ((n1.size () < n2.size ()) || (n1.size () == n2.size () && n1 < n2)))
        return "0";//十分重要!!!!!!

    string s, v;//s存商,v存余数
    int a[maxn], b[maxn], r[maxn], La = n1.size (),Lb = n2.size (), i, tp = La;//a，b是整形数组表示被除数，除数，tp保存被除数的长度

    fill (a, a + maxn, 0); fill (b, b + maxn, 0); fill (r, r + maxn, 0);//数组元素都置为0

    for (i = La - 1; i >= 0; i--)
        a[La-1-i] = n1[i] - '0';

    for (i = Lb - 1; i >= 0; i--)
        b[Lb-1-i] = n2[i] - '0';

    if (La < Lb || (La == Lb && n1 < n2))
    {//cout<<0<<endl;
     return n1;
    }//如果a<b,则商为0，余数为被除数

    int t = La - Lb;//除被数和除数的位数之差

    for (int i = La - 1; i >= 0; i--)//将除数扩大10^t倍
    {
        if (i >= t)
            b[i] = b[i-t];

        else
            b[i] = 0;
    }

    Lb = La;
    for (int j = 0; j <= t; j++)
    {
        int temp;
        while ((temp = Sub (a, b + j, La, Lb - j)) >= 0)//如果被除数比除数大继续减
        {
            La = temp;
            r[t-j]++;
        }
    }

    for (i = 0; i < maxn - 10; i++)
    {
        r[i+1] += r[i] / 10;
        r[i] %= 10;//统一处理进位
    }

    while (!r[i]) i--;//将整形数组表示的商转化成字符串表示的
    while (i >= 0) s += r[i--] + '0';

    i = tp;

    while (!a[i]) i--;//将整形数组表示的余数转化成字符串表示的</span>

    while (i >= 0) v += a[i--] + '0';

    if (v.empty ())
        v = "0";
     //cout<<v<<endl;
    if (nn == 1)
        return s;

    if (nn == 2)
        return v;
}
