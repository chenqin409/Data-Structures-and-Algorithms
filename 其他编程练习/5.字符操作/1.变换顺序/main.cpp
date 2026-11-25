#include <iostream>

using namespace std;

int main()
{
    char s[1005];
    cin>>s;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]!='@')
        {
            break;
        }
        i++;
    }
    int len=0;
    while(s[len]!='\0') len++;
    for(int j=i;j<len;j++)
    {
        cout<<s[j];
    }
    for(int j=0;j<i;j++)
    {
        cout<<s[j];
    }
    return 0;
}
