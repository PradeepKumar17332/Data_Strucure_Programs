#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *l;
	struct node *r;
};
struct node1
{
	struct node *r;
	struct node1 *link;
};
class btree
{
	struct node1 *top,*front,*rear;
	public:
	btree()
	{
		top=NULL;front=NULL;rear=NULL;
	}
	struct node *insert(struct node *root)
	{
		struct node *ptr,*temp=root,*pre;
		ptr=new node;
		cout<<"Enter the value of node :: ";
		cin>>ptr->data;
		ptr->l=NULL;
		ptr->r=NULL;
		if(root==NULL)
		{
			root=ptr;
			return root;
		}
		while(temp!=NULL)
		{
			pre=temp;
			if(temp->data > ptr->data)
			{
				temp=temp->l;
			}
			else
				temp=temp->r;
		}
		if(pre->data > ptr->data)
			pre->l=ptr;
		else
			pre->r=ptr;
		return (root);
	}
	struct node* image(struct node *root)
	{
		struct node *croot;
		if(root==NULL)
		{
			return NULL;
		}
		croot=new node;
		croot->data=root->data;
		croot->r=image(root->l);
		croot->l=image(root->r);
		return (croot);
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
	void display(struct node *root)
	{
		btree stk;
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
	void search(struct node *root)
	{
		struct node *temp=root;
		cout<<"Enter the number you want to search :: ";
		int n;
		cin>>n;
		while(temp!=NULL)
		{
			if(temp->data==n)
			{
				cout<<"Number found!! \n";
				return;
			}
			if(temp->data > n)
				temp=temp->l;
			else
				temp=temp->r;
		}
		cout<<"Number not found !! \n";
	}
	struct node * delete1(struct node *root)
	{
		struct node *temp=root,*pre,*ptr;
		cout<<"Enter the number you want to delete :: ";
		int n;
		cin>>n;
		while(temp!=NULL)
		{

			if(temp->data==n)
			{
				if(temp->l==NULL && temp->r==NULL)
				{
					if(pre->data > n)
						pre->l=NULL;
					else 
						pre->r=NULL;
					delete temp;
				}
				else if(temp->l==NULL && temp->r!=NULL)
				{
					ptr=temp->r;
					if(temp==root)
						root=ptr;
					else if(pre->data > n)
						pre->l=ptr;
					else
						pre->r=ptr;
				}
				else if(temp->l!=NULL && temp->r==NULL)
				{
					ptr=temp->l;
					if(temp==root)
						root=ptr;
					else if(pre->data > n)
						pre->l=ptr;
					else
						pre->r=ptr;
				}
				else if(temp->l!=NULL && temp->r!=NULL)
				{
					struct node *succParent = temp->r;       
        			struct node *succ = temp->r; 
        			while (succ->l != NULL) 
        			{ 
            			succParent = succ; 
            			succ = succ->l; 
        			}
        			if(succParent == succ)
        			{
        				temp->r=succ->r;
        			}
        			else
        			{succParent->l = succ->r;}
        			temp->data = succ->data; 
        			delete succ;
				}
				return root;
			}
			if(temp->data > n)
			{pre=temp;temp=temp->l;}
			else
			{pre=temp;temp=temp->r;}
		}
		cout<<"Number not found !! \n";
		return (root);
	}
	void enque(struct node *root)
	{
		struct node1 *ptr;
		ptr=new node1;
		ptr->r=root;
		ptr->link=NULL;
		if(front==NULL && rear==NULL)
		{
			front=ptr;rear=ptr;
		}
		else
		{
			rear->link=ptr;
			rear=ptr;
		}
	}
	struct node * deque()
	{
		struct node *ptr=NULL;
		if(front==NULL && rear==NULL)
		{
			cout<<"Queue is Empty\n";return ptr;
		}
		else if(front==rear)
		{
			ptr=front->r;
			front=NULL;rear=NULL;
			return ptr;
		}
		else
		{
			ptr=front->r;
			front=front->link;
			return ptr;
		}
	}
	bool qisempty()
	{
		if(front==NULL)
			return true;
		else
			return false;
	}
	void level(struct node *root)
	{
		int visit[100]={};
		struct node *ptr;
		enque(root);
		visit[root->data]=1;
		cout<<root->data<<" ";
		while(!qisempty())
		{
			ptr=deque();
			if(ptr->l!=NULL)
			{
				if(visit[ptr->l->data]==0)
				{enque(ptr->l);
				visit[ptr->l->data]=1;
				cout<<ptr->l->data<<" ";}
			}
			if(ptr->r!=NULL)
			{	
				if(visit[ptr->r->data]==0)
				{enque(ptr->r);
				visit[ptr->r->data]=1;
				cout<<ptr->r->data<<" ";}
			}
		}
		cout<<"\n";
	}
};
int main()
{
	btree tr;
	int x,j,k=0,flag=0,max=-1;
	struct node *root=NULL,*croot;
	do{
	flag=0;
	cout<<"\nEnter your choice...\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Mirror Image\n6.Display Level Wise\n7.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				root=tr.insert(root);
				break;
		case 2:
				cout<<"\t______________DISPLAY_PREORDER_______________\n";
				tr.display(root);
				break;
		case 3:
				cout<<"\t______________DELETION______________\n";
				root=tr.delete1(root);
				break;
		case 4:
				cout<<"\t______________SEARCH_______________\n";
				tr.search(root);
				break;
		case 5:
				cout<<"\t______________MIRROR_IMAGE______________\n";
				croot=tr.image(root);
				tr.display(croot);
				break;
		case 6:
				cout<<"\t___________DISPLAY_LEVEL_WISE_____________\n";
				tr.level(root);
				break;
		case 7:
				flag=1;
				break;
	}
	}
	while(flag==0);
	return 0;
}