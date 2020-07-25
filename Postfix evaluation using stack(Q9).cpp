//postfix evaluation

#include<iostream>
#include<stdlib.h>
using namespace std;

int top=-1;
int ans[10];


void push(int num){
    
    if(top==9){
        cout<<"STACK is FULL."<<endl;
        return;
    }
    ++top;
    ans[top]=num;
    
}

void pop(){
    
    
    if(top==-1){
        cout<<"STACK is EMPTY."<<endl;
        return;
    }
    
    top--;
}


int main()
{
    int *dig;       //single dimensional array
    int x;
    char ch,ch1;
    char *stack;
    int size;
    
    
    cout<<"\nEnter the size of the postfix expression: ";
    cin>>size;
    stack=new char[size];
    dig=new int[size];
    
    
    cout<<"\nEnter the postfix expression:\n";
    for(int i=0;i<size;i++)
    {
        cin>>stack[i];
    }
    
    cout<<"\nPostfix Expression entered is: ";
    for(int i=0;i<size;i++)
        cout<<stack[i]<<" ";
    cout<<"\n";
    
    int j=0,k=0;
    
    for(int i=0;i<size;i++)
    {
        if(isdigit(stack[i]))
        {
            ch1=stack[i];
            x=(int)ch1;
            
            dig[j]=x-48;           //in ASCII code, the numbers (digits) start from 48. dig[j]=(int)ch1-48;
            push(dig[j]);
            j++;
        }
        else
        {
            ch=stack[i];
            switch(ch)
            {
                case '+': ans[top-1]=ans[top-1]+ans[top];
                          pop();
                          break;
                    
                case '-': ans[top-1]=ans[top-1]-ans[top];
                          pop();
                          break;
                    
                case '*': ans[top-1]=ans[top-1]*ans[top];
                          pop();
                          break;
                    
                case '/': ans[top-1]=ans[top-1]/ans[top];
                          pop();
                          break;
                    
                case '^': ans[top-1]=ans[top-1]^ans[top];
                          pop();
                          break;

                default: cout<<"\nWrong Operator";
                         exit(0);
                         break;
            }
            
            
            k++;
        }
       
    }
    
    cout<<"\nSolution of the postfix expression: "<<ans[0];
   // getch();
    return 0;
}
