/***********************************************
************************************************
@�ӿ�: string Div (string a, long long b)
@����:
@ʱ�临�Ӷ�: O (n)
@:
************************************************/

string Div (string a, long long b)//�߾���a���Ե�����b
{
    string r;
    long long d = 0;

    if(a == "0")
        return a;//����

    for (long long i = 0; i < a.size (); i++)
    {
        r += (d * 10 + a[i] - '0') / b + '0';//�����
        d = (d * 10 + (a[i] - '0')) % b;//�������
    }

    long long p = 0;
    for (long long i = 0; i < r.size (); i++)
        if (r[i] != '0')
        {
            p = i;
            break;
        }

return r.substr (p);
}
