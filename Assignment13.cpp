//============================================================================
// Name        : quick_sort.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#define MAX 20

class sorting
{

public:
	int marks[MAX],n,lb=0,ub=n-1;

	void accept();
	void display();
	void topfive();
	void quick();
	void quick_sort(int marks[],int lb,int ub);
	int  partiton(int marks[],int lb,int ub);
};

void sorting::accept()
	{
		cout<<"Enter the no of marks to be entered:"<<endl;
		cin>>n;
		cout<<"Enter the marks"<<endl;
		for(int i=0;i<n;i++)
			cin>>marks[i];

		quick_sort(marks,0,n-1);

	}

int sorting::partiton(int marks[],int lb,int ub)
{

		int pivot, up, down;
		pivot = marks[lb];
		up = lb;
		down = ub;
		while (up < down)
		{
			while (marks[up] <= pivot && up <ub)
				up++;


			while (marks[down] > pivot && down>lb)
				down --;


			if (up < down)
			{
					int t= marks[up];
					marks[up]=marks[down];
					marks[down]=t;
			}
		}
		marks[lb] = marks[down];
		marks[down] = pivot;
		return down;
}
void sorting::quick_sort(int marks[],int i,int j)
{
	if(i>=j)
		return;

	int p=partiton(marks,i,j);

	quick_sort(marks,i,p-1);

	quick_sort(marks,p+1,j);
}

void sorting::topfive()
{
	cout<<"Top five scores are:"<<endl;
	for(int i=n-1;i>=(n-5);i--)
		{
			cout<<marks[i]<<" ";
		}
}

void sorting::display()
	{
		cout<<"The entered marks are:"<<endl;
		for(int i=0;i<n;i++)
			cout<<marks[i]<<" ";
		cout<<endl;

	}



int main()
{
       sorting s;
        s.accept();
		cout<<"After sorting:"<<endl;
		s.display();
		s.topfive();
		return 0;
}
