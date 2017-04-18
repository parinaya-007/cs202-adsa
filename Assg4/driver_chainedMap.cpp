
#include "ChainedMap.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace cs202;

int main( )
{
	ChainedMap< int, int > d;
	int opt=0,val,key;

	while ( opt != 5 )
	{
		cout << "Choose an option[1-5] from the list below." << endl;
		cout << "1.  Add value to the hash table. " << endl;
		cout << "2.  Remove value from hash table." << endl;
		cout << "3.  Check if a key is present." << endl;
		cout << "4.  Get a value associated to a key." << endl;
		cout << "5.  exit." << endl;

		cin >> opt;

		switch(opt)
		{
			case 1:	cout << "Enter the value of the element : ";
					cin >> val;
					cout<< "Enter the key associated : ";
					cin >> key;
					d.put(key,val);
					break;

			case 2:	cout << "Enter the key to be removed : ";
					cin >> key;
		//			d.Remove(key);1

					break;

			case 3:	cout << "Enter the key to be checked : ";
					cin >> key;
					bool b;
//					b = d.has(key);
					if(b)
						cout<<"The key is present.";
					else
						cout<<"The key is not present.";
					break;

			case 4:	cout << "Enter the key whose value needed : ";
					cin >> key;
					val = 0;
					val = d.get(key);
					if(val)
						cout<<"The value associated with key - "<<key<<" is : "<<val;
					break;

			case 5:	cout << "Exiting";
							break;

			default:
							cout << "Please enter a valid choice";
		}
	}

}
