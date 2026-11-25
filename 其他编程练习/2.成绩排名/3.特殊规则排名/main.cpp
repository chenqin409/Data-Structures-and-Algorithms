#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end(),greater<int>());

    int result =1;
    for(int i=1;i<n;i++)
    {
        vector<int>temp =a;
        temp[i]+=n;
        if(temp[i]>temp[0])
        {
            sort(temp.begin(),temp.end(),greater<int>());
            int judge =1;
            for(int j=1;j<n;j++)
            {
                 if(temp[0]-temp[j]>=j)  continue;
                 else
                 {
                     judge = 0;
                     break;
                 }
            }
            if(judge==0) break;
            else result++;
        }
        else break;

    }
    cout<<result;
    return 0;
}
