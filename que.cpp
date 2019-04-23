#include<bits/stdc++.h>
using namespace std;

struct node
{
	string name;
	int regno;
	int pr;
	struct node *link;
};

class que
{
	struct node *f,*r;
	public:
	que()
	{
		f=NULL;r=NULL;
	}
	void enque()
	{
		string s;
		struct node *ptr;
		ptr=new node;
		cout<<"Enter the NAME of patient"<<endl;
		cin>>s;
		ptr->name=s;
		cout<<"Enter the Regno. of the patient"<<endl;
		cin>>ptr->regno;
		cout<<"Enter the Condition of patient \n=>for Serious Condition press <2>\n=>for Medium Condition press <1>\n=>for General Condtion press <0>"<<endl;
		cin>>ptr->pr;
		ptr->link=NULL;
		if(f==NULL && r==NULL)
		{
			f=ptr;r=ptr;
		}
		else
		{
			
			struct node *temp=f,*pre=f,*f1=f;
			while((temp->pr > ptr->pr))
			{
				pre=temp;
				temp=temp->link;
				if(temp==NULL)
				{break;}
			}
			if(temp==NULL)
			{
				r->link=ptr;
				r=ptr;
				
			}
			else
			{
				if(f==temp)
				{
					ptr->link=f;
					f=ptr;
					
				}
				else
				{
					ptr->link=temp;
					pre->link=ptr;
					f=f1;
				}
				
			}
		}
	}
	void deque()
	{
		if(f==NULL && r==NULL)
		{
			cout<<"Queue is Empty\n";return;
		}
		else if(f==r)
		{
			cout<<"------------------------------------------------\n";
			cout<<"The name of th patient is ::"<<f->name<<endl;
			cout<<"The regno of the patient is ::"<<f->regno<<endl;
			cout<<"The Condition of the patient is ::"<<f->pr<<endl;
			cout<<"------------------------------------------------\n";
			f=NULL;r=NULL;
		}
		else
		{
			cout<<"------------------------------------------------\n";
			cout<<"The name of th patient is ::"<<f->name<<endl;
			cout<<"The regno of the patient is ::"<<f->regno<<endl;
			cout<<"The Condition of the patient is ::"<<f->pr<<endl;
			cout<<"------------------------------------------------\n";
			f=f->link;
		}
	}
	void display_all()
	{
		struct node *temp=f;
		while(f!=NULL)
		{
			cout<<"------------------------------------------------\n";
			cout<<"The name of th patient is ::"<<f->name<<endl;
			cout<<"The regno of the patient is ::"<<f->regno<<endl;
			cout<<"The Condition of the patient is ::"<<f->pr<<endl;
			cout<<"------------------------------------------------\n";
			f=f->link;
		}
		f=temp;
	}
	void display_specific()
	{
		cout<<"Enter the condition for which you want to display the record :: ";
		int w;
		cin>>w;
		struct node *temp=f;
		while(f!=NULL)
		{
			if(f->pr==w)
			{cout<<"------------------------------------------------\n";
			cout<<"The name of th patient is ::"<<f->name<<endl;
			cout<<"The regno of the patient is ::"<<f->regno<<endl;
			cout<<"The Condition of the patient is ::"<<f->pr<<endl;
			cout<<"------------------------------------------------\n";}
			f=f->link;
		}
		f=temp;
	}
};
int main()
{
	que q;
	int x,j,k=0,flag=0;
	
	do{
	flag=0;
	cout<<"Enter your choice...\n1.New Entery\n2.Delete Entery\n3.Display All\n4.Display specific\n5.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				q.enque();
				break;
		case 2:
				q.deque();
				break;
		case 3:
				q.display_all();
				break;
		case 4:
				q.display_specific();
				break;
		case 5:flag=1;break;
	}
	}
	while(flag==0);
	return 0;
}

