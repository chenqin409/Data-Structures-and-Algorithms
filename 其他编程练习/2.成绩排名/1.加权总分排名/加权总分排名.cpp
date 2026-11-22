#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    void compute()
    {
        sum=grade_1*40+grade_2*35+grade_3*25;
    }
    string id;
    int grade_1;
    int grade_2;
    int grade_3;
    int sum;
};

bool compare(Student &s1,Student &s2)
{
    if(s1.sum==s2.sum)
    {
        if(s1.grade_1==s2.grade_1)
        {
            if(s1.grade_2==s2.grade_2)
            {
                return s1.grade_3>s2.grade_3;
            }
            return s1.grade_2>s2.grade_2;
        }
        return s1.grade_1>s2.grade_1;
    }
    return s1.sum>s2.sum;
}
int main()
{
    int n;
    cin>>n;
    vector<Student>st(n);
    for(int i=0;i<n;i++)
    {
        cin>>st[i].id;
        cin>>st[i].grade_1>>st[i].grade_2>>st[i].grade_3;
        st[i].compute();
    }
    sort(st.begin(),st.end(),compare);
    for(int i=0;i<3;i++)
    {
        cout<<st[i].id<<" ";
        float value = st[i].sum/10.0;
        value = round(value);
        value /=10.0;

        printf("%.1f\n",value);
    }
    return 0;
}
