//============================================================================
// Name        : queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Using ARRAY
#include <iostream>
using namespace std;

struct node
	{
		int a[10];
	}p;
	int f=-1,r=-1;
class Queue
{
public:

		int data;
		void insert();
		void del()
		{
			if(f==-1)
			{
				cout<<"\n\tQueue is empty";
			}
			else
			{
				f=f+1;
			}


		}
		void display()
		{
			for(int i=f;i<=r;i++)
			{
				cout<<"\t"<<p.a[i];
			}


		}
};
 void  Queue::insert()
 {

	 if(f==-1 || r==-1)
	 {
		 f=0;
		 r=0;
		 cout<<"\n\tEnter the element";
		 cin>>data;
		p.a[r]=data;

	 }
	 else
	 {
		 r=r+1;
		 cout<<"\n\tEnter the element";
		 cin>>data;
		 p.a[r]=data;


	 }


 }
int main() {

	Queue q;
	int ch;

do
{
cout<<"\n\t1.Insert Elements\n\t2.Delete Elements\n\t3.Display";
cout<<"\n\tEnter ur choice";

cin>>ch;
switch(ch)
{

case 1:
			q.insert();
			break;
case 2:
			q.del();
			break;
case 3:
			q.display();
			break;
}



}while(ch!=5);





}
