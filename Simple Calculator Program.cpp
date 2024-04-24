#include <iostream>
#include "Stackt.h"
#include <string>
using namespace std;
 
 // this is a function that determine which operation should be done first
    int priority(char ch)
    {
        if(ch=='/' || ch=='*')
        {
            return 2; // return 2, which is the heights value meaning that it is the top piority operations 
        }
        else if(ch=='+'||ch=='-')
        {
            return 1;  // return 1, which is the second heights value meaning that it is the secound top piority operations
        }
        else 
        return 0;
    }

    // this is a function that convert the char to be double 
    // (the reason why I am using double not int because there is a division part, which mgiht be a fraction )
    double convertchartoint(char ch)
    {
        if(ch=='0')
        {
            return 0.0;
        }
        else if(ch=='1')
        {
            return 1.0;
        }
        else if(ch=='2')
        {
            return 2.0;
        }
        else if(ch=='3')
        {
            return 3.0;
        }
        else if(ch=='4')
        {
            return 4.0;
        }
        else if(ch=='5')
        {
            return 5.0;
        }
        else if(ch=='6')
        {
            return 6.0;
        }
        else if(ch=='7')
        {
            return 7.0;
        }
        else if(ch=='8')
        {
            return 8.0;
        }
        else if(ch=='9')
        {
            return 9.0;
        }
        return 0.0;
    }
   
    // other way to convert 
    double convertch(char ch)
    {
        return ch - '0';
    }

    // this is a function to evaluate the postfix 
    double evaluateoperation(double x,double y,char ch)
    {
        if(ch=='/')
        {
            return y/x;
        }
        else if(ch=='*')
        {
            return x*y;
        }
        else if(ch=='+')
        {
            return x+y;
        }
        else if(ch=='-')
        {
            return x-y;
        }
        return 0.0;
    }

    // this is a function that convert the infix the user provide to a postfix to be evaluated 
    // in other function
    double evaluatepostfix(string postfix)
    {
        double dum;
        Stackt<double>S;
        for(int i=0;i<postfix.length();i++)
        {
            char temp=postfix[i];
            if(( temp>'0' && temp<'9') )
            {
              double num =convertch(temp);
              S.push(num);
            }
            else
            {
                double x[2];
                for (int count = 0; count < 2; count++) {
                S.stackTop(x[count]);
                S.pop(dum);
            }
               S.push(evaluateoperation(x[0],x[1],temp)); 
            }
        }
        double result;
        S.stackTop(result);
        cout<<"the final result is "<<result;
    
        return 0;

    }

int main()
{
    string input;

    cout<<"please write the infix\n";
    cin >> input;
    
    Stackt<char> S;
    string postfix;
    char x;

    for(int i=0;i<input.length();i++)
    {
        char temp= input[i];
        if((temp>='a'&& temp<='z')||(temp>='A' && temp <='Z')||( temp>'0' && temp<'9') )
        postfix=postfix+temp;
        else if(input[i]=='(')
        {
           S.push(input[i]); 
        }
        else if(input[i]==')')
        {
            if(S.stackIsEmpty()==1)
            {
                cout<<"there is an error with the prackets\n";
            }
            else 
            {   
                char y;
                while(S.stackIsEmpty()!=1 &&(S.stackTop(y), y)!= '(')
                {
                        postfix=postfix+y;
                        S.pop(x);
                }
                S.pop(x);
            }
        }
        else
        {
            char y;
            S.stackTop(y);
            while (S.stackIsEmpty()!=1 && priority(temp)<= priority(y))
            {
                postfix=postfix+y;
                S.pop(x);
                S.stackTop(y);
            }
            S.push(temp);
        } 
    }
      while(S.stackIsEmpty()!=1)
        {
            char y;
            S.stackTop(y);
            postfix=postfix+y;
            S.pop(x);
        }
    cout<<"the infix is: \n"<<input<<endl;
    cout<<"the postfix is\n"<<postfix<<endl;
    evaluatepostfix(postfix);








    return 0;
}