#include<bits/stdc++.h>
using namespace std;

struct graph
{
	int src,dest,wt;
};

struct node3
{
	int data;
	struct node3 *next;
};
class stack1
{
	struct node3 *top;
public:
	stack1()
	{top=NULL;}
	void  push1(int dt)
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
	int pop1()
	{
		if(top==NULL)
		{
			return (-1);
		}
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
class kru
{
	int V,E;
	struct graph d[20];
public:
	void create(int adj[20][20])
	{
		cout<<"Enter the no. of vertices :: ";cin>>V;
		cout<<"Enter the no. of edges :: ";cin>>E;
		cout<<"Enter the SOURCE  DESTINSTION  WEIGHT of the edges \n";
		for(int i=0;i<E;i++)
		{
			cin>>d[i].src>>d[i].dest>>d[i].wt;
			adj[d[i].src][d[i].dest]=d[i].wt;
			adj[d[i].dest][d[i].src]=d[i].wt;
		}
	}
	void display1(int adj[20][20])
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void display(int adj[20][20])
	{
		cout<<"\n\t___________DISPLAY_ADJACENCY_MATRIX__________\n";
		display1(adj);
		cout<<"\n\t___________DISPLAY_DFS___________\n";
		stack1 stk;
		int a=d[0].src,b;
		int visit[100]={};
		stk.push1(a);
		cout<<a<<" ";
		visit[a]=1;
		while(!stk.isempty())
		{
			a=stk.pop1();
			if(visit[a]==0)
			{
				cout<<a<<" ";visit[a]=1;
			}
			for(int i=0;i<V;i++)
			{
				if(adj[a][i]>0)
				{
					b=i;
					if(visit[b]==0)
					{
						stk.push1(b);
					}
				}
			}
		}
		cout<<endl;
	}
	void md(int adj[20][20])
	{
		int cost[20][20],c=0;
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(adj[i][j]==0)
					cost[i][j]=100000;
				else
					cost[i][j]=adj[i][j];
			}
		}
		int visit[100]={},srcv=0,d=100000;
		int dist[100],pred[20]={};
		for(int i=0;i<100;i++)
			dist[i]=100000;
		dist[srcv]=0;
		while(c!=V)
		{
			d=100000;
			visit[srcv]=1;c++;
			for(int i=0;i<V;i++)
			{
				if(dist[srcv]+cost[srcv][i] < dist[i])
				{dist[i]=min(dist[i],dist[srcv]+cost[srcv][i]);
				pred[i]=srcv;}
			}
			for(int i=0;i<V;i++)
			{
				if(dist[i] < d && visit[i]==0)
				{
					d=dist[i];
					srcv=i;
				}
			}
		}
		for(int i=0;i<V;i++)
		{
			cout<<dist[i]<<" ";
		}
		cout<<endl;
		srcv=0;
		int j;
		for(int i=0;i<V;i++)
		{
			if(i!=srcv)
			{
				cout<<"\nDistance of node "<<i<<" = "<<dist[i];
				cout<<"\n path = "<<i;
				j=i;
				do{
					j=pred[j];
					cout<<"<- "<<j;
				}while(j!=srcv);
			}
		}
	}
};
int main()
{
	
	int x,flag=0;
	int adj[20][20]={};
	kru k;
	do{
	flag=0;
	cout<<"\n\t_________MENU________\n1.Create Graph\n2.Display\n3.Minimum Distance\n4.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				cout<<"\n\t___________CREATION____________\n";
				k.create(adj);
				break;
		case 2:

				k.display(adj);
				break;
		case 3:
				cout<<"\n\t___________MINIMUM_DISTANCE____________\n";
				k.md(adj);
				break;
		case 4:
				flag=1;
				break;
	}
	}
	while(flag==0);
	return 0;
}