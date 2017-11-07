/***********************************************
��POJ2104Ϊ��
************************************************
@�ӿ�: void build (int dep, int l,int r)
@����: ���ݶ�������ݽ���������
@ʱ�临�Ӷ�: O (nlogn)		
@dep: ��ǰ���ֵ����
@l: ��ǰ�����������˵�
@r: ��ǰ����������Ҷ˵�

@�ӿ�: int query (int dep, int L, int R, int l, int r, int k)
@����: ��ѯ[l,r]�����ڵ�k���ֵ
@ʱ�临�Ӷ�: O (logn)		
@dep: ��ǰ���ֵ����
@L: ��ǰ�������˵�
@R: ��ǰ������Ҷ˵�
@l: ��ǰ�����������˵�
@r: ��ǰ����������Ҷ˵�
@k: ��ѯ�ĵ�k��
************************************************/

//ע����Ҫ��δ���������������Ҫ������������ʼ��(ȫ��ʼ��Ϊ0)������
int tree[30][maxn];//��ʾÿ��ÿ��λ�õ�ֵ
int sorted[maxn];//�Ѿ��������
int toleft[30][maxn];//toleft[p][i]��ʾ��i���1��i�ж��ٸ����������

void build (int dep, int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    int same = mid - l + 1;//��ʾ�����м�ֵ���ұ�������ߵĸ���
    for (int i = l; i <= r; i++)
      if (tree[dep][i] < sorted[mid])
         same--;

    int lpos = l, rpos = mid + 1;
    for (int i = l; i <= r; i++)
    {
        if (tree[dep][i] < sorted[mid])//���м����С���������
             tree[dep+1][lpos++] = tree[dep][i];
        else if (tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep+1][lpos++] = tree[dep][i];
            same--;
        }
        else  //���м�ֵ������ұ�
            tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1] + lpos - l;//��1��i����ߵĸ���
    }
    build (dep + 1, l, mid);
    build (dep + 1, mid + 1, r);
}

//��ѯ�����k�������[L,R]�Ǵ����䣬[l,r]��Ҫ��ѯ��С����
int query (int dep, int L, int R, int l, int r, int k)
{
    if (l == r) return tree[dep][l];
    int mid = (L + R) >> 1;
    int cnt = toleft[dep][r] - toleft[dep][l-1];//[l,r]��λ����ߵĸ���
    if (cnt >= k)
    {
        //L+Ҫ��ѯ������ǰ��������ߵĸ���
        int newl = L + toleft[dep][l-1] - toleft[dep][L-1];
        //��˵���ϲ�ѯ����ᱻ������ߵĸ���
        int newr = newl + cnt - 1;
        return query (dep + 1, L, mid, newl, newr, k);
    }
    else
    {
         int newr = r + toleft[dep][R] - toleft[dep][r];
         int newl = newr - (r - l - cnt);
         return query (dep + 1, mid + 1, R, newl, newr, k - cnt);
    }
}

int main()
{
    //CFF;
    //CPPFF;
	int n, q;
	while (scanf ("%d%d", &n, &q) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf ("%d", &tree[0][i]);
			sorted[i] = tree[0][i];
		}
		sort (sorted + 1, sorted + 1 + n);
		build (0, 1, n);
		
		for (int i = 1; i <= q; i++)
		{
			int ll, rr, kk;
			scanf ("%d%d%d", &ll, &rr, &kk);
			printf ("%d\n", query (0, 1, n, ll, rr, kk));
		}
	}
    return 0;
}
