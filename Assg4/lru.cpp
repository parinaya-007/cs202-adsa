#include "openMap.hpp"
#include <iostream>

using namespace cs202;

int main()
{
	int blockSize;
	cout << "Enter the word size :\n ";
	cin >> blockSize;
	int mainMemory;
	int cacheMemory;
	cout << "Enter the Main Memory size and Cache Memory size : \n";
	cin >> mainMemory;
	cin >> cacheMemory;
	int size = cacheMemory / blockSize;   //size of cache memory in block
	OpenMap<int,int> ht(size);
	int loc, key, index, value;
	bool isFull = true;
	int counter[size];
	for(int i=0; i<size; i++)
		counter[i] = -1;

	int num;
	cout << "Enter no. of locations to read :\n ";
	cin >> num;
	cout << endl;

	while(num){
		cout << "Enter Location No. :\n";
		cin >> loc;
		cout << endl;

		isFull = true;
		for(int i=0; i<size; i++){
			if(counter[i]==-1)
				isFull = false;
		}

		cout << "X1" << endl;

		key = loc / blockSize;
		value = loc;
		if(ht.has(key))
		{
			cout << "X2" << endl;
			ht.put(key, value);
			index = ht.Search(key);
			counter[index] = 0;
			for(int i=0; i<size; i++){
				if(counter[i]!=-1 && i!=index)
					counter[i] += 1;
			}
		}

		else if((!ht.has(key)) && (!isFull)){
			// index = ht.openHash(key);
			// search
			cout << "X3" << endl;
			ht.put( key, value );
			// to get index return from insertH
			int ind = ht.Search(key);
			counter[ind] = 0;

			for(int i=0; i<size; i++){
				if(counter[i]!=-1 && i!=ind)
					counter[i] += 1;
			}
		}

		else{	// !has(key) && isFull
			cout << "X4" << endl;
			int max = counter[0];
			int max_index = 0;
			for(int i=0; i<size; i++){
				if(max < counter[i]){
					max = counter[i];
					max_index = i;
				}
			}

			ht.insertAt(max_index, key, value);

		}

		cout << "X5" << endl;

		cout << "Counter[] :" << endl;
		for(int i=0; i<size; i++)
			cout << counter[i] << endl;
		ht.display();
		num--;
	}

	return 0;
}
