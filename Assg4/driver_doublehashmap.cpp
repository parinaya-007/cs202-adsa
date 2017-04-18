#include "DoubleHashMap.hpp"
//#include "OpenMap.hpp"
#include <stdlib.h>
#include <iostream>
//#include<sstream>
//#include<string>
using namespace std;
using namespace cs202;

int main()
{
	DoubleHashMap< int, int> d(5);
	//d[1]=2;
	//cout<<d[1];
	//d.put(2,3);
	//d.put(10,3);d.put(9,3);d.put(8,3);d.put(7,3);d.put(4,3);
	//d.put(3,4);
	//d.put(16,6);
	//d.rehash();
    // d.display();


	int opt=0,val;
	int key;

	while ( opt != 5 )
	{
		cout << "\nChoose an option[1-5] from the list below." << endl;
		cout << "1.  Add value to the hash table. " << endl;
		cout << "2.  Remove value from hash table." << endl;
		cout << "3.  Check if a key is present." << endl;
		cout << "4.  Get a value associated to a key." << endl;
		cout << "5.  exit." << endl;

		cin >> opt;

		switch(opt)
		{
			case 1:	cout << "Enter the value of the element : \n";
					cin >> val;
					cout<< "Enter the key associated : \n";
					cin >> key;
					d.put(key,val);
	//				d.display();
					break;

			case 2:	cout << "Enter the key to be removed :\n ";
					cin >> key;
					d.remove(key);
					break;

			case 3:	cout << "Enter the key to be checked :\n ";
					cin >> key;
					bool b;
					b = d.has(key);
					if(b)
						cout<<"The key is present.\n";
					else
						cout<<"The key is not present.\n";
					break;

			case 4:	cout << "Enter the key whose value needed :\n ";
					cin >> key;
					val = 0;
					val = d.get(key);
					if(val)
						cout<<"The value associated with key "<<key<<" is :"<<val<<"\n";
					break;

			case 5:	cout << "Exiting\n";
							break;

			default:
                    cout << "Please enter a valid choice\n";
		}
	}

}
