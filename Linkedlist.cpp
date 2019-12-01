#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *right,*left;    	
};
struct node *root=NULL;

int insert(int n)
{
	struct node *temp;
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	
	if(!root)
		root=temp;
	else{
		struct node* ptr=root;
		while(ptr)
		{ 
			if(ptr->data>temp->data)
				ptr=ptr->right;
			else
				ptr=ptr->left;	
		}
		ptr=temp; 
	}
}









int main()
{
	insert(10);
}
