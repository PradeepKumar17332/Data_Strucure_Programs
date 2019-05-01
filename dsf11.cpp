#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>

using namespace std;

class student
{
  string name,dob;
  float m1,m2;
  int rollno;

  public :

  void input()
  {
    cout<<"\nEnter the Roll No. : ";
    cin>>rollno;
    cout<<"\nEnter the Name : ";
    cin>>name;
    cout<<"\nEnter the DOB : ";
    cin>>dob;
    cout<<"\nEnter the Marks 1 : ";
    cin>>m1;
    cout<<"\nEnter the Marks 2 : ";
    cin>>m2;
  }

  void modify()
  {
    cout<<"\nStudent Roll No. : "<<rollno;
    cout<<"\n\nEnter the Name : ";
    cin>>name;
    cout<<"\nEnter the DOB : ";
    cin>>dob;
    cout<<"\nEnter the Marks 1 : ";
    cin>>m1;
    cout<<"\nEnter the Marks 2 : ";
    cin>>m2;
  }

  void display()
  {
    cout<<"\n  Roll No. : "<<rollno;
    cout<<"\n  Name : "<<name;
    cout<<"\n  DOB : "<<dob;
    cout<<"\n  Marks 1 : "<<m1;
    cout<<"\n  Marks 2 : "<<m2;
  }

  void report()
  {
    printf("%-15d%-18s%-18s%-8.2f%-8.2f\n",rollno,name.c_str(),dob.c_str(),m1,m2);
  }

  int roll()
  { return rollno;  }

  friend fstream & operator >> (fstream &in,student &a);
  friend fstream & operator << (fstream &out,student &a);

};

fstream & operator >> (fstream &in,student &a)
{
  in>>a.name>>a.dob>>a.m1>>a.m2>>a.rollno;

  return in;
}

fstream & operator << (fstream &out,student &a)
{
  out<<" "<<a.name<<" "<<a.dob<<" "<<a.m1<<" "<<a.m2<<" "<<a.rollno;

  return out;
}

void create_student()
{
  fstream fp;
  student st;
	char ch;
  cout<<"\n\n";
	cout<<"\n\n\tCREATE STUDENT RECORD... ";
	fp.open("student.txt",ios::trunc|ios::out);
	do
	{
		st.input();
    fp<<st;
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void insert_student()
{
  fstream fp;
  student st;
	char ch;
  cout<<"\n\n";
	cout<<"\n\n\tINSERT STUDENT RECORD... ";
	fp.open("student.txt",ios::out|ios::app);
	do
	{
		st.input();
    fp<<st;
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void display_student()
{
  fstream fp;
  student st;
  int n;
	int found=0;
	cout<<"\n\n";
	cout<<"\n\n\tSEARCH STUDENT RECORD... ";
	cout<<"\n\n\tEnter The Roll No. of The student : ";
	cin>>n;
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.txt",ios::in);
	while(!fp.eof())
	{
    fp>>st;
		if(st.roll()==n)
		{
			st.display();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nStudent does not exist";
	 ;
}

void modify_student()
{
  fstream fp,fp2;
  student st;
	int n;
	int found=0;
	cout<<"\n\n";;
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The Roll No. of The student : ";
	cin>>n;
	fp.open("student.txt",ios::in|ios::out);
  fp2.open("temp.txt",ios::out);
	while(fp.eof()==0 && found==0)
	{
    fp>>st;
		if(st.roll()==n)
		{
			st.display();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify();
      fp2<<st;
			cout<<"\n\n\t Record Updated";
			found=1;
		}
    else { fp2<<st;}
	}

	fp.close();
  fp2.close();
  remove("student.txt");
	rename("temp.txt","student.txt");
	if(found==0)
		cout<<"\n\n Record Not Found ";
}


void delete_student()
{
  fstream fp;
  student st;
	int n;
	int flag=0;
	cout<<"\n\n";
	cout<<"\n\n\n\tDELETE STUDENT...";
	cout<<"\n\nEnter The Roll No. of the Student You Want To Delete : ";
	cin>>n;
	fp.open("student.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(!fp.eof())
	{
    fp>>st;
    if(st.roll()!=n)
      fp2<<st;
		else
			flag=1;
	}

	fp2.close();
	fp.close();
	remove("student.txt");
	rename("Temp.txt","student.txt");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ..";
	else
		cout<<"\n\nRecord not found";

}

void display_all()
{
  fstream fp;
  student st;
	cout<<"\n\n";
	fp.open("student.txt",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		return;
	}


	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"******************************************************************\n";
  printf("%-15s%-18s%-18s%-8s%-8s\n","Roll No.","Name","DOB","M1","M2");
	cout<<"******************************************************************\n";

	while(!fp.eof())
	{
    fp>>st;
		st.report();
	}

	fp.close();

}

int menu()
{
  int o=0,o1;

  printf("\n***************************\n");

  printf("\n1.Create Database");
  printf("\n2.Display Database");
  printf("\n3.Display Record");
  printf("\n4.Insert Record");
  printf("\n5.Delete Record");
  printf("\n6.Modify Record");
  printf("\n0.Exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&o1);

  if(o1==0)  exit(0);
  else if(o1>-1 && o1<7)  {}
  else printf("\nERROR...!!!");

  return o1;
}


int main(int argc, char const *argv[])
{

  int o=4;

  while(o!=0)
  {
    o=menu();
    switch(o)
    {
      case 1 :  create_student();
                break;
      case 2 :  display_all();
                break;
      case 3 :  display_student();
                break;
      case 4 :  insert_student();
                break;
      case 5 :  delete_student();
                break;
      case 6 :  modify_student();
                break;
    }
  }


  return 0;
}
