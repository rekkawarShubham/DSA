//============================================================================
// Name        : Bub_select.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;
class sort
{
	int array[10];
	int n;
public:
	void get()
	{
		cout<<"\nEnter number of students:";
		cin>>n;
		cout<<"\nEnter their percentages:\n";
		for(int i=0;i<n;i++)
			cin>>array[i];
	}
	void bubble_sort()
	{
		int i,j,temp;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(array[j+1]<array[j])
				{
					temp=array[j+1];
					array[j+1]=array[j];
					array[j]=temp;
				}
			}
		}
		show();
		show_top5();
	}
	void selection_sort()
	{
		int i,j,small,temp;
		for( i=0;i<n;i++)
		{
			small=i;
			for(j=i+1;j<n;j++)
			{
				if(array[j]<array[small])
				{
					small=j;
				}
			}
			temp=array[small];
			array[small]=array[i];
			array[i]=temp;
		}
		show();
		show_top5();
	}
	void show()
	{
		for(int i=0;i<n;i++)
		{
			cout<<array[i]<<" ";
		}
	}
	void show_top5()
	{
		cout<<"\nThe top scorers are:";
		for(int i=n-1;i>=(n-5)&&i>=0;i--)
		{
			cout<<"\n"<<array[i];
		}
	}
};
int main()
{
	int ch;
	sort s;
	s.get();
	cout<<"\n1.Bubble sort\n2.Selection Sort\n";
	cin>>ch;
	switch(ch)
	{
	case 1:
		s.bubble_sort();

		break;
	case 2:
		s.selection_sort();
		break;
	default:cout<<"\nWrong choice!!";
	}
	return 0;
}



