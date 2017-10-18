//============================================================================
// Name        : vanilla.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;

}*head1,*head2,*head3;
int i;
node *temp=new node;
node * create()
{
	node *newnode=new node;
	cin>>newnode->data;
	newnode->next=NULL;
	return newnode;

}
void insert()
{
	node *ptr;
	int n;
	cout<<"\n\tEnter the number of elements";
	cin>>n;
	cout<<"\n\tEnter element";
	for(i=0;i<n;i++)
	{
		temp=create();
		if(head1==NULL)
		{
			head1=temp;
		}
		else
		{
			ptr=head1;
			while(ptr->next!=NULL)
				ptr=ptr->next;

			ptr->next=temp;

		}


	}


}
void insert_vanilla()
{
	node *ptr;
	int n;
	cout<<"\n\tEnter the number of elements who eat vanilla";
	cin>>n;
	cout<<"\n\tEnter elements";
	for(i=0;i<n;i++)
	{
		temp=create();
		if(head2==NULL)
		{
			head2=temp;
		}
		else
		{
			ptr=head2;
			while(ptr->next!=NULL)
				ptr=ptr->next;

			ptr->next=temp;

		}


	}


}
void insert_butter()
{
	node *ptr;
	int n;
	cout<<"\n\tEnter the number of elements eat butter";
	cin>>n;
	cout<<"\n\tEnter element";
	for(i=0;i<n;i++)
	{
		temp=create();
		if(head3==NULL)
		{
			head3=temp;
		}
		else
		{
			ptr=head3;
			while(ptr->next!=NULL)
				ptr=ptr->next;

			ptr->next=temp;

		}


	}


}
void disp()
{

	node *ptr;
	ptr=head1;
	cout<<"\n\n";
	while(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		ptr=ptr->next;
	}
	cout<<"\n";

}
void disp_v()
{

	node *ptr;
	ptr=head2;
	cout<<"\n\n";
	while(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		ptr=ptr->next;
	}
	cout<<"\n";

}
void disp_b()
{

	node *ptr;
	ptr=head3;
	cout<<"\n\n";
	while(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		ptr=ptr->next;
	}
	cout<<"\n";

}
void in()

{
	int flag=0;
	node *p1=head2;
	node *p2=head3;
cout<<"\n";
	while(p1!=NULL)
	{
		flag=0;
		while(p2!=NULL)
		{
			if(p1->data==p2->data)
			{
				flag=1;
				break;
			}

			p2=p2->next;
		}
		if(flag==1)
		{
			cout<<"\t"<<p1->data;
		}

		p1=p1->next;
	}



}
void only_v()
{
	int flag=0;
	node *p1,*p2;
	p1=head2;
	p2=head3;
	while(p1!=NULL)
	{
		flag=0;
		p2=head3;
		while(p2!=NULL)
		{
			if(p1->data==p2->data)
			{
				flag=1;
				break;
			}
			p2=p2->next;
		}
		if(flag==0)
		{
			cout<<"\t"<<p1->data;
		}
		p1=p1->next;

	}





}
void only_b()
{
	int flag=0;
	node *p1,*p2;
	p1=head3;
	p2=head2;
	while(p1!=NULL)
	{
		flag=0;
		p2=head2;
		while(p2!=NULL)
		{
			if(p1->data==p2->data)
			{
				flag=1;
				break;
			}
			p2=p2->next;
		}
		if(flag==0)
		{
			cout<<"\t"<<p1->data;
		}
		p1=p1->next;

	}





}
void uni()
{
	only_v();
	in();
	only_b();

}



int main() {
	head1=NULL;
	head2=NULL;
	head3=NULL;

	int ch;

	insert();
	insert_vanilla();
	insert_butter();


	do
	{
cout<<"\n-------------------------------------------------------\n";
	cout<<"\n\t1.Display All Students\n\t2.Display Student only eat vanilla\n\t3.Display Student only eat butter\n\t4.Students eat both\n\t5.Display student students who like only vanilla\n\t6.Only b";
	cout<<"\n\t7.UNION";
	cout<<"\n\tEnter your choice";
	cin>>ch;
	switch(ch)
	{
	case 1:
				disp();
				break;
	case 2:
				disp_v();
				break;
	case 3:
				disp_b();
				break;
	case 4:
				in();
				break;
	case 5:
				only_v();
				break;
	case 6:
				only_b();
				break;
	case 7:
				uni();
				break;

	}
	}while(ch!=8);

	return 0;
}
