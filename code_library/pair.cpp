

priority_queue <PII> qu;//���յ�һ�ؼ��ֵ�������
priority_queue <PII, vector <PII>, less <PII> > qu;//���յ�һ�ؼ��ֵ�������
priority_queue <PII, vector <PII>, greater <PII> > qu;//���յ�һ�ؼ��ֵݼ�����

//pair <Ta, Tb>Ĭ���ǰ���Ta�����������밴��Tb������Ҫ���رȽϼ������£�������ǰ���Tb���������
struct cmp
{
    bool operator () (const PII&a, const PII&b) {return a.second < b.second;}
};

priority_queue <PII, vector <PII>, cmp> qu;
