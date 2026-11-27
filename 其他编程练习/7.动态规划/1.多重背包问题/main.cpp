#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,W;
    cin>>n>>W;
    vector<int>value,weight;
    for(int i=0;i<n;i++)
    {
        int vi,wi,mi;
        cin>>vi>>wi>>mi;


        for(int k=1;k<=mi;k*=2)  //通过二进制数来表示数量，节省空间
        {
            value.push_back(vi*k);
            weight.push_back(wi*k);
            mi-=k;  //k=1+2+4+8+……
        }
        if(mi>0)  //补全余数
        {
            value.push_back(vi*mi);
            weight.push_back(wi*mi);
        }
    }

    vector<int>dp(W+1,0); //动态规划
    for(int i=0;i<weight.size();i++)  //weight.size()=有几个包
    {
        for(int j=W;j>=weight[i];j--)  //逆序更新数据，正序会加入重复更新的值
        {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]); //对于每一个包i,比较该二进制数是0或1的结果
        }
    }
    cout<<dp[W];

    return 0;
}
