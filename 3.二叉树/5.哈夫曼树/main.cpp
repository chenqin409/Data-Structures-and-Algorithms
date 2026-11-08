#include<iostream>
#include<queue>
#include<algorithm>
using namespace std; 

int main() {
	int n,temp;
	priority_queue<int,vector<int>,greater<int>>q;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		q.push(temp);
	}
	int sum=0,value_1,value_2;
	while(q.size()>1)
	{
		value_1 = q.top();
		q.pop();
		value_2 = q.top();
		q.pop();
		sum+=value_1+value_2;
		q.push(value_1+value_2);
	}
	cout<<sum;
	return 0;
}
