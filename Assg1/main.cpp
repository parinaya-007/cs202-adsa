#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "seqLinearList.hpp"
#include "sorting.hpp"

int main(){
	int n, v;
	cout << "Enter number of Elements to be sorted :";
	cin >> n;
	cout << endl;
	LinearList<int> list(n);	//object of Sort class

	cout << "Enter the values to be sorted :" << endl;
	for(int i=0; i<list.maxSize(); i++){
		cin >> v;
		list.insert(i-1, v);
	}
	
	//Modification in Linear List
	int l;
	cout << endl;
	cout << "List Modification Choices :" << endl;
	cout << "1. Check whether list is empty" << endl;
	cout << "2. Return the actual length of list" << endl;
	cout << "3. Return the Maximum Size of list" << endl;
	cout << "4. Return list element at position 'k'" << endl;
	cout << "5. Find if the element present in the list at position 'k' and store it in 'x'" << endl;
	cout << "6. Search for 'x' in list, if present return position, else return -1" << endl;
	cout << "7. Delete Element at position 'k' after storing it in 'x'" << endl;
	cout << "8. Insert 'x' at position next to 'k'" << endl;
	cout << "9. Exit" << endl;
	cout << endl;

	int k, x, intTemp;
	bool temp;
	char c;
	while(1){
		cout << "y -> continue modifying list" << endl;
		cout << "n -> quit modifying and move to sorting" << endl;
		cout << "Do you want to continue modifying list? (y/n) : ";
		cin >> c;
		if(c == 'y') continue;
		else if(c == 'n') break;
		cout << "Enter Choice :";
		cin >> l;
		switch (l){
			case 1: if(list.isEmpty())
						cout << "True" << endl;
					else
						cout << "False" << endl;
					break;
			case 2: cout << list.length() << endl;
					break;
			case 3: cout << list.maxSize() << endl;
					break;
			case 4: cout << "k = ";
					cin >> k;
					cout << endl;
					cout << "Element = ";
					cout << list.returnListElement(k) << endl;
					break;
			case 5: cout << "k = ";
					cin >> k;
					cout << endl;
					temp = list.find(k, x);
					if(temp) cout << "Element present =" << x;
					else cout << "Element not present!";
					cout << endl;
					break;
			case 6: cout << "x = ";
					cin >> x;
					intTemp = list.search(x);
					if(intTemp != false){
						cout << "Position = ";
						cout <<  intTemp << endl;
					}
					else
						cout << "Element not found!" << endl;
					break;
			case 7: cout << "k = ";
					cin >> k;
					cout << endl;
					list.deleteElement(k, x);
					cout << "Deleted Element :";
					cout << x << endl;
					cout << "Current Length of List :";
					cout << list.length() << endl;
					break;
			case 8: cout << "x = ";
					cin >> x;
					cout << endl;
					cout << "k = ";
					cin >> k;
					cout << endl;
					list.insert(k, x);
					cout << "Current length of list :";
					cout << list.length();
					break;
			case 9: exit(0);
					break;
			default: cout << "Enter a Choice!" << endl;
		}
		cout << endl;
	}

	int f;
	cout << endl;
	cout << "Choose Sorting Algorithm :" << endl;
	cout << "1. Insertion Sort" << endl;
	cout << "2. Bubble Sort" << endl;
	cout << "3. Rank Sort" << endl;
	cout << "4. Selection Sort" << endl;
	cout << "5. Exit" << endl;
	cout << endl;

	int start, end;
	double time;
	Sort<int> sort;		//object of Sort class
	while(1){
		cout << "Enter Choice :";
		cin >> f;
		switch (f){
			case 1:	start = clock();
					sort.insertionSort(list, 0, list.maxSize()-1);
					end = clock();
					time = (((double)(end - start)/CLOCKS_PER_SEC)) * 1000;
					cout << "Time Elapsed :" << time << "s"<< endl;
					break;
			case 2: start = clock();
					sort.bubbleSort(list, 0, list.maxSize()-1);
					end = clock();
					time = (((double)(end - start)/CLOCKS_PER_SEC)) * 1000;
					cout << "Time Elapsed :" << time << "s"<< endl;
					break;
			case 3: start = clock();
					sort.rankSort(list, 0, list.maxSize()-1);
					end = clock();
					time = (((double)(end - start)/CLOCKS_PER_SEC)) * 1000;
					cout << "Time Elapsed :" << time << "s"<< endl;
					break;
			case 4: start = clock();
					sort.selectionSort(list, 0, list.maxSize()-1);
					end = clock();
					time = (((double)(end - start)/CLOCKS_PER_SEC)) * 1000;
					cout << "Time Elapsed :" << time << "s"<< endl;
					break;
			case 5: exit(0);
			default: cout << "Invalid choice!"  << endl;
					 break;
		}
		cout << endl;
	}
	return 0;
}
