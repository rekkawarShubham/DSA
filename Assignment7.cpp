//============================================================================
// Name        : st.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int top=-1;
class Stack
{

public:
	int a[5];
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(top==4)
	return 1;
	return 0;
}
void push(char data)
{
	top++;
	a[top]=data;
}
char pop()
{
	char x;
	x=a[top];
	top=top-1;

	return x;
}



};
int main() {

	char exp[20];
	Stack s;
	int flag;

	cout<<"Enter ur expression";
	cin>>exp;
	for(int i=0;exp[i]!='\0';i++)
	{

	if(exp[i]=='('||exp[i]=='[' ||exp[i]=='{')
		s.push(exp[i]);
	char ch;
	if((exp[i]==')')||(exp[i]==']') ||(exp[i]=='}'))
	{
		ch=s.pop();

		if((exp[i]==')' && ch!='(')||(exp[i]==']' && ch!='[')||(exp[i]=='}' && ch!='{'))
		{
			//cout<<"\n\tNo paranthesis";
			flag=1;
			break;
		}
	}


	}

int x=s.isempty();

	if(x==1 && flag==0)
		cout<<"\n\tValid";
	else
		cout<<"\n\tInValid";

	return 0;
}
