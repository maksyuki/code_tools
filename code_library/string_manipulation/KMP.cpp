/***********************************************
���ٵ�ģʽƥ��
************************************************
@�ӿ�: void Build ()
@����: Ԥ����ģʽ��
@ʱ�临�Ӷ�: O (n)


@�ӿ�: int KMP ()
@����: ���ģʽ��ƥ��
@ʱ�临�Ӷ�: O (n)
************************************************/

//pat�����б�ʾģʽ����text�����ʾĿ�괮
char pat[maxn], text[maxn];int Next[maxn];

void Build ()
{
	int len = strlen (pat), k = 0;
    Next[0] = -1, Next[1] = 0;
	for (int i = 2; i <= len; i++)
	{
		while (k >= 0 && pat[i-1] != pat[k]) k = Next[k];

		Next[i] = ++k;
	}
}

int KMP ()
{
	int len_pat = strlen (pat), len_text = strlen (text);

    if (len_pat < 1 || len_text < 1 || len_text < len_pat)
        return -1;

	int i = 0, j = 0;
    while (i < len_text)
    {
        if (pat[j] == text[i] || j == -1)
            i++, j++;

        else
            j = Next[j];

        if (j == len_pat)
            return i - j;
    }

return -1;
}
