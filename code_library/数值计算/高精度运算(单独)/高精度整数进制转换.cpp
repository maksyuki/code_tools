/***********************************************
���M���Ƶ�N���Ƶĸ߾���ת��
************************************************
@�ӿ�: int GetNum (char c)
@����: ���ַ�ת��������
@ʱ�临�Ӷ�: O (1)
@c: ��ת�������ֵ��ַ�

@�ӿ�: char GetChar (int val)
@����: ������ת�����ַ�
@ʱ�临�Ӷ�: O (1)
@val: ��ת�����ַ�������

@�ӿ�: void Change ()
@����: ��������ַ����ĸ�����λ��ԭΪ������ʽ
@ʱ�临�Ӷ�: O (n)

@�ӿ�: void Solve ()
@����: ����������
@ʱ�临�Ӷ�: O (n ^ 2)

@�ӿ�: void Output ()
@����: ������Ӧ����������
@ʱ�临�Ӷ�: O (n)
************************************************/

const int maxn = 100000 + 66;

char str[maxn];//�����ַ���
int start[maxn], ans[maxn], res[maxn];//���������̣�����
int oldBase, newBase;//ת��ǰ��Ľ���


int GetNum (char c)//��������ַ��������֣����д��ĸ����Сд��ĸ��
{
    if(c >= '0' && c <= '9') return c - '0';//����
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;//��д��ĸ
    return c - 'a' + 36;//Сд��ĸ
}


char GetChar (int i)//���ֵõ��ַ�
{
    if (i >= 0 && i <= 9) return i + '0';
    if (i >= 10 && i <= 35) return i - 10 + 'A';
    return i - 36 + 'a';
}

void Change ()//��������ַ����ĸ�����λ��ԭΪ������ʽ
{
    int i;
    start[0] = strlen (str);//�����0λ��������鳤��
    for(i = 1; i <= start[0]; i++)
        start[i] = GetNum (str[i-1]);
}

void Solve ()
{
    memset (res, 0, sizeof (res));//������ʼ��Ϊ��
    int y, i, j;
    //ģnȡ�෨��(�������������Ϊ��λ������Ϊ��λ)
    while (start[0] >= 1)
    {//ֻҪ��������Ȼ���ڵ���1���Ǿͼ�����ģ2ȡ�ࡱ
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
        res[++res[0]] = y;//��һ������õ�������
        i = 1;
        //�ҵ���һ���̵���ʼ��
        while ((i <= ans[0]) && (ans[i] == 0)) i++;
        //�����һ��ʹ�õı�����
        memset (start, 0, sizeof(start));
        //���ֵõ����̱�Ϊ��һ�ֵı�����
        for(j = i;j <= ans[0]; j++)
            start[++start[0]] = ans[j];
        memset (ans, 0, sizeof(ans)); //�����һ�ֵ��̣�Ϊ��һ��������׼��
    }
}

void Output ()//�Ӹ�λ����λ�������
{
    int i;
    for (i = res[0]; i >= 1; i--)
        printf ("%c", GetChar (res[i]));
    printf ("\n");
}

