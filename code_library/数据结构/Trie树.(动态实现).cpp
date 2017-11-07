/***********************************************
************************************************
@接口: void Init ()
@功能: 初始化根节点
@时间复杂度:

@接口: void Insert (char *s)
@功能: 插入单词
@时间复杂度: O(len(s)))
@*s: 待插入的单词

@接口: bool Query (char *s)
@功能: 查询单词
@时间复杂度: O(len(s))
@*s: 查询的单词

@接口: void DelTree (Trie *t)
@功能: 删除Tire树
@时间复杂度:
@*t: 递归删除的节点
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
