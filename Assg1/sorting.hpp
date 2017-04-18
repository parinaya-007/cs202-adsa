#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"

template<class Item>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<Item>& A, int low, int high);
		void bubbleSort(LinearList<Item>& A, int low, int high);
	 	void rankSort(LinearList<Item>& A, int low, int high);
        void selectionSort(LinearList<Item>& A, int low, int high);

};

//Insertion Sort
template<class Item>
void Sort<Item>::insertionSort(LinearList<Item>& A, int low, int high){

	int key, i;
	for (int j = low+1; j<=high; j++){
		key = A[j];
		i = j-1;
		while (i >= 0 && A[i]>key){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}

//displaying sorted elements
	for(int i=low; i<=high; i++){
		cout << A[i];
		cout << " ";
	}
	cout << endl;

}

//Bubble Sort
template<class Item>
void Sort<Item>::bubbleSort(LinearList<Item>& A, int low, int high){
	
	int j = high, temp;
	while(j>=low+1){
		for(int i=low; i<=j-1; i++){
			if(A[i]>A[i+1]){
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
			}
		}
		j--;
	}

//displaying sorted elements
	for(int i=low; i<=high; i++){
		cout << A[i];
		cout << " ";
	}
	cout << endl;

}

//Rank Sort
template<class Item>
void Sort<Item>::rankSort(LinearList<Item>& A, int low, int high){

	int R[high+1];
	int U[high+1];
	for(int i=0; i<=high; i++)
		R[i] = 0;
	for(int j=low+1; j<=high; j++){
		for(int i=low; i<=j-1; i++){
			if(A[j]<=A[i])
				R[i]++;
			else
				R[j]++;
		}
	}
	for(int i=low; i<=high; i++)
		U[R[i]] = A[i];
	for(int i=low; i<=high; i++)
		A[i] = U[i];

//displaying sorted elements
	for(int i=low; i<=high; i++){
		cout << A[i];
		cout << " ";
	}
	cout << endl;

}

//Selection Sort
template<class Item>
void Sort<Item>::selectionSort(LinearList<Item>& A, int low, int high){

	bool sorted = false;
	int j = high, pos, temp;
	while(j>low && sorted==false){
		pos = low;
		sorted = true;
		for(int i=low+1; i<=j; i++){
			if(A[pos]<=A[i])
				pos = i;
			else 
				sorted = false;
		}
		temp = A[pos];
		A[pos] = A[j];
		A[j] = temp;
		j--;  
	}

//displaying sorted elements
	for(int i=low; i<=high; i++){
		cout << A[i];
		cout << " ";
	}
	cout << endl;

}

#endif