//============================================================================
// Name        : set.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Set
{
public:
	int n,i,cn,bn,j,k,flag=0;
	int total[10],a[10],b[10],c[10];
	int ni[10];

			void input();
			void dispc();
			void dispb();
			void intersect();
			void neither();
			void uni();



};
void Set::uni()
{
	int un[10];
	int cnt1=0,flag=0;
	for(i=0;i<cn;i++)
	{
		un[cnt1]=a[i];
		cnt1++;


	}
for(i=0;i<bn;i++)
{
	flag=0;
		for(j=0;j<cn;j++)
		{
			if(a[j]==b[i])
			{
				flag=1;
				break;

			}
		}
			if(flag==0)
			{
				un[cnt1]=b[i];
				cnt1++;
			}

	}

		cout<<"\n\n\t Students Playing any game are:";
				for(i=0;i<cnt1;i++)
				{
					cout<<"\n\t"<<un[i];
				}






}
void Set::neither()
{
	k=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<cn;j++)
		{
			if(total[i]==a[j])
			{
				flag=1;
				break;
			}



		}
		if(flag==0)
		{
			ni[k]=total[i];
			k++;
		}
	}

	int cnt=0;
	int final[10];
	for(i=0;i<k;i++)
		{
			flag=0;
			for(j=0;j<bn;j++)
			{
				if(ni[i]==b[j])
				{
					flag=1;
					break;
				}



			}
			if(flag==0)
			{
				final[cnt]=ni[i];
				cnt++;
			}
		}

	cout<<"\n\n\t Students not playing any game are:";
			for(i=0;i<cnt;i++)
			{
				cout<<"\n\t"<<final[i];
			}





}
void Set::intersect()
{
	k=0;
	for(i=0;i<cn;i++)
	{
		for(j=0;j<bn;j++)
		{
			if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
			}
		}
	}
		cout<<"\n\n\t Students playing both are:";
		for(i=0;i<k;i++)
		{
			cout<<"\n\t"<<c[i];
		}

}







void Set::input()
{
	cout <<"\n\tEnter total number of student";
		cin>>n;
		cout<<"\n\tEnter students roll number";
		for(i=0;i<n;i++)
		{
			cin>>total[i];
		}
		cout <<"\n\n\tEnter total number of student playing cricket";
			cin>>cn;
			cout<<"\n\tEnter students roll number";
			for(i=0;i<cn;i++)
			{
				cin>>a[i];
			}
			cout <<"\n\n\tEnter total number of student playing badminton";
				cin>>bn;
				cout<<"\n\tEnter students roll number";
				for(i=0;i<bn;i++)
				{
					cin>>b[i];
				}




}
void Set::dispc()
{
		cout <<"\n\tTotal number of student in cricket: "<<cn;
			cout<<"\n\tStudents roll number";
			for(i=0;i<cn;i++)
			{
				cout<<"\n\t"<<a[i];
			}

}
void Set::dispb()
{
	cout <<"\n\tTotal number of student in Badminton: "<<bn;
				cout<<"\n\tStudents roll number";
				for(i=0;i<bn;i++)
				{
					cout<<"\n\t"<<b[i];
				}
}
int main() {

	int ch;
	Set s;
	do
	{
		cout<<"\n----------------------------------------------------------------------------\n";
		cout<<"\n\t1.Input\n\t2.Display student only playing cricket\n\t3.Display student only playing badminton\n\t4.Playing both\n\t5.Not playing any game";
		cout<<"\n\t6.Students Playing any game";

	cout<<"\n\tEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
	case 1:
							s.input();
							break;
	case 2:
							s.dispc();
							break;
	case 3:
							s.dispb();
							break;
	case 4:
							s.intersect();
							break;
	case 5:
							s.neither();
							break;
	case 6:
							s.uni();
							break;


	}



	}while(ch!=7);
	return 0;
}
