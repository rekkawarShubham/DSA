//============================================================================
// Name        : stack1.cpp
// Author      : Shubham Rekkawar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<ctype.h>
using namespace std;
//class inpo containing data member and member functions
class inpo
{
    char in[20],po[20],stk[10];//stack for expression conversion.
    int i,j,is,ic,top,top1; //Two top one for stack and one for stack 1.
    int stk1[10]; //Stack 1 for expression evaluation.
public:
    inpo()
    {
     i=j=is=ic=0; //initialization of data members
     top=top1=-1;
    }
    bool IsOperand(char C)
    {
        if(C >= '0' && C <= '9') return true;
        if(C >= 'a' && C <= 'z') return true;
        if(C >= 'A' && C <= 'Z') return true;
        return false;
    }
    void getinfix() //Accept the infix expression
    {
        cout<<"\nEnter valid infix Expression: ";
        cin>>in; //Stored infix exp in in[]char array.
    }
    void showinfix() //Show the infix expression
    {
        cout<<"\t"<<in;
    }
    int isempty() //Stack basic functions.
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if(top==9)
            return 1;
        else
            return 0;
    }
    void push1(int x1)//for integer stack
    {
        top=top+1;
        stk1[top]=x1;
    }
    int pop1() //for integer stack
    {
       int s1;
       s1=stk1[top];
       top=top-1;
       return s1;
    }
    void push(char x)//for character stack
    {
        top=top+1;
        stk[top]=x;
    }
    char pop()//for character stack
    {
        char s;
        s=stk[top];
        top=top-1;
        return s;
    }
    void showpostfix()
    {
        cout<<"\t"<<po;
    }
    void convert();
    int instackprio();
    int incomingprio(char); //member functions
    void postfixExpEval();
};
void inpo::postfixExpEval() //To evaluate the postfix expression
{
    i=0;
    char ch;
    int op1,op2,res,tot;
        while(po[i]!='\0')//read postfix expression one by one
        {
            ch=po[i];
            if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^')) //isdigit(ch) built in function to check digit.
            {
                switch(ch)//if operator pop and perform operation and push back into the stack.
                {
                case '+':op2=pop1();
                         op1=pop1();
                         res=op1+op2;
                         push1(res);
                         break;
                case '-':op2=pop1();
                         op1=pop1();
                         res=op1-op2;
                         push1(res);
                         break;
                case '*':op2=pop1();
                         op1=pop1();
                         res=op1*op2;
                         push1(res);
                         break;
                case '/':op2=pop1();
                         op1=pop1();
                         res=op1/op2;
                         push1(res);
                         break;
                case '^':op2=pop1();
                         op1=pop1();
                         res=op1;
                         while(op2>1)
                         {
                          res=res*op1;
                          op2--;
                         }
                         push1(res);
                         break;
                }//end of switch

            } //end of if
            else if(IsOperand(ch))//To check operand we use IsOperand function.
            {
                push1(ch-'0'); //if operand push it inside stack
            } //end of else
            i=i+1;
        }//end of while

    tot=pop1(); //final evaluated result at the top of stack.
    cout<<"\nResult is:"<<tot;
}//end of fun

/*******************************************************************
 * Function Name: To convert infix expression to postfix expression.
 * return type: Void
 *******************************************************************/

void inpo::convert()
{
    i=j=0;
    char p,k;
    while(in[i]!='\0')//do until null character not found
    {
     p=in[i];//to read one by one from infix expression
     if((p=='(')||(p=='+')||(p=='-')||(p=='*')||(p=='/')||(p=='^')||(p==')'))
     {
         if(isempty()) //here we are dealing with operator only as per their priority.
         {
             push(p); //if initially stack is empty push
         }
         else if(p==')') //when we encountered with ')' bracket pop from stack until we r not encountered with '(' bracket.
         {
             k=pop();
             while(k!='(') //check the pop element with '(' bracket. if equal stop poping.
             {
                 po[j]=k; //pop and store it inside the postfix expression array po[].
                 j++;     //increment po[] array index by 1.
                 k=pop(); //pop next element
             }
         }
         else
         {
             is=instackprio(); //when we are pushing the operator inside the stack.
             ic=incomingprio(p);// we are always checking their incoming and instack priority.
             if(is>ic)//if instack priority is gretter than incoming priority
             {
              k=pop(); //pop the stack top operator whose priority is bigger than incoming operator from stack.
              po[j]=k;//store it in postfix expression array po[j]
              j++;  //increment j by one.
              push(p);//then push the incoming operator in stack.
             }
             else
             {
                 push(p); //if incoming operator priority is gretter than instack operator priority then
             }            // directly push the incoming operator inside the stack.
         }
     }
     else// if opearnd is their directly store it inside the postfix expression array po[j].
     {
        po[j]=p;
        j++; //increment j by one.
     }
     i=i+1; //read the next character of infix expression for conversion.
    }//end of while loop
    if(in[i]=='\0')//if we encountered with NULL Character of infix expression then
    {
        while(!isempty())//pop the stack containts until stack is not empty and
        {
         k=pop(); //pop from stack
         po[j]=k; //store it inside the postfix expression array po[j].
         j++;  //increment j by one.
        }
    }
 po[j]='\0'; // at the end of the postfix expression store null character to indicate end of the expression.
}

/* * Function to check the instack priority of operator * */
int inpo::instackprio()
{
    char b;
    b=stk[top];
    switch(b)
    {
     case '(':return 0; break;
     case '+':return 2; break;
     case '-':return 2; break;
     case '*':return 4; break;
     case '/':return 4; break;
     case '^':return 5; break;
    }
}
/* * Function to check the priority of incoming operator * */
int inpo::incomingprio(char ch)
{
    switch(ch)
    {
     case '(':return 9; break;
     case '+':return 1; break;
     case '-':return 1; break;
     case '*':return 3; break;
     case '/':return 3; break;
     case '^':return 6; break;
    }
}

int main()
{
    inpo p1;
    p1.getinfix();
    p1.showinfix();
    cout<<"\nAfter conversion from infix to postfix...\n";
    p1.convert();
    p1.showpostfix();
    cout << "\n\n!!!POSTFIX EXPRESSION EVALUATION ARE AS FOLLOWS..!!!" << endl;
    p1.postfixExpEval();
    return 0;
}
