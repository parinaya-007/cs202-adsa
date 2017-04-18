#include<iostream>
#include "stack.hpp"
using namespace std;
using namespace sandq;
int main()
{
    stack<int> s;
    int i,j;
    i=1;
    while(i!=7)
    {
        cout<<"1.)Push\n2.)Pop\n3.)Display\n4.)Get Top\n5.)Size\n6.)Is Stack Empty\n7.)Exit\n";
        cout<<"Enter Your choice\n";
        cin>>i;
        switch(i)
        {
            case 1: cout<<"Enter The element you want to insert\n";
                    cin>>j;
                    s.push(j);
                    break;
            case 2: s.pop();
                    cout<<"Element Popped\n";
                    break;
            case 3: s.display();
                    break;
            case 4:cout<<s.top()<<"\n";
                    break;
            case 5:cout<<"The Size is \n";
                    cout<<s.size()<<"\n";
                    break;
            case 6:if(s.empty()==1)
                    cout<<"Empty\n";
                    else
                        cout<<"Not Empty\n";
                    break;
            case 7:break;
            default:cout<<"Wrong Choice\n";
                    break;

        }
    }
    return 0;
}
