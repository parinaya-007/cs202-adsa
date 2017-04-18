// Driver Program for testing `seqLinearList` class
// Author: Parinaya Chaturvedi
// Roll Number: B15120
#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
using namespace cs202;

int main(int argc, char const *argv[])
{
	int n, v;
	cout << "Enter number of Elements to be sorted :";
	cin >> n;
	cout << endl;
	LinearList<int> list(n);

	cout << "Enter the values to be sorted :" << endl;
	for(int i=0; i<n; i++){
		cin >> v;
		list.insert(v, i+1);
	}
	
	//Modification in Linear List
	cout << endl;
	cout << "List Modification Choices :" << endl;
	cout << "1.  at(k)           : Return the element in the list at position k" << endl;
	cout << "2.  push_back(item) : Appending an element to the LinearList" << endl;
	cout << "3.  empty()         : Returns true if LinearList is empty" << endl;
	cout << "4.  size()          : Returns the size of the LinearList" << endl;
	cout << "5.  capacity()      : Returns the capacity of the LinearList" << endl;
	cout << "6.  fill(item)      : Fills all the elements with a default value 'item'" << endl;
	cout << "7.  resize(n)       : Resizes the LinearList" << endl;
	cout << "8.  find(item)      : Find the index of first occurence of an item in the list" << endl;
	cout << "9.  erase(item)     : Remove all occurences of an item in the list" << endl;
	cout << "10. erase_pos(pos)  : Remove the item in the list at position pos" << endl;
	cout << "11. insert(item, k) : Insert item at position k" << endl;
	cout << "12. display()       : Displays every element in the list" << endl;
	cout << "13. Exit" << endl;
	cout << endl;

	int l, k, x;
	while(1){
		cout << "Enter Choice :";
		cin >> l;
		switch (l){
			case 1: cout << "k = ";
					cin >> k;
					cout << "Element = ";
					cout << list.at(k) << endl;
					break;
			case 2: cout << "item = ";
					cin >> k;
					list.push_back(k);
					cout << "Appended List : ";
					list.display();
					cout << endl;
					break;
			case 3: if(list.empty()) cout << "True" << endl;
					else cout << "False" << endl;
					break;
			case 4: cout << "Size = " << list.getSize() << endl;
					break;
			case 5: cout << "Capacity = " << list.getCapacity() << endl;
					break;
			case 6: cout << "item = ";
					cin >> k;
					list.fill(k);
					cout << "Filled List with default value : ";
					list.display();
					break;
			// case 7: 
			// 		break;
			case 8: cout << "item = ";
					cin >> k;
					x = list.find(k);
					cout << "Element present at index = " << x;
					cout << endl;
					break;
			case 9: cout << "item = ";
					cin >> k;
					list.erase(k);
					cout << "Erased List at " << k << " : ";
					list.display();
					cout << endl;
					break;
			case 10: cout << "pos = ";
					 cin >> k;
					 list.erase_pos(k);
					 cout << "Erased List at pos " << k << " : ";
					 list.display();
					 break;
			case 11: cout << "item = ";
					 cin >> x;
					 cout << "k = ";
					 cin >> k;
					 list.insert(x, k);
					 cout << "List with inserted element : ";
					 list.display();
					 cout << "Current length of list : ";
					 cout << list.getSize();
					 cout << endl;
					 break;
			case 12: list.display();
					 break;
			case 13: exit(0);
					break;
			default: cout << "Enter a Choice!" << endl;
		}
		cout << endl;
	}
	return 0;
}