/***********************************************
************************************************
@�ӿ�: void Init ()
@����: ��ʼ�����ڵ�
@ʱ�临�Ӷ�:

@�ӿ�: void Insert (char *s)
@����: ���뵥��
@ʱ�临�Ӷ�: O(len(s)))
@*s: ������ĵ���

@�ӿ�: bool Query (char *s)
@����: ��ѯ����
@ʱ�临�Ӷ�: O(len(s))
@*s: ��ѯ�ĵ���

@�ӿ�: void DelTree (Trie *t)
@����: ɾ��Tire��
@ʱ�临�Ӷ�:
@*t: �ݹ�ɾ���Ľڵ�
************************************************/

const int maxn = 26;
struct Trie
{
    Trie *next[maxn];
    bool last;
    Trie ()    {
        memset (next, 0, sizeof (next));
        last = false;
    }
};

Trie *root;

void Init ()
{
    root = new Trie;
}

void Insert (char *s)
{
    if (!s[0]) return ;

    Trie *p = root;
    for (int i = 0; s[i]; i++)
    {
        if (!p -> next[s[i]-'a'])
            p -> next[s[i]-'a'] = new Trie;

        p = p -> next[s[i]-'a'];
    }
    p -> last = true;
}

bool Query (char *s)
{
    if (!s[0]) return false;

    Trie *p = root;
    for (int i = 0; s[i]; i++)
    {
        if (!p -> next[s[i]-'a'])
            return false;

        p = p -> next[s[i]-'a'];
    }

    if (p -> last)
        return true;

return false;
}

void DelTree (Trie *s)
{
    if (!s) return ;

    for (int i = 0; i < maxn; i++)
    {
        if (s -> next[i])
            DelTree (s -> next[i]);
    }
    delete s;
}
