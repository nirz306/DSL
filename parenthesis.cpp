#include<iostream>
#include<string.h>
using namespace std;

class stackOp
{
    char arr[100];
    public:
        int top = -1;
        string str;
       
        void check_parenthesis()
        {
             int flag = 0;
            cout<<"Enter an expression ";
            cin>>str;
            for(int i=0; str[i]!='\0'; i++)
            {
                if(str[i] == '(' || str[i] == '{'  || str[i] == '[' )
                {
                    top++;
                    arr[top]=str[i];

                }
                else if(str[i] == ')' || str[i] == '}'  || str[i] == ']' )
                {
                    switch(str[i])
                    {
                        case ')':if(arr[top]!='(')
                                {flag = 1;}
                                break;
                                

                        case '}':if(arr[top]!='{')
                                {flag = 1;}
                                break;

                        case ']':if(arr[top]!='[')
                                {flag = 1;}
                                 break;

                        default: cout<<"Invalid exp"<<endl;
                    }
                    top--;
                    if (flag == 1)
                    {
                        break;
                    }
                    
                }
                else{

                }
            }

             if (flag ==1 || top!=-1)
                {cout<<"Flag"<<flag<<endl;
                cout<<"Top"<<top<<endl;
                cout<<"Not well parenthesized"<<endl;}
            else   //top = -1    
                {cout<<"Flag"<<flag<<endl;
                cout<<"Top"<<top<<endl;
                cout<<"Well parenthesized"<<endl;}

        }
};

int main()
{
    stackOp obj1;
    obj1.check_parenthesis();
}
