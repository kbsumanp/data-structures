//reverse a stack using two additional stack 

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> S, S1, S2;
    S.push(1), S.push(2), S.push(3),S.push(4),S.push(5);

    cout << "The top element of S is: " << S.top() << endl;

    while (!S.empty())
     {
        S1.push(S.top());
        S.pop(); 
     }
    while (!S1.empty()) 
       {
        S2.push(S1.top()); 
        S1.pop();
       }
    while (!S2.empty()) 
       {
        S.push(S2.top()); 
        S2.pop();
       }

    cout << "The top element of S is now: " << S.top() << endl;

    return 0;
}
