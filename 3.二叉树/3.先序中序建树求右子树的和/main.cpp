#include<bits/stdc++.h>
using namespace std;

class node{
public:
	node(int value)
	{
		this->data=value;
		this->left=NULL;
		this->right=NULL;
	}
	int data;
	node* left;
	node* right;
};

node* BuildTree(const vector<int>&v1,int v1_left,int v1_right,const vector<int>&v2,int v2_left,int v2_right)
{
	if(v1_left>=v1_right) return NULL;
	int root_value = v1[v1_left];
	int pos=0;
	node* root = new node(root_value);
	while(v2[pos]!=root_value) pos++;
	int left_size = pos - v2_left;
	root->left = BuildTree(v1,v1_left+1,v1_left+1+left_size,v2,v2_left,v2_left+left_size);
	root->right = BuildTree(v1,v1_left+1+left_size,v1_right,v2,v2_left+left_size+1,v2_right);
	return root;
}

node* find_value(node* root,int value)
{
	if(root==NULL) return NULL;
	if(root->data==value) return root;
	node* temp = find_value(root->left,value);
	if(temp!=NULL) return temp;
	return find_value(root->right,value);
}

int calculate_target(node* root)
{
	if(root==NULL) return 0;
	int sum = root->data;
	sum+=calculate_target(root->left);
	sum+=calculate_target(root->right);
	return sum;
}
int main() {
	int n,temp,target;
	cin>>n;
	vector<int>v1,v2;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v1.push_back(temp);
	}
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v2.push_back(temp);
	}
	cin>>target;
	node* m_node=BuildTree(v1,0,n,v2,0,n);
	m_node = find_value(m_node,target);
	int sum;
	if(m_node==NULL)
	{
		sum=-1;
	}
	else if(m_node->right==NULL)
	{
		sum=0;
	}
	else 
	{
		sum = calculate_target(m_node->right);
	}
	cout<<sum;
	return 0;
}
