#include<bits/stdc++.h>
using namespace std;

int apply(int num1,char op,int num2)
{
    if(op=='+') return num1+num2;
    else if(op=='-') return num1-num2;
    else return num1*num2;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num1,num2,num3;
        char op1,op2;
        int result=0;
        cin>>num1>>op1>>num2>>op2>>num3;
        if(op2=='*')
        {
            result = num2*num3;
            result = apply(num1,op1,result);
        }
        else
        {
            result = apply(num1,op1,num2);
            result = apply(result,op2,num3);
        }
        cout<<result<<endl;
    }

    return 0;
}
