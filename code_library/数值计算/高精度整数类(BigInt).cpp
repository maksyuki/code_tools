/***********************************************
************************************************
@接口: BigInt
@功能: 进行高精度整数的计算
@时间复杂度:

BigInt ();
BigInt (int num);
BigInt (const char *num);
BigInt operator = (const int num);
BigInt operator = (const char *num);

BigInt operator + (const BigInt &b) const;
BigInt operator += (const BigInt &b);
BigInt operator - (const BigInt &b);
BigInt operator -= (const BigInt &b);
BigInt operator * (const BigInt &b);
BigInt operator *= (const BigInt &b);
BigInt operator / (const BigInt &b);
BigInt operator /= (const BigInt &b);
BigInt operator % (const BigInt &b);
BigInt operator %= (const BigInt &b);

bool operator < (const BigInt &b);
bool operator > (const BigInt &b);
bool operator == (const BigInt &b);
bool operator != (const BigInt &b);
bool operator <= (const BigInt &b);
bool operator >= (const BigInt &b);

void CleanFrontZero ();
string str() const;
BigInt Inc (int v = 1);
BigInt Dec (int v = 1);
istream& operator >> (istream &in, BigInt &x);
ostream& operator << (ostream &out, const BigInt &x);

BigInt Factorial (int n);
BigInt Factorial (BigInt n);
BigInt Pow (BigInt a, int b);

************************************************/

//注意ofstream中加的特判！！！否则高精度数赋值为0时会不输出！！！
const int MAXSIZE = 1e3;
struct BigInt
{
    int len, s[MAXSIZE];
    BigInt () {memset(s, 0, sizeof(s)); len = 1;}
    BigInt (int num) {*this = num;}
    BigInt (const char *num) {*this = num;}

    BigInt operator = (const int num)
    {
        char s[MAXSIZE];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    BigInt operator = (const char *num)
    {
        for (int i = 0; num[i] == '0'; num++) ;
        len = strlen(num);
        for (int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }

    void CleanFrontZero () {while (len > 1 && !s[len-1]) len--;}

    BigInt operator + (const BigInt &b) const
    {
        BigInt c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < max(len, b.len); i++)
        {
            int x = g;
            if (i < len) x += s[i];
            if (i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    BigInt operator - (const BigInt &b)//要满足被减数比减数大
    {
        BigInt c;
        c.len = 0;
        for (int i = 0, g = 0; i < len; i++)
        {
            int x = s[i] - g;
            if (i < b.len) x -= b.s[i];
            if (x >= 0) g = 0;

            else {g = 1; x += 10;}
            c.s[c.len++] = x;
        }
        c.CleanFrontZero();
        return c;
    }

    BigInt operator * (const BigInt &b)
    {
        BigInt c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                c.s[i + j] += s[i] * b.s[j];

        for (int i = 0; i < c.len; i++)
        {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.CleanFrontZero();
        return c;
    }

    BigInt operator / (const BigInt &b)//整数除法，即只保留结果的整数部分
    {
        BigInt c, f = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            f = f * 10;
            f.s[0] = s[i];
            while (f >= b)
            {
                f -= b;
                c.s[i]++;
            }
        }
        c.len = len;
        c.CleanFrontZero();
        return c;
    }

    bool operator < (const BigInt &b)
    {
        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }

    bool operator > (const BigInt &b)
    {
        if (len != b.len) return len > b.len;
        for (int i = len - 1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] > b.s[i];
        return false;
    }

    BigInt operator % (const BigInt &b) { BigInt r = *this / b; r = *this - r * b; return r;}
    BigInt operator += (const BigInt &b) {*this = *this + b; return *this;}
    BigInt operator -= (const BigInt &b) {*this = *this - b; return *this;}
    BigInt operator *= (const BigInt &b) {*this = *this * b; return *this;}
    BigInt operator /= (const BigInt &b) {*this = *this / b; return *this;}
    BigInt operator %= (const BigInt &b) {*this = *this % b; return *this;}
    bool operator == (const BigInt &b) {return !(*this > b) && !(*this < b);}
    bool operator != (const BigInt &b) {return !(*this == b);}
    bool operator <= (const BigInt &b) {return *this < b || *this == b;}
    bool operator >= (const BigInt &b) {return *this > b || *this == b;}
    BigInt Inc (int v = 1) {*this += v; return *this;}
    BigInt Dec (int v = 1) {*this -= v; return *this;}

    string str() const
    {
        string res = "";
        for (int i = 0; i < len; i++) res = char(s[i] + '0') + res;
        return res;
    }
};

istream& operator >> (istream &in, BigInt &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream &out, const BigInt &x)
{
    if (x.len > 0) out << x.str();//非常重要的地方！！！
    else out << "0";
    return out;
}

//高精度阶乘
BigInt Factorial (int n)
{
    BigInt base = 1;
    for (int i = 2; i <= n; i++) base *= i;
    return base;
}

//高精度阶乘
BigInt Factorial (BigInt n)
{
    BigInt res = 1;
    for (BigInt base = 2; base <= n; base.Inc()) res *= base;
    return res;
}

//高精度幂
BigInt Pow (BigInt a, int b)
{
    BigInt s = 1;
    while (b)
    {
        if (b & 1) s *= a;
        a *= a;
        b >>= 1;
    }
    return s;
}
