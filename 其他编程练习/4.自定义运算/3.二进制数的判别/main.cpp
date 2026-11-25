#include <iostream>

using namespace std;
int compute(int a)
{
    if(a>>2 >0) return 1;
    else return 0;
}
int main()
{
    int n;
    cin>>n;
    int result=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        result +=compute(a);

    }
    cout<<result;
    return 0;
}
