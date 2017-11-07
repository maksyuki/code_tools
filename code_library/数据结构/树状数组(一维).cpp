/***********************************************
************************************************
@�ӿ�: int lowbit (int x)
@ʱ�临�Ӷ�: O (1)
@x: ��״������±�

@�ӿ�: int GetSum (int x)
@ʱ�临�Ӷ�: O (logn)
@x: ��ѯ����(0,x)���Ͻ�λ��

@�ӿ�: void UpDate (int x, int v)
@ʱ�临�Ӷ�: O (logn)
@x: ��������(0,x)���Ͻ�λ��
@v: ����ֵ
************************************************/

int bit[maxn];
//ȡx��λһ���ж��ٸ�0
inline int lowbit (int x) {return x & (-x);}

//��ǰ׺��
inline int GetSum (int x) {
    int res;
    for (res = 0; x; x -= lowbit (x)) res += bit[x];
    return res;
}

//�������
inline void UpDate (int x, int v) {
    for (; x <= n; x += lowbit (x)) bit[x] += v;
}
