#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 1

#include <iostream>
#include <string.h>
using namespace std;

namespace cs202 {
    template<typename T>
    class LinearList{
      private:
        T* buffer;
        unsigned int size;
        unsigned int capacity;
      public:
        // Default Constructor
        // Creates a zero sized LinearList
        LinearList();

        // Constructor with size as input
        LinearList(const int& isize);                   

        // Constuctor with size and default value as input
        LinearList(const int& isize, const T& ival);    

        // Default Destructor
        ~LinearList();                                  

        // Accessing an element of the LinearList using operator
        inline T& operator[](const int& i);         

        // Return the element in the list at position k
        inline T& at(const int& k);         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const T& item);              

        // Returns true if LinearList is empty
        bool empty();

        //Delete list
        void deletelist();                          

        // Returns the size of the LinearList
        unsigned int getSize();                                 

        // Returns the capacity of the LinearList
        unsigned int getCapacity();                                 

        // Fills all the elements with a default value
        void fill(const T& item);                   

        // Resizes the LinearList
        void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(const T& item);

        // Remove all occurences of an item in the list
        void erase(const T& item);

        // Remove the item in the list at position pos
        void erase_pos(const int& pos);

        // Insert item at position k
        void insert(const T& item, const int& k);

        // Displays every element in the list
        void display();

        // Iterator class for LinearList
        // This should be used to traverse the LinearList
        // See std::vector<T>::iterator for more understanding
        // on how iterators work
        // class iterator{                      
        //   private:
        //     T* elem_;
        //   public:
        //     iterator();
        //     iterator(T* ptr);
        //     ~iterator();
        //     T& operator*();
        //     void operator=(T *ptr);
        //     void operator=(iterator iter);
        //     void operator++();
        //     void operator--();
        //     bool operator!=(T* ptr);
        //     bool operator==(T* ptr);
        //     bool operator!=(iterator iter);
        //     bool operator==(iterator iter);
        //     iterator operator+(int i);
        //     iterator operator-(int i);
        // };
        // iterator begin();                     
        // iterator end();
    };

    template<typename T>
    LinearList<T>::LinearList(){
        buffer = new T;
        size = 0;
    }

    template<class T>
    LinearList<T>::LinearList(const int& ListSize){
        buffer = new T[ListSize];
        size = 0;
        capacity = ListSize;
    }

    template<class T>
    LinearList<T>::LinearList(const int& ListSize, const T& ival){
        buffer = new T[ListSize];
        capacity = ListSize;
        size = 0;
        for(int i=0; i<ListSize; i++)
            buffer[i] = ival;
    }

    template<class T>
    LinearList<T>::~LinearList(){
        delete buffer;
    }

    template<class T>
    inline T& LinearList<T>::operator[](const int& i){
        return buffer[i];
    }

    template<class T>
    inline T& LinearList<T>::at(const int& k){
        return buffer[k-1];
    }

    template<class T>
    void LinearList<T>::push_back(const T& item){
        size++;
        // capacity++;
        buffer[size-1] = item;
    }

    template<class T>
    bool LinearList<T>::empty(){
        return (buffer==NULL) ? true : false;
    }

    template<class T>
    void LinearList<T>::deletelist(){
        buffer = new T;
    }

    template<class T>
    unsigned int LinearList<T>::getSize(){
        return size;
    }

    template<class T>
    unsigned int LinearList<T>::getCapacity(){
        return capacity;
    }

    template<class T>
    void LinearList<T>::fill(const T& item){
        for( int i=0; i<size; i++ )
            buffer[i] = item;
    }

    template<class T>
    void LinearList<T>::resize(const int& n){
    int bigger;
        T* old_buffer = buffer;
        buffer = new T[ n ];
        if( size > n )
            bigger = n;
        else
            bigger = size;
        for( int i = 0; i < bigger; i++ )
        {
            buffer[ i ] = old_buffer[ i ];
        }
        delete [] old_buffer;
        size = bigger;
    }

    template<class T>
    int LinearList<T>::find(const T& item){
        int flag = 0;
        for( int i=0; i<size; i++ ){
            if( buffer[i]==item ){
                flag = 1;
                return i;
            }
        }
        if(flag==0) return size;
    }

    template<class T>
    void LinearList<T>::erase(const T& item){
    int i,k;
        for(i=0;i<size;i++)
        {
          if(buffer[i] == item)
          {
            k=i;
            for(k;k<size-1;k++)
            {
              buffer[k] = buffer[k+1];
            }
            size--;
            i--;
          }
        }
    }

    template<class T>
    void LinearList<T>::erase_pos(const int& pos){
        if( pos <= size && pos >= 1 ){
            for( int i=pos-1; i<size-1; i++ )
                buffer[i] = buffer[i+1];
            size--;
        }
    }

    template<class T>
    void LinearList<T>::insert(const T& item, const int& k){
        int i;
        for(i=size;i>=k;i--)
        {
            buffer[i]=buffer[i-1];
        }
        buffer[k-1]=item;
        size++;
    }

    template<class T>
    void LinearList<T>::display(){
        for(int i=0; i<size; i++)
            cout << buffer[i] << " ";
        cout << endl;
    }
}

#endif  /* _SEQ_LINEAR_LIST */
