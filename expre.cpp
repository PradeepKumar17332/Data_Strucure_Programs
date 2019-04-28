#include<bits/stdc++.h>
using namespace std;

struct node
{
	char data;
	struct node *l;
	struct node *r;
};
struct node1
{
	struct node *r;
	struct node1 *link;
};
struct node2
{
	struct node *r;
	struct node2 *link;
	int flag;
};	
class stack2
{
	struct node2 *top;
	public:
	stack2()
	{
		top=NULL;
	}
	void push2(struct node *root,int f) 
	{
		struct node2 *ptr;
		ptr=new node2;
		ptr->r=root;
		ptr->flag=f;
		if(top!=NULL)
		{
			ptr->link=top;
			top=ptr;
		}
		else
		{top=ptr;}
	}
	struct node* pop2(int *f)
	{
		if(top==NULL)
		{
			return NULL;
		}
		struct node2 *ptr=top;
		top=top->link;
		*f=ptr->flag;
		return (ptr->r);
		
	}
	bool isempty()
	{
		if(top==NULL)
			return true;
		else
			return false;
	}
	struct node *top1(int *f)
    {
    	*f=top->flag;
    	return(top->r);
	}
};
class stack1
{
	struct node1 *top;

public:
	stack1()
	{
		top=NULL;
	}
	void  push1(struct node *root)
	{
		struct node1 *ptr;
		ptr=new node1;
		ptr->r=root;
		if(top!=NULL)
		{
			ptr->link=top;
			top=ptr;
		}
		else
		{top=ptr;}
	}
	struct node* pop1()
	{
		if(top==NULL)
		{
			return NULL;
		}
		struct node1 *ptr=top;
		top=top->link;
		return (ptr->r);
		
	}
	bool isempty()
	{
		if(top==NULL)
			return true;
		else
			return false;
	}
};
class tree1
{
public:
	struct node * post_create()
	{
		struct node *ptr,*root,*temp;
		string s;
		cout<<"Enter the postfix expression :: ";
		cin>>s;
		stack1 stk;
		int l=s.size();
		for(int i=0;i<l;i++)
		{
			if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] !='/' && s[i]!='^')
			{
				ptr=new node;
				ptr->l=NULL;
				ptr->r=NULL;
				ptr->data=s[i];
				stk.push1(ptr);
				//delete(ptr);
			}
			else
			{
				struct node *p1,*p2;
				p1=stk.pop1();
				p2=stk.pop1();
				temp=new node;
				temp->data=s[i];
				temp->r=p1;
				temp->l=p2;
				stk.push1(temp);
				//delete(ptr);
			}
		}
		root=stk.pop1();
		return root;
	}
	struct node * pre_create()
	{
		struct node *ptr,*root,*temp;
		string s;
		cout<<"Enter the prefix expression :: ";
		cin>>s;
		stack1 stk;
		int l=s.size();
		for(int i=l-1;i>=0;i--)
		{
			if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] !='/' && s[i]!='^')
			{
				ptr=new node;
				ptr->l=NULL;
				ptr->r=NULL;
				ptr->data=s[i];
				stk.push1(ptr);
				//delete(ptr);
			}
			else
			{
				struct node *p1,*p2;
				p1=stk.pop1();
				p2=stk.pop1();
				temp=new node;
				temp->data=s[i];
				temp->r=p1;
				temp->l=p2;
				stk.push1(temp);
				//delete(ptr);
			}
		}
		root=stk.pop1();
		return root;
	}
	void non_pre(struct node *root)
	{
		stack1 stk;
		while(root!=NULL)
		{
			cout<<root->data<<" ";
			stk.push1(root);
			root=root->l;
		}
		while(!stk.isempty())
		{
			root=stk.pop1();
			if(root!=NULL)
			{
				root=root->r;
				while(root!=NULL)
				{
					cout<<root->data<<" ";
					stk.push1(root);
					root=root->l;
				}
			}
		}
	}
	void re_pre(struct node *root)
	{
		if (root == NULL) 
        	return; 
  
   	 	cout << root->data << " "; 
    	re_pre(root->l);

    	re_pre(root->r); 
	}
	void non_post(struct node *root)
	{
		stack2 stk;
		int flag;
		struct node *curr=root,*ptr;
		
		while(curr!=NULL)
		{
			stk.push2(curr,0);
			curr=curr->l;
		}

		while(!stk.isempty())
		{
			curr=stk.top1(&flag);
			if(flag==1)
			{	
				ptr=stk.pop2(&flag);
				cout<<curr->data<<" ";
			}
			else
			{
				curr=stk.top1(&flag);
				ptr=stk.pop2(&flag);
				flag=1;
				stk.push2(curr,1);
				curr=curr->r;
				while(curr!=NULL)
				{
					//curr->flag=0;
					stk.push2(curr,0);
					curr=curr->l;
				}
			}
		
		} 
	cout<<endl;		
		
	}
	void re_post(struct node *root)
	{
		if (root == NULL) 
        	return; 
   	 	re_post(root->l);
    	re_post(root->r);
    	cout << root->data << " "; 
	}
	void non_in(struct node *root)
	{
		stack1 stk;
		while(root!=NULL)
		{
			//cout<<root->data<<" ";
			stk.push1(root);
			root=root->l;
		}
		while(!stk.isempty())
		{
			root=stk.pop1();
			cout<<root->data<<" ";
			if(root!=NULL)
			{
				root=root->r;
				while(root!=NULL)
				{
					//cout<<root->data<<" ";
					stk.push1(root);
					root=root->l;
				}
			}
		}
	}
	void re_in(struct node *root)
	{
		if (root == NULL) 
        	return; 
    	re_in(root->l);
    	cout << root->data << " "; 
    	re_in(root->r); 
	}
};
int main()
{
	tree1 tr;
	int x,j,k=0,flag=0,max=-1;
	struct node *pre_root,*post_root;
	do{
	flag=0;
	cout<<"\nEnter your choice...\n1.Postfix Expression\n2.Prefix Expression\n3.Preorder\n4.Inorder\n5.Postorder\n7.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				post_root = tr.post_create();
				break;
		case 2:
				pre_root = tr.pre_create();
				break;
		case 3:
				cout<<"\t______________NON_RECURSIVE_PREORDER_POSTFIX_______________\n";
				tr.non_pre(post_root);
				cout<<"\n\t______________RECURSIVE_PREORDER_POSTFIX_______________\n";
				tr.re_pre(post_root);
				cout<<"\n\t______________NON_RECURSIVE_PREORDER_PREFIX_______________\n";
				tr.non_pre(pre_root);
				cout<<"\n\t______________RECURSIVE_PREORDER_PREFIX_______________\n";
				tr.re_pre(pre_root);
				break;
		case 4:
				cout<<"\t______________NON_RECURSIVE_INORDER_POSTFIX_______________\n";
				tr.non_in(post_root);
				cout<<"\n\t______________RECURSIVE_INORDER_POSTFIX_______________\n";
				tr.re_in(post_root);
				cout<<"\n\t______________NON_RECURSIVE_INORDER_PREFIX_______________\n";
				tr.non_in(pre_root);
				cout<<"\n\t______________RECURSIVE_INORDER_PREFIX_______________\n";
				tr.re_in(pre_root);
				break;
		case 5:
				cout<<"\t______________NON_RECURSIVE_POSTORDER_POSTFIX_______________\n";
				tr.non_post(post_root);
				cout<<"\n\t______________RECURSIVE_POSTORDER_POSTFIX_______________\n";
				tr.re_post(post_root);
				cout<<"\n\t______________NON_RECURSIVE_POSTORDER_PREFIX_______________\n";
				tr.non_post(pre_root);
				cout<<"\n\t______________RECURSIVE_POSTORDER_PREFIX_______________\n";
				tr.re_post(pre_root);
				break;
		case 7:
				flag=1;
				break;
	}
	}
	while(flag==0);
	return 0;
}


