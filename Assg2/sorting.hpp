#ifndef _SORTING_HPP
#define _SORTING_HPP 1

#include <iostream>
#include "seqLinearList.hpp"
#define MAX 100000

namespace cs202 {
  template<class T>
  class Sort{
    public:
      void insertionSort(LinearList<T>& A, int low, int high);
      void bubbleSort(LinearList<T>& A, int low, int high);
      void rankSort(LinearList<T>& A, int low, int high);
      void selectionSort(LinearList<T>& A, int low, int high);
      void mergeSort(LinearList<T>& A, int low, int high);
      void merge( LinearList<T>& A, int low, int mid, int high );
      void quickSort(LinearList<T>& A, int low, int high);
      int partition( LinearList<T>& A, int low, int high );
  };
  
  template< class T >
  void Sort<T>::insertionSort( LinearList<T>& A, int low, int high ){
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
  }
  
  template< class T >
  void Sort<T>::bubbleSort( LinearList<T>& A, int low, int high ){
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
  }

  template< class T >
  void Sort<T>::rankSort( LinearList<T>& A, int low, int high ){
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
  }

  template<class T>
  void Sort<T>::selectionSort( LinearList<T>& A, int low, int high ){
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
  }

  template<class T>
  void Sort<T>::mergeSort( LinearList<T>& A, int low, int high ){
    int mid;
    if( low < high ){
      mid = (low + high)/2;
      mergeSort( A, low, mid );
      mergeSort( A, mid+1, high );
      merge( A, low, mid, high );
    }
  }

  template<class T>
  void Sort<T>::merge( LinearList<T>& A, int low, int mid, int high ){      
    int n1 = mid - low + 1;
    int n2 = high - mid;
    LinearList<T> x(n1+1);
    LinearList<T> y(n2+1);
    for( int i=0; i<n1; i++ )
        x.insert(A[low + i], i+1);
    for( int i=0; i<n2; i++ )
        y.insert(A[mid + 1 + i], i+1);
    int i=0, j=0;
    int k = low;
    while(i<n1 && j<n2){
      if(x[i]<=y[j]){
        A[k]=x[i];
        i++;
        k++;
      }
      else{
        A[k]=y[j];
        j++;
        k++;
      }
    }
    while(i<n1){
      A[k]=x[i];
      k++;
      i++;
    }
    while(j<n2){
      A[k]=y[j];
      k++;
      j++;
    }
  }

  template<class T>
  void Sort<T>::quickSort( LinearList<T>& A, int low, int high ){
    int mid;
    if( low < high ){
      mid = partition( A, low, high );
      quickSort( A, low, mid );
      quickSort( A, mid+1, high );
    }
  }  

  template<class T>
  int Sort<T>::partition( LinearList<T>& A, int low, int high ){
    T pivot = A[ high ];
    int i = low;
    int j = high;
    T temp;
    while(1){
      while( A[j] > pivot ) j--;
      while( A[i] < pivot ) i++;

      if( j>i ){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
      else if( j==i )
        return j-1;
      else
        return j;
    }
  }
}

#endif  /* _SORTING_HPP */
