#include<bits/stdc++.h>
using namespace std;
template<class T>
class stack1
{
	struct node
	{
	T data;
	struct node *link;
	};
	struct node *top;
	public:
	stack1()
	{
		top=NULL;
	}
	void push(T value)
	{
		struct node *ptr;
		ptr=new node;
		ptr->data=value;
		ptr->link=NULL;
		if(top!=NULL)
		{
			ptr->link=top;
			top=ptr;
		}
		else
		{top=ptr;}
		
	}
	T pop()
	{
		struct node *temp;
		temp=top;
		if(top==NULL)
		{return '.';}
		else
		{
		top=top->link;
		if(temp->data!='(')
		{//cout << temp->data;
		return temp->data;}
		}
		delete temp;
		
	}	
	
	bool isempty()
	{
		if(top==NULL)
			return true;
		else
			return false;
	}
	char top1()
	{
	      //  if(top != NULL)
		return top->data;
		//return '$';
	}
	
	
};
int pre(char a)
{
	char oper[7]={')','(','+','-','*','/','^'};
		for(int i=0;i<7;i++)
		{
			if(oper[i]==a)
				return i/2;
		}
}
void evapos(char s[],int k)
{
	int ia,ib,w;
	stack1<int> st;
	//char ans1,ans;
	
	cout<<"Enter the value in given order\n";
	
	for(int i=0;i<k;i++)
	{
		if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] !='/' && s[i]!='^' && s[i]!=40 && s[i]!=41)
		{ 
			
			cout<<"Enter the value of "<<s[i]<<" ::";
			cin>>w;
			st.push(w);
		}
		else
		{	
			ia=st.pop();ib=st.pop();
			
			//cout<<ia<<" "<<ib<<"\n";
			if(s[i]=='+')
				w=ia+ib;
			else if(s[i]=='-')
				w=ib-ia;
			else if(s[i]=='*')
				w=ia*ib;
			else if(s[i]=='/')
				w=ib/ia;
			else if(s[i]=='^')
				w=pow(ib,ia);
			st.push(w);
			
		}
	}
	cout<<st.pop()<<endl;
}
void evapref(char s[],int k)
{
	int ia,ib,w;
	stack1<int> st;
	char ans1,ans;
	
	cout<<"Enter the value in given order\n";
	
	for(int i=k-1;i>=0;i--)
	{
		if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^' && s[i]!=40 && s[i]!=41)
		{
			
			cout<<"Enter the value of "<<s[i]<<" ::";
			cin>>w;
			st.push(w);
		}
		else
		{	
			ia=st.pop();ib=st.pop();
			
			//cout<<ia<<" "<<ib<<"\n";
			if(s[i]=='+')
				w=ia+ib;
			else if(s[i]=='-')
				w=ia-ib;
			else if(s[i]=='*')
				w=ia*ib;
			else if(s[i]=='/')
				w=ia/ib;
			else if(s[i]=='^')
				w=pow(ia,ib);
			st.push(w);
			
		}
	}
	cout<<st.pop()<<endl;
}
void postf(string s,int q)
{
				int l=s.size(),k=0,j,op=0,mm=0;
				stack1<char> stk;
				char t[l],a,pref[l];
				for(int i=0;i<l;i++)
				{
					if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='^' && s[i]!=40 && s[i]!=41)
					{
						//cout<<s[i];
						t[k++]=s[i];
						op++;
					}
					else if(stk.isempty())
						stk.push(s[i]);
					
					else 
					{
					if(s[i]=='(')
					{stk.push(s[i]);}
					else if(s[i]==')')
					{
						while(stk.top1()!='(')
						{
							a=stk.pop();
							if(a!='.')
							t[k++]=a;
						}
						a=stk.pop();
					}
					else{
					while(!stk.isempty() && pre(s[i])<= pre(stk.top1()))
					{
						a=stk.pop();
						if(a!='.')
						t[k++]=a;
					}
					stk.push(s[i]);
					}
					}
				}
				while(!(stk.isempty()))
				{
					a=stk.pop();
					if(a!='.')
					t[k++]=a;
				}
				if(q==0)
				{
				cout<<endl<<t<<endl;
				evapos(t,k);	
				}
				if(q==1)
				{
					
					for(int i=k-1;i>=0;i--)
					{cout<<t[i];pref[mm++]=t[i];}
					cout<<endl;
					evapref(pref,k);
					cout<<endl;
				}
				//cout<<"last\n";
}
int main()
{
	string s;
	
	cout<<"Enter the equation==";
	cin>>s;
	int l=s.size(),x,j;
	int k=0,flag=0;
	char t[l];
	do{
	flag=0;
	
	cout<<"Enter your choice...\n1.INFIX\n2.POSTFIX\n3.PREFIX\n4.EXIT\n";
	cin>>x;
	switch(x)
	{
		case 1:
				cout<<"The infix of the equation is ::"<<s<<endl;
				break;
		case 2:
				postf(s,0);
				break;
		case 3:
				j=0;
				for(int i=l-1;i>=0;i--)
				{
					if(s[i]=='(')
						t[j]=')';
					else if(s[i]==')')
						t[j]='(';
					else
						t[j]=s[i];
					j++;
					//cout<<t[j];
				}
				//cout<<t<<"rev\n";
				postf(t,1);
				break;
		case 4:flag=1;break;
	}
	}
	while(flag==0);
	return 0;
}