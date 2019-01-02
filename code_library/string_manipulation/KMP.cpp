/***********************************************
快速单模式匹配
************************************************
@接口: void Build ()
@功能: 预处理模式串
@时间复杂度: O (n)


@接口: int KMP ()
@功能: 求解模式串匹配
@时间复杂度: O (n)
************************************************/

//pat数组中表示模式串，text数组表示目标串
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
