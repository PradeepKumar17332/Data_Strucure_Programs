#include<bits/stdc++.h>
using namespace std;
struct node
{
	int user_id;
	string name;
	int num;
	int dd,mm,yy;
};
struct node2
{
	struct node data;
	int id;
	struct node2 *next;
};
struct node3
{
	struct node data;
	struct node3 *next;
};
class stack1
{
	struct node3 *top;
public:
	stack1()
	{top=NULL;}
	void  push1(struct node dt)
	{
		struct node3 *ptr;
		ptr=new node3;
		ptr->data=dt;
		if(top!=NULL)
		{
			ptr->next=top;
			top=ptr;
		}
		else
		{top=ptr;}
	}
	struct node pop1()
	{
		// if(top==NULL)
		// {
		// 	return ;
		// }
		struct node3 *ptr=top;
		top=top->next;
		return (ptr->data);
		
	}
	bool isempty()
	{
		if(top==NULL)
			return true;
		else
			return false;
	}
};
class que
{
	struct node3 *front,*rear;
public:
	que()
	{
		front=NULL;rear=NULL;
	}
	void enque(struct node dt)
	{
		struct node3 *ptr;
		ptr=new node3;
		ptr->data=dt;
		//ptr->id=i;
		ptr->next=NULL;
		if(front==NULL && rear==NULL)
		{
			front=ptr;rear=ptr;
		}
		else
		{
			rear->next=ptr;
			rear=ptr;
		}
	}
	struct node deque()
	{
		struct node ptr;
		if(front==NULL && rear==NULL)
		{
			cout<<"Queue is Empty\n";return ptr;
		}
		else if(front==rear)
		{
			ptr=front->data;
			front=NULL;rear=NULL;
			return ptr;
		}
		else
		{
			ptr=front->data;
			front=front->next;
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
};
class face
{
	struct node2 *g[30];
	struct node d[20];
	int no=0;
public:
	void database()
	{
		cout<<"Enter the number of the users :: ";cin>>no;
		for(int i=0;i<no;i++)
		{
			
			cout<<"Enter the name of user :: ";cin>>d[i].name;
			cout<<"The USER ID of user "<<d[i].name<<" :: "<<i<<endl;
			d[i].user_id=i;
			cout<<"Enter the no. of comments :: ";cin>>d[i].num;
			cout<<"Enter the date of birth ( dd  mm  yy) :: ";cin>>d[i].dd;cin>>d[i].mm;cin>>d[i].yy;
			cout<<"=========================================================\n";
		}
	}
	void adj()
	{
		int n;
		struct node2 *temp;
		for(int i=0;i<no;i++)
		{
			cout<<"For USER ID "<<i<<" enter the number of friends :: ";cin>>n;
			g[i]=NULL;
			for(int j=0;j<n;j++)
			{
				struct node2 *t;
				t= new node2;
				cout<<"Enter the USER ID of friend :: ";cin>>t->id;
				cout<<"-----------------------------------------\n";
				
				t->data=d[t->id];
				t->next= NULL;
				if(g[i]==NULL)
				{
					g[i]= t;
					temp= g[i]; 
				}
				else temp->next=t,temp=temp->next;
			}
		}
	}
	void display()
	{
		que q;
		struct node ptr,max_fri,max_com,min_com;
		struct node2 *temp;
		int visit[100]={};
		int maxfr[200]={};
		int c=0,maxf=-1;
		q.enque(d[0]);
		visit[d[0].user_id]=1;
		cout<<"The name of user :: "<<d[0].name<<endl;
		cout<<"The USER ID of user "<<d[0].name<<" :: "<<d[0].user_id<<endl;
		cout<<"The no. of comments :: "<<d[0].num<<endl;
		cout<<"The date of birth ( dd  mm  yy) :: "<<d[0].dd<<"/"<<d[0].mm<<"/"<<d[0].yy<<endl;
		cout<<"=========================================================\n";
		int max=d[0].num,min=d[0].num;
		max_com=d[0];min_com=d[0];
		while(!q.qisempty())
		{
			c=0;
			ptr=q.deque();
			temp=g[ptr.user_id];
			while(temp!=NULL)
			{
				c++;
				if(visit[temp->data.user_id]==0)
				{
					cout<<"The name of user :: "<<temp->data.name<<endl;
					cout<<"The USER ID of user "<<temp->data.name<<" :: "<<temp->data.user_id<<endl;
					cout<<"The no. of comments :: "<<temp->data.num<<endl;
					cout<<"The date of birth ( dd  mm  yy) :: "<<temp->data.dd<<"/"<<temp->data.mm<<"/"<<temp->data.yy<<endl;
					cout<<"=========================================================\n";
					visit[temp->data.user_id]=1;
					q.enque(temp->data);
				}
				temp=temp->next;
			}
			maxfr[ptr.user_id]=c;
			if(ptr.num > max_com.num)
				max_com=ptr;
			if(ptr.num < min_com.num)
				min_com=ptr;
			if(c>maxf)
			{
				maxf=c;
				max_fri=ptr;
			}
			
		}

		cout<<"\t_____________USER_HAVING_MAX_FRIENDS________________\n";
		for(int i=0;i<no;i++)
		{
		if(maxf==maxfr[d[i].user_id])
		{
			cout<<"The name of user :: "<<d[i].name<<endl;
			cout<<"The USER ID of user "<<d[i].name<<" :: "<<d[i].user_id<<endl;
			cout<<"The no. of comments :: "<<d[i].num<<endl;
			cout<<"The date of birth ( dd  mm  yy) :: "<<d[i].dd<<"/"<<d[i].mm<<"/"<<d[i].yy<<endl;
			cout<<"=========================================================\n";}
		}
		

		cout<<"\n\t_____________USER_HAVING_MAX_COMMENTS________________\n";
		for(int i=0;i<no;i++)
		{
			if(max_com.num==d[i].num)
			{
				cout<<"The name of user :: "<<d[i].name<<endl;
			cout<<"The USER ID of user "<<d[i].name<<" :: "<<d[i].user_id<<endl;
			cout<<"The no. of comments :: "<<d[i].num<<endl;
			cout<<"The date of birth ( dd  mm  yy) :: "<<d[i].dd<<"/"<<d[i].mm<<"/"<<d[i].yy<<endl;
			cout<<"=========================================================\n";}
			}
		
		cout<<"\n\t_____________USER_HAVING_MIN_COMMENTS________________\n";
		for(int i=0;i<no;i++)
		{
			if(min_com.num==d[i].num)
			{
				cout<<"The name of user :: "<<d[i].name<<endl;
			cout<<"The USER ID of user "<<d[i].name<<" :: "<<d[i].user_id<<endl;
			cout<<"The no. of comments :: "<<d[i].num<<endl;
			cout<<"The date of birth ( dd  mm  yy) :: "<<d[i].dd<<"/"<<d[i].mm<<"/"<<d[i].yy<<endl;
			cout<<"=========================================================\n";}
			
		}

		cout<<endl;
	}
	void display2()
	{
		int visit[100]={};
		struct node temp;
		struct node2 *ptr;
		stack1 stk;
		stk.push1(d[0]);
		visit[d[0].user_id]=1;
		cout<<"The name of user :: "<<d[0].name<<endl;
		cout<<"The USER ID of user "<<d[0].name<<" :: "<<d[0].user_id<<endl;
		cout<<"The no. of comments :: "<<d[0].num<<endl;
		cout<<"The date of birth ( dd  mm  yy) :: "<<d[0].dd<<"/"<<d[0].mm<<"/"<<d[0].yy<<endl;
		cout<<"=========================================================\n";
		while(!stk.isempty())
		{
			temp=stk.pop1();
			if(visit[temp.user_id]==0)
			{
				cout<<"The name of user :: "<<temp.name<<endl;
				cout<<"The USER ID of user "<<temp.name<<" :: "<<temp.user_id<<endl;
				cout<<"The no. of comments :: "<<temp.num<<endl;
				cout<<"The date of birth ( dd  mm  yy) :: "<<temp.dd<<"/"<<temp.mm<<"/"<<temp.yy<<endl;
				cout<<"=========================================================\n";
				visit[temp.user_id]=1;
			}
			ptr=g[temp.user_id];
			while(ptr!=NULL)
			{
				temp=ptr->data;
				if(visit[temp.user_id]==0)
				{
					stk.push1(temp);
				}
				ptr=ptr->next;
			}
		}
	}
	void dmonth()
	{
		int mon;
		int c=0;
		cout<<"Enter the month number :: ";
		cin>>mon;
		for(int i=0;i<no;i++)
		{
			if(d[i].mm==mon){
			c++;
			cout<<"The name of user :: "<<d[i].name<<endl;
			cout<<"The USER ID of user "<<d[i].name<<" :: "<<d[i].user_id<<endl;
			cout<<"The no. of comments :: "<<d[i].num<<endl;
			cout<<"The date of birth ( dd  mm  yy) :: "<<d[i].dd<<"/"<<d[i].mm<<"/"<<d[i].yy<<endl;
			cout<<"=========================================================\n";}		
		}
		if(c==0)
			cout<<"For this month,no data is present\n";
	}
};

int main()
{
	
	int x,flag=0;
	face fc;
	do{
	flag=0;
	cout<<"\n\t_________MENU________\n1.Insert Database\n2.Display using bfs\n3.Display using dfs\n4.Display acc. to month of birthday\n5.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				cout<<"\n\t___________CREATE_DATABASE________________\n";
				fc.database();
				cout<<"\n\t___________CREATION_OF_ADJACENT_MATRIX________________\n";
				fc.adj();
				break;
		case 2:
				cout<<"\t______________DISPLAY_USING_BFS______________\n";
				fc.display();
				break;
		case 3:
				cout<<"\t______________DISPLAY_USING_DFS______________\n";
				fc.display2();
				break;
		case 4:
				cout<<"\t___________DISPLAY_ACC_TO_MONTH_________________\n";
				fc.dmonth();
				break;
		case 5:
				flag=1;
				break;
	}
	}
	while(flag==0);
	return 0;
}