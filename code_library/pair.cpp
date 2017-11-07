

priority_queue <PII> qu;//按照第一关键字递增排序
priority_queue <PII, vector <PII>, less <PII> > qu;//按照第一关键字递增排序
priority_queue <PII, vector <PII>, greater <PII> > qu;//按照第一关键字递减排序

//pair <Ta, Tb>默认是按照Ta递增排序，若想按照Tb排序，需要重载比较级，如下，下面的是按照Tb递增排序的
struct cmp
{
    bool operator () (const PII&a, const PII&b) {return a.second < b.second;}
};

priority_queue <PII, vector <PII>, cmp> qu;
