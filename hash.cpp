#include<bits/stdc++.h>
using namespace std;

struct node 
{
	string name;
	int phone;
	int link;
	int pre;
};
class hash1
{
public:
	void witho()
	{
		int n,flag=0;
		cout<<"Enter the size of hash table :: ";cin>>n;
		struct node *h[n+1];
		for(int i=0;i<=n;i++)
		{
			h[i]=new node;
			h[i]->link=-1;
			h[i]->name="N";
		}
		do
		{
			struct node *temp=new node;
			cout<<"Enter the name :: ";cin>>temp->name;
			cout<<"Enter the phone number :: ";cin>>temp->phone;
			int x= (temp->phone)%n;
			while(h[x]->link != -1)
			{
				x= (x+1)%n;
			}
			cout<<x<<'\n';
			h[x]->name = temp->name;
			h[x]->phone = temp->phone;
			h[x]->link=1;
			cout<<"_._._._._._._._._._._._._._._._._._._._._._._._\n";
		
		for(int i=0;i<n;i++)
		{
			cout<<i<<" -> "<<h[i]->name<<" "<<h[i]->phone<<" "<<h[i]->link<<'\n';
			cout<<"_._._._._._._._._._._._._._._\n";
		}
		cout<<"Do you want to continue press <1> otherwise <0> :: ";cin>>flag;
		}while(flag==1);
		
	}
	void with()
	{
		int n,flag=0,c=0;
		cout<<"Enter the size of hash table :: ";cin>>n;
		struct node *h[n+1];
		for(int i=0;i<=n;i++)
		{
			h[i]=new node;
			h[i]->name="N";
			h[i]->phone = -1;
			h[i]->link = -1;
			h[i]->pre = -1;

		}
		do
		{
			struct node *temp=new node;
			cout<<"Enter the name :: ";cin>>temp->name;
			cout<<"Enter the phone number :: ";cin>>temp->phone;
			int x= (temp->phone)%n;
			if(c==n)
				{cout<<"Hashtable is full\n";}
			else if(h[x]->phone == -1)
			{
				h[x]->name = temp->name;
				h[x]->phone = temp->phone;
			}
				else
				{
					if((h[x]->phone)%n == x)
					{
						while(h[x]->link != -1)
						{
							x=  h[x]->link ;
						}
						int p=x;
						while(h[x]->phone != -1)
						{
							x=  (x+1)%n ;
						}
						h[x]->name = temp->name;
						h[x]->phone = temp->phone;
						h[x]->pre = p;
						h[p]->link	= x;
					}
					else
					{
						int p = x;
						while(h[x]->phone !=-1)
						{
							x = (x+1) %n ;
						}
						h[x]->name = h[p]->name;
						h[x]->phone = h[p]->phone;
						h[h[p]->pre]->link	= x;
						h[x]->link = h[p]->link;
						h[x]->pre = h[p]->pre;

						h[p]->name = temp->name;
						h[p]->phone = temp->phone;
						h[p]->link= -1;
						h[p]->pre=-1;
					}
				}
				cout<<"_._._._._._._._._._._._._._._._._._._._._._._._\n";
		c++;
		for(int i=0;i<n;i++)
			{
				cout<<i<<" -> "<<h[i]->name<<" "<<h[i]->phone<<" "<<h[i]->link<<'\n';
				cout<<"_._._._._._._._._._._._._._._\n";
			}
			cout<<"Do you want to continue press <1> otherwise <0> :: ";cin>>flag;
		}while(flag==1);
	}
};
int main()
{
	hash1 k;	
	int x,flag=0;
	do{
	flag=0;
	cout<<"\n\t_________MENU________\n1.Without Replacement\n2.With Replacement\n3.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				cout<<"\n\t___________WITHOUT_REPLACEMENT____________\n";
				k.witho();
				break;
		case 2:
				cout<<"\n\t___________WITH_REPLACEMENT____________\n";
				k.with();
				break;
		case 3:
				flag=1;
				break;
	}
	}
	while(flag==0);
	return 0;
}