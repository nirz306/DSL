#include<iostream>
using namespace std;

char stack[10];  //..............Stack and Top Declaration
int top = -1;

void expConvert() //.......Function to convert Expression: INFIX - POSTFIX
{

	 char infix[20];   //....to store Infix expression
	 char postfix[20]; //....to store Postfix expression
	
	 int i = 0;  //....Index of Infix String
	 int j = 0;  //....Index of Postfix String
	
	 cout<<"\n\n Enter the Infix Expression: ";  //....Accept Input/Infix String
	 cin>>infix;
	
	for(i=0; infix[i] != '\0'; i++) //....Visit/Access each character of Infix String
	 {
	 if(infix[i] == '(' || infix[i] == '[' || infix[i] == '{')  //......if Opening Parantheses - Push in Stack
	 {
	 top++;
	 stack[top] = infix[i];
	 } 
	
	 else if(infix[i] == 'a' || infix[i] == 'b' || infix[i] == 'c' || infix[i] == 'd')  //....if Operand - Copy to Postfix String
	 {
	 postfix[j] = infix[i];
	 j++;
	 } 
	
	 else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')  //....if Operator - push in stack
	 {
	 top++;
	 stack[top] = infix[i];
	 }
	 else    //......if Closing Parantheses - Pop until Opening and copy to Postfix String.
	 {
	 switch(infix[i])
	 {
	 case ')': while(stack[top] != '(')
		 {
		 postfix[j] = stack[top];
		 j++;
		 top--;
		 }
		 top--;
		 break;
	 case ']': while(stack[top] != '[')
		 {
		 postfix[j] = stack[top];
		 j++;
		 top--;
		 }
		 top--;
		 break;
	 case '}': while(stack[top] != '{')
	 {
	 postfix[j] = stack[top];
	 j++;
	 top--;
	 }
	 top--;
	 break;
	 }
	
	 }
	 }
	
	 postfix[j] = '\0'; //....Display Postfix String
	
	 cout<<"\n\t The Postfix String: "<<postfix;

}

 
int stk[10];
 int top2 = -1;

void push(int val) //..............Push Function
{
 top2++;
 stk[top2] = val;
}

int pop()  //..............Pop Function
{
 int val = stk[top2];
 top2--;
 return val;
}

void postfixEval()  //..............Postfix Expression Evaluation
{
 int j; //....Index of Postfix String
 char postfix[20];  //....To store Postfix String
 int Operand1; //...to store Operands
 int Operand2;


 cout<<"\n\n Enter the Postfix String: ";
 cin>>postfix;


 for(j=0; postfix[j] != '\0'; j++)   //iterating postfix string
 {
 
	 if(postfix[j] == 'a' || postfix[j] == 'b' || postfix[j] == 'c' || postfix[j] == 'd')   //....If Operands - Push in Stack
	
	 {
	 switch(postfix[j])
	 {
	 case 'a': push(2); // a = 2
	 break;
	 case 'b': push(4); // b = 4
	 break;
	 case 'c': push(6); // c = 6
	 break;
	 case 'd': push(8); // d = 8
	 break;
 	}
 	}
 else                   //....if Operator: Pop 2 Operands,do operation and Push result in stack.
 {
	 Operand2 = pop(); //....Second Operand : due to LIFO
	
	 Operand1 = pop(); //....First Operand : due to LIFO

	 switch(postfix[j]) //....Do an Operatoration as per the Operator.
	 {
	 case '+':
	 push(Operand1 + Operand2);
	 break;
	 case '-':
	 push(Operand1 - Operand2);
	 break;
	 case '*':
	 push(Operand1 * Operand2);
	 break;
	 case '/':
	 push(Operand1 / Operand2);
	 break;
	 }
	 }
 }

 cout<<"\n\t Postfix Expression Evaluation: "<<pop();
}


 
int main()
{
  expConvert();

 cout<<"\n\n";
 
 cout<<"\n Operand - Value";
 cout<<"\n\t a - 2";
 cout<<"\n\t b - 4";
 cout<<"\n\t c - 6";
 cout<<"\n\t d - 8";

 postfixEval();

 cout<<"\n\n";
 return 0;
}
/*--------------------OUTPUT-----------------------
 
Enter the Infix Expression: (a+b)
The Postfix String: ab+
 
Enter the Infix Expression: [(a+b)*(c-d)]
The Postfix String: ab+cd-*
 
Enter the Infix Expression: [a*(c-d)]
 The Postfix String: acd-*
 
 Program for Postfix Expression Evaluation 
--------------------------------------------------
 Operand - Value
a - 2
b - 4
c - 6
d - 8
Enter the Postfix String: abc+*
Postfix Expression Evaluation: 20
 
----------------------------------------------------*/
