//============================================================================
// Name        : pinnacle.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<cstdio>
using namespace std;
class node
{
public:
	string name;
	int id;
	node *next;
};
class Pinnacle
{
	string str;
	int prn;
	node *head;
	int count;

public:
		Pinnacle()
		{
			head=NULL;
			count=0;
		}
		node *gethead()
		{
			return head;
		}
		void addnew(int choice)
		{
			count++;
			int n,flag;
			node *newptr,*s;
			cout<<"\nEnter PRN:";
			cin>>prn;
			cout<<"\nEnter name:";
			cin>>str;
			newptr=new node;
			newptr->id=prn;
			newptr->name=str;
			newptr->next=NULL;
			int found=traverse(newptr);
			if(!head)
			head=newptr;

			else if(!found)
			{
				if(choice==3)
				{
					s=head;
					while(s->next)
						s=s->next;
					s->next=newptr;
				}
				if(choice==1)
				{
					node *oldhead=head;
					head=newptr;
					newptr->next=oldhead;
				}
				if(choice==2)
				{
					flag=0;
					cout<<"\nAfter which member you want to insert:";
					cin>>n;
					s=head;
					while(s)
					{
						if(s->id==n)
						{
							flag=1;
							newptr->next=s->next;
							s->next=newptr;
							cout<<"\nInserted";
							break;
						}
						s=s->next;
					}
					if(!flag)
					{
						cout<<"\nMember not found";
					}
				}
			}
			else
				cout<<"\nPRN already exists";

		}
		int traverse(node *c)
		{
			node *s=head;
			while(s)
			{
				if(s->id==c->id)
				{
					return 1;
				}
			}
			return 0;

		}
		void display()
		{
			if(!head)
			{
				cout<<"\nEmpty";
			}
			else
			{
				node *s;
				s=head;
				while(s->next)
				{
					cout<<"PRN:"<<s->id<<" "<<"Name:"<<s->name<<"\n";
					s=s->next;
				}
				cout<<"PRN:"<<s->id<<" "<<"Name:"<<s->name<<"\n";
			}
		}
		void delete_node(int choice)
		{
			node *s,*temp,*del;
			int a;
			if(!head)
			{
				cout<<"\nEmpty list";
			}
			else
			{
				if(choice==1)
				{
					del=head;
					head=head->next;
					delete del;
				}
				if(choice==2)
				{
					int flag=0;
					cout<<"\nEnter PRN of member:";
					cin>>a;
					s=head;
					temp=s;
					while(s)
					{
						if(s->id==a)
						{
							flag=1;
							temp->next=s->next;
						}
						temp=s;
						s=s->next;
					}
					if(flag)
					{
						cout<<"\nDeleted";
					}
					else
						cout<<"\nNot found";
				}
				if(choice==3)
				{
					s=head;
					while(s->next)
					{
						temp=s;
						s=s->next;
					}
					temp->next=NULL;
					delete s;
				}
			}
		}
		void get_count()
		{
			cout<<"\nNumber of members:"<<count;
		}
		/*void reverse()
		{
			node *s,*temp,*previous;
			if(!head)
			{
				cout<<"\nEmpty";
			}
			else
			{
				s=head;
				previous=NULL;
				while(s->next)
				{
					temp=s->next;
					s->next=previous;
					previous=s;
					s=temp;
				}
				s->next=previous;
				head=s;
				display();
			}
		}*/
		void reverse(node *h)
		{
			if(h==NULL)
			{
				return;
			}
			else
			{
				reverse(h->next);
				cout<<"PRN:"<<h->id<<"  Name:"<<h->name<<endl;
			}
		}
		void concatenate(Pinnacle o1,Pinnacle o2)
		{
			node *s;
			count=o1.count+o2.count;
			if((o1.head!=NULL)||(o2.head!=NULL))
			{
				s=o1.head;
				while(s->next)
					s=s->next;
				s->next=o2.head;
				head=o1.head==NULL?o2.head:o1.head;
			}
			else
				head=NULL;
		}
		void create()
		{
			node *s;
			Pinnacle ol;
			s=head;
			while(s)
			{
				ol.add(s);
				s=s->next;
			}
			ol.display();
		}
		void add(node *newnode)
		{
			node *temp,*prev,*pp;
			pp=new node;
			pp->id=newnode->id;
			pp->name=newnode->name;
			pp->next=NULL;
			if(head==NULL)
			{
				head=pp;
			}
			else if(pp->id<head->id)
			{
				pp->next=head;
				head=pp;
			}
			else
			{
				temp=head->next;
				prev=head;
				while(temp)
				{
					if(pp->id<temp->id)
					{
						prev->next=pp;
						pp->next=temp;
						break;
					}
					prev=temp;
					temp=temp->next;
				}
				if(temp==NULL)
				{
					prev->next=pp;
				}


			}

		}
};
int main()
{
	Pinnacle obj,obj1,obj2;
	int ch,c,ll;
	char ans;
	do
	{
		cout<<"\nSelect link list(1/2):";
		cin>>ll;
		switch(ll)
		{
			case 1:cout<<"1.Insertion\n2.Display\n3.Number of members\n4.Delete\n5.Reverse\n";
			cin>>ch;

			switch(ch)
			{
				case 1:
					cout<<"\n1.President\n2.Member\n3.Secretary\n";
					cin>>c;
					obj.addnew(c);
					break;
				case 2:obj.display();
					break;
				case 3:obj.get_count();
					break;
				case 4:
					cout<<"\n1.President\n2.Member\n3.Secretary\n";
					cin>>c;
					obj.delete_node(c);
					break;
				case 5:obj.reverse(obj.gethead());
					break;
				default:cout<<"\nWrong choice!";
			}
			break;
			case 2:cout<<"1.Insertion\n2.Display\n3.Number of members\n4.Delete\n5.Reverse\n";
						cin>>ch;

			switch(ch)
			{
				case 1:
					cout<<"\n1.President\n2.Member\n3.Secretary\n";
					cin>>c;
					obj1.addnew(c);
					break;
				case 2:obj1.display();
					break;
				case 3:obj1.get_count();
					break;
				case 4:
					cout<<"\n1.President\n2.Member\n3.Secretary\n";
					cin>>c;
					obj1.delete_node(c);
					break;
				case 5:obj1.reverse(obj1.gethead());
					break;
				default:cout<<"\nWrong choice!";
			}
			break;

			default:cout<<"\nWrong choice of link list";
		}
		cout<<"\nWant to perform another operation?";
		cin>>ans;
	}while(ans=='y');
	cout<<"\nWant to concatenate the two lists?";
	cin>>ans;
	if(ans=='y')
	{
		obj2.concatenate(obj,obj1);
		cout<<"\nThe concatenated list is:\n";
		obj2.create();
	}
	return 0;
}

