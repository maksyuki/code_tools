
struct BigNum
{
    char a[maxn];
    int lenth;
    bool flag;
};

BigNum change_to_BigNum (int n) ;
BigNum BigNum_abs (BigNum BN) ;
bool operator < (BigNum BN1, BigNum BN2) ;
bool operator > (BigNum BN1, BigNum BN2) ;
bool operator == (BigNum BN1, BigNum BN2) ;
bool operator <= (BigNum BN1, BigNum BN2) ;
bool operator >= (BigNum BN1, BigNum BN2) ;
BigNum operator + (BigNum BN1, BigNum BN2) ;
BigNum operator - (BigNum BN1, BigNum BN2) ;
BigNum operator * (BigNum BN1, BigNum BN2) ;
BigNum operator * (BigNum BN, long long t) ;
BigNum operator / (BigNum BN1, BigNum BN2) ;
BigNum operator / (BigNum BN, long long t) ;
BigNum operator % (BigNum BN1, BigNum BN2) ;
long long operator % (BigNum BN, long long t) ;
BigNum operator ^ (BigNum BN1, BigNum BN2) ;
BigNum operator += (BigNum &BN1, BigNum BN2) ;
BigNum operator -= (BigNum &BN1, BigNum BN2) ;
BigNum operator *= (BigNum &BN1, BigNum BN2) ;
BigNum operator *= (BigNum &BN, long long t) ;
BigNum operator /= (BigNum &BN1, BigNum BN2) ;
BigNum operator /= (BigNum &BN, long long t) ;
BigNum operator %= (BigNum &BN1, BigNum BN2) ;
BigNum operator %= (BigNum &BN, long long t) ;
BigNum operator ^= (BigNum &BN1, BigNum BN2) ;

int max(int a,int b)
{
    return a>b?a:b;
}

void Input_BigNum(BigNum &BN)
{
    char ch[MAX];
    scanf("%s",ch);
    int len=strlen(ch);
    BN=change_to_BigNum(0);
    BigNum temp=change_to_BigNum(1);
    int i=0;
    for(i=len-1;i>=0;i--)
    {
        if(ch[i]=='1')
            BN+=temp;
        temp*=2;
    }
}

void Output_BigNum(BigNum BN)
{
    BigNum zero=change_to_BigNum(0);
    int i,ans[MAX],num=0;
    while(BN>zero)
    {
        ans[num++]=(BN.a[0]-'0')%2;
        BN/=2;
    }
    for(i=num-1;i>=0;i--)
        printf("%d",ans[i]);
}

BigNum BigNum_abs(BigNum BN)
{
    BigNum ans=BN;
    ans.flag=true;
    return ans;
}

BigNum change_to_BigNum(int n)
{
    BigNum ans;
    if(n==0)
    {
        ans.lenth=1;
        ans.a[0]='0';
        ans.flag=true;
        return ans;
    }
    int m=abs(n);
    ans.lenth=0;
    while(m>0)
    {
        ans.a[ans.lenth++]=m%10+48;
        m/=10;
    }
    if(n<0)
        ans.flag=false;
    else
        ans.flag=true;
    return ans;
}

bool operator ==(BigNum BN1,BigNum BN2)
{
    if(BN1.lenth!=BN2.lenth||BN1.flag!=BN2.flag)
        return false;
    int i;
    for(i=0;i<BN1.lenth;i++)
    {
        if(BN1.a[i]!=BN2.a[i])
            return false;
    }
    return true;
}

bool operator !=(BigNum BN1,BigNum BN2)
{
    return !(BN1==BN2);
}

bool operator <(BigNum BN1,BigNum BN2)
{
    if(BN1.flag==false&&BN2.flag==true)
        return true;
    if(BN1.flag==true&&BN2.flag==false)
        return false;
    if(BN1.lenth<BN2.lenth)
        return BN1.flag;
    if(BN1.lenth>BN2.lenth)
        return !BN1.flag;
    int i;
    for(i=BN1.lenth-1;i>=0;i--)
    {
        if(BN1.a[i]<BN2.a[i])
            return BN1.flag;
        if(BN1.a[i]>BN2.a[i])
            return !BN1.flag;
    }
    return false;
}

bool operator >(BigNum BN1,BigNum BN2)
{
    if(BN1.flag==true&&BN2.flag==false)
        return true;
    if(BN1.flag==false&&BN2.flag==true)
        return false;
    if(BN1.lenth>BN2.lenth)
        return BN1.flag;
    if(BN1.lenth<BN2.lenth)
        return !BN1.flag;
    int i;
    for(i=BN1.lenth-1;i>=0;i--)
    {
        if(BN1.a[i]>BN2.a[i])
            return BN1.flag;
        if(BN1.a[i]<BN2.a[i])
            return !BN1.flag;
    }
    return false;
}

bool operator <=(BigNum BN1,BigNum BN2)
{
    if(BN1.flag==false&&BN2.flag==true)
        return true;
    if(BN1.flag==true&&BN2.flag==false)
        return false;
    if(BN1.lenth<BN2.lenth)
        return BN1.flag;
    if(BN1.lenth>BN2.lenth)
        return !BN1.flag;
    int i;
    for(i=BN1.lenth-1;i>=0;i--)
    {
        if(BN1.a[i]<BN2.a[i])
            return BN1.flag;
        if(BN1.a[i]>BN2.a[i])
            return !BN1.flag;
    }
    return true;
}

bool operator >=(BigNum BN1,BigNum BN2)
{
    if(BN1.flag==true&&BN2.flag==false)
        return true;
    if(BN1.flag==false&&BN2.flag==true)
        return false;
    if(BN1.lenth>BN2.lenth)
        return BN1.flag;
    if(BN1.lenth<BN2.lenth)
        return !BN1.flag;
    int i;
    for(i=BN1.lenth-1;i>=0;i--)
    {
        if(BN1.a[i]>BN2.a[i])
            return BN1.flag;
        if(BN1.a[i]<BN2.a[i])
            return !BN1.flag;
    }
    return true;
}

BigNum operator +(BigNum BN1,BigNum BN2)
{
    if(BN1.flag==false&&BN2.flag==true)
        return BN2-BigNum_abs(BN1);
    if(BN1.flag==true&&BN2.flag==false)
        return BN1-BigNum_abs(BN2);
    BigNum ans;
    ans.flag=BN1.flag;
    int bn1[MAX],bn2[MAX],result[MAX],len=max(BN1.lenth,BN2.lenth),c=0,i;
    for(i=0;i<BN1.lenth;i++)
        bn1[i]=BN1.a[i]-48;
    for(;i<len;i++)
        bn1[i]=0;
    for(i=0;i<BN2.lenth;i++)
        bn2[i]=BN2.a[i]-48;
    for(;i<len;i++)
        bn2[i]=0;
    for(i=0;i<len;i++)
    {
        result[i]=bn1[i]+bn2[i]+c;
        if(result[i]>=10)
        {
            result[i]-=10;
            c=1;
        }
        else
            c=0;
    }
    if(c==1)
        result[len++]=1;
    ans.lenth=len;
    for(i=0;i<ans.lenth;i++)
        ans.a[i]=result[i]+48;
    return ans;
}

BigNum operator -(BigNum BN1,BigNum BN2)
{
    if(BN1.flag==true&&BN2.flag==false)
        return BN1+BigNum_abs(BN2);
    BigNum ans;
    if(BN1.flag==false&&BN2.flag==true)
    {
        ans=BigNum_abs(BN1)+BN2;
        ans.flag=false;
        return ans;
    }
    if(BN1.flag==false&&BN2.flag==false)
        return BigNum_abs(BN2)-BigNum_abs(BN1);
    int bn1[MAX],bn2[MAX],result[MAX],len,c=0,i;
    if(BN1>=BN2)
    {
        ans.flag=true;
        len=BN1.lenth;
        for(i=0;i<BN1.lenth;i++)
            bn1[i]=BN1.a[i]-48;
        for(i=0;i<BN2.lenth;i++)
            bn2[i]=BN2.a[i]-48;
        for(;i<len;i++)
            bn2[i]=0;
    }
    else
    {
        ans.flag=false;
        len=BN2.lenth;
        for(i=0;i<BN2.lenth;i++)
            bn1[i]=BN2.a[i]-48;
        for(i=0;i<BN1.lenth;i++)
            bn2[i]=BN1.a[i]-48;
        for(;i<len;i++)
            bn2[i]=0;
    }
    for(i=0;i<len;i++)
    {
        result[i]=bn1[i]-bn2[i]-c;
        c=0;
        if(result[i]<0)
        {
            result[i]+=10;
            c=1;
        }
        else
            c=0;
    }
    ans.lenth=0;
    while(result[len-1]==0&&len>1)
        len--;
    for(i=0;i<len;i++)
        ans.a[ans.lenth++]=result[i]+48;
    return ans;
}

BigNum operator *(BigNum BN1,BigNum BN2)
{
    BigNum zero=change_to_BigNum(0);
    if(BN1==zero||BN2==zero)
        return zero;
    BigNum ans;
    ans.flag=BN1.flag==BN2.flag;
    int bn1[MAX],bn2[MAX],result[MAX],i,j;
    for(i=0;i<BN1.lenth;i++)
        bn1[i]=BN1.a[i]-48;
    for(i=0;i<BN2.lenth;i++)
        bn2[i]=BN2.a[i]-48;
    memset(result,0,sizeof(result));
    for(i=0;i<BN1.lenth;i++)
    {
        for(j=0;j<BN2.lenth;j++)
            result[i+j]+=bn1[i]*bn2[j];
    }
    for(i=0;i<BN1.lenth+BN2.lenth-1;i++)
    {
        result[i+1]+=result[i]/10;
        result[i]%=10;
    }
    ans.lenth=i;
    if(result[i]>0)
        ans.lenth++;
    for(i=0;i<ans.lenth;i++)
        ans.a[i]=result[i]+48;
    return ans;
}

BigNum operator *(BigNum BN,int t)
{
    BigNum ans;
    if(t==0)
    {
        ans.flag=true;
        ans.lenth=1;
        ans.a[0]='0';
        return ans;
    }
    int i,j,temp,tt=abs(t),bn1[MAX],bn2[MAX],lenth;
    memset(bn2,0,sizeof(bn2));
    for(i=0;i<BN.lenth;i++)
        bn1[i]=BN.a[i]-48;
    i=0;
    while(tt>0)
    {
        temp=tt%10;
        tt/=10;
        for(j=0;j<BN.lenth;j++)
            bn2[j+i]+=temp*bn1[j];
        i++;
    }
    lenth=i+BN.lenth;
    for(i=0;i<lenth;i++)
    {
        bn2[i+1]+=bn2[i]/10;
        bn2[i]%=10;
    }
    while(bn2[i]==0&&i>0)
        i--;
    ans.lenth=i+1;
    ans.flag=(t<0&&BN.flag==false)||(t>=0&&BN.flag==true);
    for(i=0;i<ans.lenth;i++)
        ans.a[i]=bn2[i]+48;
    return ans;
}

BigNum operator /(BigNum BN1,BigNum BN2)
{
    BigNum bn1,bn2,cmp,zero;
    bn1=BigNum_abs(BN1);
    bn2=cmp=BigNum_abs(BN2);
    zero=change_to_BigNum(0);
    if(bn1<bn2||bn2==zero)
        return zero;
    BigNum ans;
    ans.flag=BN1.flag==BN2.flag;
    ans.lenth=0;
    bn2.lenth=bn1.lenth;
    int i,j;
    for(i=0;i<BN1.lenth-BN2.lenth;i++)
        bn2.a[i]='0';
    for(j=0;i<bn2.lenth;i++)
        bn2.a[i]=BN2.a[j++];
    while(bn2>=cmp)
    {
        ans.a[ans.lenth]='0';
        while(bn1>=bn2)
        {
            bn1-=bn2;
            ans.a[ans.lenth]++;
        }
        ans.lenth++;
        for(i=bn2.lenth-BN2.lenth;i<bn2.lenth;i++)
            bn2.a[i-1]=bn2.a[i];
        bn2.lenth--;
    }
    reverse(ans.a,ans.a+ans.lenth);
    while(ans.a[ans.lenth-1]=='0')
        ans.lenth--;
    return ans;
}

BigNum operator /(BigNum BN,int t)
{
    int i=BN.lenth-1,temp=0;
    BigNum ans;
    ans.lenth=0;
    ans.flag=true;
    while(i>=0)
    {
        temp=temp*10+BN.a[i]-48;
        ans.a[ans.lenth++]=temp/t+48;
        temp%=t;
        i--;
    }
    reverse(ans.a,ans.a+ans.lenth);
    while(ans.a[ans.lenth-1]=='0')
        ans.lenth--;
    return ans;
}

BigNum operator %(BigNum BN1,BigNum BN2)
{
    BigNum zero=change_to_BigNum(0),one=change_to_BigNum(1);
    if(BN1==zero||BN2==zero||BN2==one)
        return zero;
    BigNum two=change_to_BigNum(2);
    if(BN2==two)
        return change_to_BigNum((BN1.a[0]-'0')%2);
    BigNum bn1=BigNum_abs(BN1),bn2=BN2,cmp=BN2;
    bn2.lenth=bn1.lenth;
    int i,j;
    for(i=0;i<BN1.lenth-BN2.lenth;i++)
        bn2.a[i]='0';
    for(j=0;i<bn2.lenth;i++)
        bn2.a[i]=BN2.a[j++];
    while(bn2>=cmp)
    {
        while(bn1>=bn2)
            bn1-=bn2;
        for(i=bn2.lenth-BN2.lenth;i<bn2.lenth;i++)
            bn2.a[i-1]=bn2.a[i];
        bn2.lenth--;
    }
    if(bn1==zero)
        return zero;
    return BN1.flag==true?bn1:BN2-bn1;
}

int operator %(BigNum BN,int t)
{
    if(BN==change_to_BigNum(0)||t<=1)
        return 0;
    if(t==2)
        return (BN.a[0]-48)%2;
    int temp=t,i,j,digit=0,lenth=0,ans=0;
    while(temp>0)
    {
        lenth++;
        temp/=10;
    }
    for(i=BN.lenth-1;i>=0;i--)
    {
        if(digit<lenth)
        {
            digit++;
            ans=ans*10+BN.a[i]-48;
        }
        else
        {
            temp=ans;
            for(j=1;j<=9;j++)
            {
                while(ans>=0)
                    ans-=t;
                ans+=temp;
            }
            ans=(ans-t+BN.a[i]-48)%t;
            if(ans<0)
                ans+=t;
            temp=ans;
            digit=0;
            while(temp>0)
            {
                digit++;
                temp/=10;
            }
        }
    }
    ans%=t;
    return BN.flag==true?ans:(t-ans)%t;
}

BigNum operator ^(BigNum BN1,BigNum BN2)
{
    BigNum zero=change_to_BigNum(0),one=change_to_BigNum(1),two=change_to_BigNum(2);
    BigNum ans=one,temp=BN1;
    while(BN2>zero)
    {
        if(BN2%two==one)
            ans*=temp;
        temp*=temp;
        BN2/=two;
    }
    return ans;
}

BigNum operator +=(BigNum &BN1,BigNum BN2)
{
    BN1=BN1+BN2;
    return BN1;
}

BigNum operator -=(BigNum &BN1,BigNum BN2)
{
    BN1=BN1-BN2;
    return BN1;
}

BigNum operator *=(BigNum &BN1,BigNum BN2)
{
    BN1=BN1*BN2;
    return BN1;
}

BigNum operator *=(BigNum &BN,int t)
{
    BN=BN*t;
    return BN;
}

BigNum operator /=(BigNum &BN1,BigNum BN2)
{
    BN1=BN1/BN2;
    return BN1;
}

BigNum operator /=(BigNum &BN,int t)
{
    BN=BN/t;
    return BN;
}

BigNum operator %=(BigNum &BN1,BigNum BN2)
{
    BN1=BN1%BN2;
    return BN1;
}

BigNum operator %=(BigNum &BN,int t)
{
    BN=change_to_BigNum(BN%t);
    return BN;
}

BigNum operator ^=(BigNum BN1,BigNum BN2)
{
    BN1=BN1^BN2;
    return BN1;
}
