//============================================================================
// Name        : cinemax.cpp
// Author      : Shubham Rekkawar 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
struct node
{
	int flag;
	char mname[20];
	char name[20];
	long mno;
	node *next;
	node *prev;
};
struct hnode
{
	node *next;
	int cnt;
};
class theatre
{
	hnode *head[11];
	node *temp,*t1,*p;
	int n,i,j;
public:
	theatre()
	{
		for(i=1;i<=10;i++)
		{
		head[i]=new hnode;
		head[i]->next=NULL;
		head[i]->cnt=0;
		}
		temp=t1=p=NULL;
		n=i=j=0;
	}
	void create(){

					node *f1;
					for(i=1;i<=10;i++)
					{
						cout << i << endl ;
							p=new node;
							p->next=NULL;
							p->prev=NULL;
							p->flag=0;
							strcpy(p->mname,"NIL");
							strcpy(p->name,"NIL");

						if(head[i]->next==NULL)
						{
							head[i]->next=p;
							p->prev=p;
							p->next=p;
						}
						temp=head[i]->next;
						f1=temp;
						for(int  k=1;k<=6;k++)
						{
							t1=new node;
							t1->flag=0;
							strcpy(t1->mname,"NIL");
							strcpy(t1->name,"NIL");
							t1->next=head[k]->next;
							temp->next=t1;
							t1->prev=temp;
							f1->prev=t1;
							temp=t1;
						}
					}

	}
	void show(){
		cout<<"Rows Status are as follows...\n";
				    cout<<"\nHead Node\tCol1\t\tCol2\t\tCol3\t\tCol4\t\tCol5\t\tCol6\t\tCol7";
				    for(int k=1;k<=10;k++)
				    {

				    	//cout << k << endl ;
				        cout<<"\nRow : "<<k;
				        temp=head[k]->next;



				        cout<<"[ "<<head[k]->cnt<<" ]-->";
				       for(int i=1;i<=7;i++)
				       {
				         cout<<"[ "<<temp->flag<<"|"<<temp->mname<<"|"<<temp->name<<"]->";
				         temp=temp->next;
				        }

				        /*if(temp->next==head[k]->next)
				        {
				         cout<<"[ "<<temp->flag<<"|"<<temp->mname<<"|"<<temp->name<<"]->";
				        }
				        cout<<"\n\n";*/
				    }
	}
	int bookshow(int r,int n,char name[20]){
		cout<<"\nYou request for"<<n<<"tickets"<<"of"<<name<<"movie\n";
			temp=head[r]->next;
			int max;
			max=head[r]->cnt;
			if(max==7)
			{
				cout<<"\nSorry no seats\n";
				return 0;
			}
			else
			{
				int seat[5],cnt=0,sn;
				for(i=0;i<n;i++)
				{
					cout<<"\nEnter seat nos\n";
					cin>>sn;
					seat[i]=sn-1;
				}
				i=0;
				while(temp->next!=head[r]->next)
				{
					if(cnt!=seat[i])
					{
						cnt++;
						temp=temp->next;
					}
					else
					{
						if(temp->flag==0)
						{
							strcpy(temp->mname,name);
							temp->flag=1;
							cout<<"\nEnter your name\n";
							cin>>temp->name;
							head[r]->cnt=head[r]->cnt+1;
							cnt=0;
							temp=head[r]->next;
							i++;
							if(i==n)
								break;
						}
					}
				}
			}
			if(temp->next==head[r]->next)
			{
				if(temp->flag==0)
				{
							strcpy(temp->mname,name);
							temp->flag=1;
							cout<<"\nEnter your name\n";
							cin>>temp->name;
							head[r]->cnt=head[r]->cnt+1;

				}
			}
			return 1;
	}
	int cancelshow(int r,int n,char name[]){
		cout<<"\nYou request for"<<n<<"tickets"<<"of"<<name<<"movie\n";
				temp=head[r]->next;
				int max;
				max=head[r]->cnt;
				if(max==-1)
				{
					cout<<"\nSorry no seats for cancel\n";
					return 0;
				}
				else
				{
					int seat[5],cnt=0,sn;
					for(i=0;i<n;i++)
					{
						cout<<"\nEnter seat nos\n";
						cin>>sn;
						seat[i]=sn-1;
					}
					i=0;
					while(temp->next!=head[r]->next)
					{
						if(cnt!=seat[i])
						{
							cnt++;
							temp=temp->next;
						}
						else
						{
							if(temp->flag==1)
							{
								strcpy(temp->mname,"NIL");
								temp->flag=0;
								strcpy(temp->name,"NIL");
								head[r]->cnt=head[r]->cnt-1;
								cnt=0;
								temp=head[r]->next;
								i++;
								if(i==n)
									break;
							}
						}
					}
				}
				if(temp->next==head[r]->next)
				{
					if(temp->flag==1)
					{
								strcpy(temp->mname,"NIL");
								temp->flag=0;
								strcpy(temp->name,"NIL");
								head[r]->cnt=head[r]->cnt+1;

				}
				}
				return 1;
	}

};

int main()
{
	cout << "Mad " << endl ;
	theatre c1;
	int row,n,ch,am;
	char mname[20];
	c1.create();
	cout<<"Talented " ;
	do
	{
		cout<<"\n1.book\n2.display\n3.cancel\n";
		cout<<"\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n1.Mohenjo_Daro\n2.Rustom\n3.Happy_Bag_Jayegi\n4.Bar_Bar_Dekho\n5.Akira\n6.Rangoon\n7.A Flying_Jatt.\n";
			cout<<"\nEnter  movie name ";
			cin>>mname;
			        c1.show();
			        cout<<"\nEnter the row number to book u r ticket: ";
			            cin>>row;
			        cout<<"\nHow many Tickets u want to Book: ";
			        cin>>n;
			        am=c1.bookshow(row,n,mname);
			        if(am!=0)
			        {
			         c1.show();
			         cout<<"\n\nYour booking is confirmed please see the status: ..\n\n";
			        }
			        else
			        {
			         cout<<"\n\nTry for another row...\n";
			        }
			        break;

		case 2:
				cout<<"\n The Booking status of the Cinemax Theator are as follows...\n\n";
		        c1.show();
		        break;
		case 3:
				cout<<"\n Cancel your Show...";
		        cout<<"\nEnter movie name to cancel the show: ";
		        cin>>mname;
		        c1.show();
		        cout<<"\nEnter the row number to cancel :";
		        cin>>row;
		        cout<<"\nHow many Tickets u want to Cancel: ";
		        cin>>n;
		        am=c1.cancelshow(row,n,mname);
		        if(am!=0)
		        {
		         c1.show();
		         cout<<"\n\nYour booking is cancel please see the status: ..\n\n";
		        }
		        else
		        {
		         cout<<"\n\nTry for another row...\n";
		         }
		        break;

		}
	}while(ch!=0);
	return 0;
}


