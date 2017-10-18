//============================================================================
// Name        : poly.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cmath>
using namespace std;
class Poly
{
public:
	int d1,i,j,a[10];
		int d2,b[10];
		int c[10],d[10];
		int max;
		int k=0;

	Poly()
	{
		for(i=0;i<10;i++)
		{
			a[i]=b[i]=c[i]=d[i]=0;
		}
	}

		void input();
		void disp();
		void add();
		void display();
		void mul();
		void show();
		void x();
		friend ostream & operator <<(ostream &out,Poly &p);

};
ostream& operator <<(ostream &o,Poly &p1)
{

		o<<"\n\t Addition of given Polynomial is: ";
		for(p1.i=p1.max;p1.i>=0;p1.i--)
		{
			if(p1.i==0)
			{
				o<<p1.c[p1.i];
			}
			else
			{
				o<<p1.c[p1.i]<<"x ^"<<p1.i<<" +";
			}
		}

}
void Poly::x()
{
	int x;
	cout<<"Enter the value of x";
	cin>>x;
	int val=0;
	for(i=d1;i>=0;i--)
	{
		val=val+a[i]*pow(x,i);
	}
	cout<<"The value is"<<val;



}
void Poly::mul()
{

	for(i=d1;i>=0;i--)
	{
		for(j=d2;j>=0;j--)
		{
				k=i+j;
				d[k]+=a[i]*b[j];

		}
	}

	k=d1+d2;
	for(int i=k;i>=0;i--)
			{	if(i==0)
				{
				cout<<d[i];

				}
				else
				{
				cout<<d[i]<<"x ^"<<i<<" +";
				}
			}


}

void Poly::add()
{

	max=(d1>d2)?d1:d2;

	for(i=max;i>=0;i--)
	{
		c[i]=a[i]+b[i];
	}

}



void Poly::input()
{

	cout<<"Enter the max degree of Poly1";
	cin>>d1;
	cout<<"\n\t Enter the coeeficients";
	for(i=d1;i>=0;i--)
	{
		cin>>a[i];
	}
	cout<<"Enter the max degree of Poly1";
		cin>>d2;
		cout<<"\n\t Enter the coeeficients";
		for(i=d2;i>=0;i--)
		{
			cin>>b[i];
		}





}
void Poly::disp()
{

	cout<<"\n\t The given Polynomial is: ";
	for(i=d1;i>=0;i--)
	{
		if(i==0)
		{
			cout<<a[i];
		}
		else
		{
			cout<<a[i]<<"x ^"<<i<<" +";
		}
	}


cout<<"\n\t The given Polynomial is: ";
for(i=d2;i>=0;i--)
{
	if(i==0)
	{
		cout<<b[i];
	}
	else
	{
		cout<<b[i]<<"x ^"<<i<<" +";
	}
}
}
int main() {
	int ch;
	Poly p;
do
{
	cout<<"\n\n---------------------------------------------\n";
cout<<"\n\t1.Enter the Polynomial\n\t2.Display\n\t3.Addition\n\t4.Multiplication\n\t5.Evaluate x";
cout<<"\n\tEnter ur choice";
cin>>ch;
switch(ch)
{
case 1:
			p.input();
			break;
case 2:
			p.disp();
			break;
case 3:
			p.add();
			cout<<p;
			break;
case 4:
			p.mul();
			//p.show();
			break;

case 5:
			p.x();
			break;
}

}while(ch!=6);

}
