#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long>a;
    for(int i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        a.push_back(temp);
    }
    vector<long long>b;
    for(int i=0;i<n-1;i++)
    {
        b.push_back(a[i+1]-a[i]);
    }
    sort(b.begin(),b.end(),greater<long long>());
    long long value1 = a[n-1]-a[0]+1;
    long long value2=0;
    for(int i=0;i<m-1;i++)
    {
        value2+=b[i]-1;
    }
    cout<<value1-value2;
    return 0;
}
