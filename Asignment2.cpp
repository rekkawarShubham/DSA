//============================================================================
// Name        : matrix.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Array
{
public:
	int a[10][10];
	int r,c,i,j;
	void input();
	void display();
	void upper();
	void transpose();
void add_d();
void add();
void sub();
void mul();
};
void Array::add()
{
	int b[10][10],add[10][10];
	int r1,c1;
	cout<<"\n\tEnter the rows and columns of m2";
		cin>>r1>>c1;
		cout<<"\n\tEnter elements";
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				cin>>b[i][j];
			}
		}
		//Addition of two matrix

				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						add[i][j]=a[i][j]+b[i][j];
					}
				}
		display();
		cout<<"\n\tElements of m2 :\n ";
			for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						cout<<"\t"<<b[i][j];
					}
					cout<<"\n";
				}
			cout<<"\n\tAddition :\n ";
				for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							cout<<"\t"<<add[i][j];
						}
						cout<<"\n";
					}





}
void Array::mul()
{
	int b[10][10],mul[10][10];
	int r1,c1;
	cout<<"\n\tEnter the rows and columns of m2";
		cin>>r1>>c1;
		cout<<"\n\tEnter elements";
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				cin>>b[i][j];
			}
		}
		//Addition of two matrix
int k=0;
				for(i=0;i<2;i++)
				{

					for(j=0;j<2;j++)
					{
						mul[i][j]=0;
						for(k=0;k<2;k++)
						{
						mul[i][j]+=a[i][k]*b[k][j];
						}
					}
				}
		display();
		cout<<"\n\tElements of m2 :\n ";
			for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						cout<<"\t"<<b[i][j];
					}
					cout<<"\n";
				}
			cout<<"\n\tAddition :\n ";
				for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							cout<<"\t"<<mul[i][j];
						}
						cout<<"\n";
					}





}

void Array::sub()
{
	int b[10][10],add[10][10];
	int r1,c1;
	cout<<"\n\tEnter the rows and columns of m2";
		cin>>r1>>c1;
		cout<<"\n\tEnter elements";
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				cin>>b[i][j];
			}
		}
		//Addition of two matrix

				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						add[i][j]=a[i][j]-b[i][j];
					}
				}
		display();
		cout<<"\n\tElements of m2 :\n ";
			for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						cout<<"\t"<<b[i][j];
					}
					cout<<"\n";
				}
			cout<<"\n\tSubtraction :\n ";
				for(i=0;i<r;i++)
					{
						for(j=0;j<c;j++)
						{
							cout<<"\t"<<add[i][j];
						}
						cout<<"\n";
					}





}
void Array::add_d()
{
	int sum;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				sum=sum+a[i][j];
			}

		}
	}
	cout<<"\n\tAddition of diagonl matrix is :"<<sum;


}
void Array::upper()
{
	int flag=0;
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i<j)
				{
					if(a[i][j]!=0)
					{
						flag=1;
						break;
					}

				}

			}
		}
	if(flag==1)
	{
						cout<<"\n\t Not upper triangular";
	}
					else
					{
						cout<<"\n\t Upper triangular";
					}



}
void Array::input()
{
	cout<<"\n\tEnter the rows and columns ";
	cin>>r>>c;
	cout<<"\n\tEnter elements";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}


}
void Array::display()
{
	cout<<"\n\tElements are :\n ";
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cout<<"\t"<<a[i][j];
			}
			cout<<"\n";
		}
}
void Array::transpose()
{
	cout<<"\n\tTranspose matrix\n";
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cout<<"\t"<<a[j][i];
			}
			cout<<"\n";
		}
}

int main() {
	int ch;
	Array a1;
	do
	{
		cout<<"\n--------------------------------------------------------\n";
	cout <<"\n\t1.Enter Elements\n\t2.Display\n\t3.Check Upper triangular\n\t4.Transpose\n\t5.Summation of diagonal elements";
	cout<<"\n\t6.Addition\n\t7.Subtraction\n\t8.Multiplication";
	cout<<"\n\tEnter your choice : ";

	cin>>ch;
	switch(ch)
	{
	case 1:
					a1.input();
					break;
	case 2:
					a1.display();
					break;
	case 3:
					a1.upper();
					break;
	case 4:
					a1.transpose();
					break;
	case 5:
					a1.add_d();
					break;

	case 6:
					a1.input();
					a1.add();
					break;
	case 7:
						a1.input();
						a1.sub();
						break;
	case 8:
					a1.input();
					a1.mul();
					break;
	}





	}while(ch!=9);
	return 0;
}
