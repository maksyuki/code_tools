
const int maxn = 26;
const int nodemaxn = 1e6;

struct Trie
{
    int next[nodemaxn][maxn], last[nodemaxn];
    int root , len;

    void Init ()
    {
        len = 0;
        root = newnode ();
    }

    int newnode ()
    {
        for (int i = 0; i < maxn; i++)
            next[len][i] = -1;
        last[len++] = 0;

        return len - 1;
    }

    void Insert (char *s)
    {
        int p = root;
        for(int i = 0; s[i]; i++)
        {
            if(next[p][s[i]-'a'] == -1)
                next[p][s[i]-'a'] = newnode ();

            p = next[p][s[i]-'a'];
        }
        last[p] = 1;
    }

    int Query (char *s)
    {
        if (!s[0]) return -1;

        int p = root;
        for (int i = 0; s[i]; i++)
        {
            if (next[p][s[i]-'a'] == -1)
                return -1;

            p = next[p][s[i]-'a'];
        }

        if (last[p]) return last[p];

        return -1;
    }
};
