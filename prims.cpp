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
	//int adj[20][20]={};
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
	// void display2()
	// {
	// 	for(int i=0;i<E;i++)
	// 	{
	// 		cout<<d[i].src<<" "<<d[i].dest<<" "<<d[i].wt<<endl;
	// 	}
	// }
	void mst(int adj[20][20])
	{
		int nadj[20][20]={};
		int cost[20][20];
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
		int visit[100]={};
		int srcv=0,d=100000;
		int dist[100];
		for(int i=0;i<100;i++)
			dist[i]=100000;
		int dist_f[100]={},c=0;
		dist[srcv]=0;dist_f[srcv]=0;
		int ts;
		while(c!=V)
		{
			d=100000;
			visit[srcv]=1;c++;
			for(int i=0;i<V;i++)
			{
				if(visit[i]==0 && dist[i] > cost[srcv][i])
				{
					
					dist[i]=cost[srcv][i];
					dist_f[i]=srcv;
					// nadj[srcv][i]=cost[srcv][i];
					// nadj[i][srcv]=cost[srcv][i];
				}
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
		for(int i=0;i<V;i++)
		{
			cout<<dist_f[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<V;i++)
		{
			nadj[dist_f[i]][i]=dist[i];
			nadj[i][dist_f[i]]=dist[i];
		}
		display(nadj);
		cout<<"\nTotal cost of MST :: ";
		int total=0;
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(i<=j)
					total+=(nadj[i][j]);
			}
		}
		cout<<total<<endl;
	}

};
int main()
{
	
	int x,flag=0;
	int adj[20][20]={};
	kru k;
	do{
	flag=0;
	cout<<"\n\t_________MENU________\n1.Create Graph\n2.Display\n3.MST\n4.EXIT\n";
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
				cout<<"\n\t___________CREATION_OF_MST____________\n";
				k.mst(adj);
				break;
		case 4:
				flag=1;
				break;
	}
	}
	while(flag==0);
	return 0;
}
