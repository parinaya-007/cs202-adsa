#include "seqLinearList.hpp"
#include "sorting.hpp"
#include <stdlib.h>
#include "timer.hpp"
#include <fstream>
using namespace cs202;

int main(int argc, char const *argv[])
{	
	int len, val, pos, sw, choice, n;
	ofstream outfile;
	outfile.open("Sorting_Time.txt", ofstream::app);
	timer t;
	Sort<int> sort;

	if(argc==2){
		choice = atoi(argv[1]);
		cin >> len;
		LinearList<int> list(len);
		for(int i=0; i<len; i++){
			cin >> val;
			list.push_back(val);
		}
			switch(choice){
				case 1: cout << "rank sort : " << endl;
						t.start();
						sort.rankSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : rank sort : " << endl;
						t.print();
						outfile << "Time : Rank Sort : " << t.last_timing() << "\n";
						break;
				case 2: cout << "bubble sort : " << endl;
						t.start();
						sort.bubbleSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : bubble sort : " << endl;
						t.print();
						outfile << "Time : Bubble Sort : " << t.last_timing() << "\n";
						break;
				case 3: cout << "insertion sort : " << endl;
						t.start();
						sort.insertionSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : insertion sort : " << endl;
						t.print();
						outfile << "Time : Insertion Sort : " << t.last_timing() << "\n";
						break;
				case 4: cout << "selection sort : " << endl;
						t.start();
						sort.selectionSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : selection sort : " << endl;
						t.print();
						outfile << "Time : Selection Sort : " << t.last_timing() << "\n";
						break;
				case 5: cout << "merge sort : " << endl;
						t.start();
						sort.mergeSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : merge sort : " << endl;
						t.print();
						outfile << "Time : Merge Sort : " << t.last_timing() << "\n";
						break;
				case 6: cout << "quick sort : " << endl;
						t.start();
						sort.quickSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : quick sort : " << endl;
						t.print();
						outfile << "Time : Quick Sort : " << t.last_timing() << "\n";
						break;
				default: cout << "Invalid Choice!" << endl;
						 return 0;
						 break;
			}
		outfile.close();
	}

	else if(argc==1){
		cout << "Enter max no. of elements : ";
		cin >> len;
		cout << "Enter actual no. of elements : ";
		cin >> n;

		LinearList<int> list(len);
		for(int i=0; i<n; i++){
			cout << "Enter Element : " << i+1 ;
			cin >> val;
			list.insert(val, i+1);
		}

			cout<<"\n\nChoose one of the following options : "<<endl;
			cout<<"1.Rank Sort\n2.Bubble Sort\n3.Insertion Sort\n4.Selection Sort\n5.Merge Sort\n6.Quick Sort\n7.Exit\n";
			cout<<"\nLinearList << ";
			cin >> sw;
			switch(sw){
				case 1: cout << "rank sort : " << endl;
						t.start();
						sort.rankSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : Rank sort : \n";
						t.print();
						list.display();
						break;
				case 2: cout << "bubble sort : " << endl;
						t.start();
						sort.bubbleSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : bubble sort : \n";
						t.print();
						list.display();
						break;
				case 3: cout << "insertion sort : " << endl;
						t.start();
						sort.insertionSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : insertion sort : \n";
						t.print();
						list.display();
						break;
				case 4: cout << "selection sort : " << endl;
						t.start();
						sort.selectionSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : selection sort : \n";
						t.print();
						list.display();
						break;
				case 5: cout << "merge sort : " << endl;
						t.start();
						sort.mergeSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : merge sort : \n";
						t.print();
						list.display();
						break;
				case 6: cout << "quick sort : " << endl;
						t.start();
						sort.quickSort(list, 0, list.getSize()-1);
						t.stop();
						cout << "time : quick sort : \n";
						t.print();
						list.display();
						break;
				default: cout << "Invalid Choice!\n" << endl;
						 return 0;
						 break;
			}
	}
	return 0;
}