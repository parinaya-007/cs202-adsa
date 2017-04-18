#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP 1

#include <iostream>
#include <string.h>
#include <memory>

using namespace std;
namespace cs202{
template<class Item>
class LinearList{

	private:
		unsigned int capacity_;
		Item *buffer_;
        unsigned int size_;
      //  int capacityinc_;
	public:
		/* Default constructor.
		 * Should create an empty list that not contain any elements*/
		LinearList()
        {
            size_=0;
            capacity_=0;
        //    capacityinc_=10;
        }
        LinearList(const int& MaxListSize);
        LinearList(const int & MaxListSize,const Item & ival);
        ~LinearList(){}
        //inline function
        Item& operator[](const int& i) //return i'th buffer_ of list
        {
            return buffer_[i];
        }
        //inline function
        Item&  at(const int &k)
		{
		    return buffer_[k];
		}
		void push_back(const Item& t);
		bool empty();
		void display();
        unsigned int size();
        unsigned int capacity();
        void fill(const Item& t);
        void resize(const int& n);
        int  find(Item& x);
        void erase(const Item& t);
        void erase_pos(const int& x);
        void  insert(const Item& x,const int  &k);
};
template<class Item>
LinearList<Item>::LinearList(const int& MaxListSize)
		{
		    capacity_=MaxListSize;
		    buffer_= new Item[capacity_];
            //capacityinc_=capacity_/2;
		    size_=0;

		}
template<class Item>
LinearList<Item>::LinearList(const int & MaxListSize,const Item & ival)
        {
		    capacity_=MaxListSize;
		    buffer_=new Item[capacity_];
		    size_=MaxListSize;
		    //capacityinc_=capacity_/2;
		    for(int i=0;i<capacity_;i++)
                buffer_[i]=ival;
		}
template<class Item>
bool LinearList<Item>::empty()
		{
		    return !size_;
		}
template<class Item>
void LinearList<Item>::display()
		{
		    int i=0;
		    cout<<"Elements are as follows:\n";
		    for(i=0;i<size_;i++)
            {
                cout<<buffer_[i]<<" ";
            }
		}
template<class Item>
unsigned int LinearList<Item>::size()
		{
		    return size_;
		}
template<class Item>
unsigned int  LinearList<Item>::capacity()
		{
		    return capacity_;
		}
template<class Item>
void LinearList<Item>::fill(const Item & t)
        {
    int i;
    for(i=0;i<size_;i++)
        buffer_[i]=t;
}
template<class Item>
int LinearList<Item>:: find(Item& x)
		{
            int i=0;
            for(i=0;i<size_;i++)
            {
                if(buffer_[i]==x)
                return i;
            }
            return size_;

		}
template<class Item>
void LinearList<Item>:: erase_pos(const int& x)
        {
    int i=x;
    if(i<1&&i>size_)
        cout<<"Enter Valid x\n";
    else
        {
            i=x;
            for(i;i<size_;i++)
                buffer_[i-1]=buffer_[i];
            size_--;
        }
}
template<class Item>
void LinearList<Item>:: insert(const Item& x,const int & k)
		{
		    int i;
		    for(i=size_;i>=k;i--)
            {
                buffer_[i]=buffer_[i-1];
            }
            buffer_[k-1]=x;
            size_++;
		}
template<class Item>
void LinearList<Item>::erase(const Item& t)
{
    int i,k;
    for(i=0;i<size_;i++)
    {
        if(buffer_[i]==t)
        {
            k=i;
            for(k;k<size_-1;k++)
            {
                buffer_[k]=buffer_[k+1];
            }
            size_--;
            i--;
        }
    }
}
template<class Item>
void LinearList<Item>::resize(const int& n)
{
               int i;
            Item * temp = new Item[n];
            if(n < size_)
            {
                size_ = n;
                for(int i = 1; i <= n; i++)
                    temp[i] = buffer_[i];
            }

            if(n > size_ && n <= capacity_ )
            {
                capacity_ = n;
                // for(i = 1; i <= size_; i++)
                // {
                //     temp[i] = buffer_[i];
                // }
                // for(i = size_; i <= n; i++)
                //     temp[i] = 0;
                // size_ = n;
            }
            if(n > capacity_)
            {
                for(i = 1; i <= size_; i++)
                {
                    temp[i] = buffer_[i];
                }
                capacity_ = n;
            }
            buffer_ = temp;
  cout<<"\n";
}
template<class Item>
void LinearList<Item>::push_back(const Item& t)
        {

           if(size_>=capacity_)
            {
                capacity_=capacity_*2;

               // unique_ptr<Item[]> new_list=make_unique<Item[]>(capacity_);
                Item * B=new Item[capacity_];
                for(int i=0;i<size_;i++)
                        {
                            B[i]=buffer_[i];
                         //   cout<<B[i];
                        }

                buffer_=B;

            }
            buffer_[size_]=t;
            size_++;
        }
}
#endif
