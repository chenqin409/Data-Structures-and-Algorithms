#include<iostream>
using namespace std;

class Node{
public:
	char data;
	Node* lchild;
	Node* rchild;
};

void CreatTree(Node* &node)
{
	char ch;
	cin>>ch;
	node = new Node;
	if(ch=='#')
	{
		node=NULL;
	}
	else
	{
		node->data = ch;
		CreatTree(node->lchild);
		CreatTree(node->rchild);
	}
}

void preorder(Node* node)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
		cout<<node->data;
		preorder(node->lchild);
		preorder(node->rchild);
	}
}

void inorder(Node* node)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
		inorder(node->lchild);
		cout<<node->data;
		inorder(node->rchild);
	}
}

void postorder(Node* node)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
		postorder(node->lchild);
		postorder(node->rchild);
		cout<<node->data;
	}
}

int main(int argc, char** argv) {
	int time;
	cin>>time;
	for(int i=0;i<time;i++)
	{
		Node* node;
		CreatTree(node);
		inorder(node);
		cout<<endl;
		postorder(node);
		cout<<endl;
			
	}
	return 0;
}
