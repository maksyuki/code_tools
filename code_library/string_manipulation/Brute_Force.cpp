/***********************************************
@func:
@interface:
@complexity:
@notes:
************************************************/

int GetStringMatch (string &text, string &pat)
{
    int len_text =  text.size (), len_pat = pat.size ();
    if (len_pat < 1 || len_text < 1 || len_text < len_pat) return -1;

    for (int i = 0; i < len_text - len_pat; i++) {
        int j, k;
        for (j = 0, k = i; j < len_pat; j++, k++)
            if (text[k] != pat[j])
                break;

        if (j == len_pat) return i;
    }
    return -1;
}
