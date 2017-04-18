#include "list.hpp"
#include<iostream>
using namespace std;
using namespace cs202;
int main()
{
    list <int> x;
    list<int> k;
    int i=1;
    int j;
    while(i!=9)
    {
        cout<<"1.) Append a value at the End\n2.) Get Top Element\n3.) Print List\n4.) Get Length\n5.) Check if List is Empty\n";
        cout<<"6.) Add value to the start of List\n7.) Delete an element \n8.) Append Given List at the end of new list\n9.)Exit\n";
        cout<<"Enter Your Choice\n";
        cin>>i;
        switch(i)
        {
            case 1:cout<<"Enter Value you want to enter\n";
                    cin>>j;
                    x.append(j);
                    break;
            case 2:cout<<x.top()<<"\n";
                    break;
            case 3:x.print();
                    break;
            case 4:cout<<x.length()<<"\n";
                    break;
            case 5:if(x.empty()==0)
                    cout<<"Not Empty\n";
                    else
                    cout<<"Empty\n";
                    break;
            case 6:cout<<"Enter Value you want to enter\n";
                    cin>>j;
                    x.cons(j);
                    break;
            case 7: cout<<"Enter Value you want to delete\n";
                    cin>>j;
                    x.remove(j);
                    break;
            case 8:cout<<"Appending List X at the end of list Y\n";

                    k.append(x);
                    k.print();
                    break;
            case 9: break;
            default: cout<<"\n\n Wrong choice\n";
                    break;



        }
    }
    return 0;
}
