/*
设有1g、2g、3g、5g、10g、20g的砝码各若干枚（其总重<=1000），用他们能称出的重量的种类数。
*/
/*
输入：
a1  a2  a3  a4  a5  a6
（表示1g砝码有a1个，2g砝码有a2个，…，20g砝码有a6个，中间有空格）。
*/
/*
样例输入：
1 1 0 0 0 0
正确输出：
3
*/
//分析：把问题稍做一个改动，已知a1+a2+a3+a4+a5+a6个砝码的重量w[i], w[i]∈{ 1,2,3,5,10,20}
//其中砝码重量可以相等，求用这些砝码可称出的不同重量的个数.
//这样一改就是经典的0/1背包问题的简化版了，求解方法完全和上面说的一样
//这里就不多说了，只是要注意这个题目不是求最大载重量，是统计所有的可称出的重量的个数。


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int w[6]={1,2,3,5,10,20};
    int d[6];
    int dp[1001];
    memset(dp,0,sizeof(dp));
    int x;
    for(int i=0;i<6;i++){
        scanf("%d",&x);
        d[i]=w[i]*x;
    }
    for(int i=0;i<6;i++){
        for(int j=1000;j-w[i]>=0;j--){
            dp[j]=max(dp[j],dp[j-d[i]]+d[i]);
        }
    }
    printf("%d\n",dp[1000]);
    return 0;
}
