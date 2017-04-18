#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
using std::cout ;
using std::cin ;
using std::endl;
namespace cs202
{

    template<class N>
    class ChainNode
    {
        template<typename T> friend class list;
        template<class Key, class Value> friend class ChainedMap;

        private:
            N data;
            ChainNode<N> *link;    
    };
    template<class T>
    class list
    {
      private:
        ChainNode<T> *first ; 
        ChainNode<T> *last ;  
        int len ;
 
      public:
        list();
        list(const list<T> & x);
        ~list();
        void append(const T& value);
        inline int length();
        inline bool empty();
        void cons(const T& value);
        void remove(const T & x);
        void append(list<T>& x);
        void print();
        ChainNode<T>* getfirst();


    };

    template<typename T> list<T>::list()
    {
        first = NULL ;
        last  = NULL ;
        len   = 0 ;
    }

    template<typename T> list<T>::~list()
    {
        ChainNode<T>* next ;
        while(first)
        {
            next =first->link ;
            delete first ;
            first = next ;
        }
    }
    template<typename T> list<T>::list(const list<T> & x)
    {
        
        ChainNode<T> *temp = x.first;
        while(temp)
        {
            this->append(temp->data);
            temp =temp->link ; 
        }
        len=x.len;
    }
    template<typename T> void list<T>::append(const T& value)
    {
        ChainNode<T>* newnode = new ChainNode<T> ;
        if(first == NULL)
        {       
            newnode->data = value;
            newnode->link = NULL;
            first = newnode;
            last = newnode;
        }
        else
        {
            newnode->data = value;
            newnode->link = NULL;
            last->link = newnode ;
            last = newnode ;
        }
        len++ ;
    } 

    template<typename T> inline int list<T>::length()
    {
        return len ;
    }
    template<typename T>  inline bool list<T>::empty()
    {
        if(len==0)
            return true ;
        else 
            return false ;
    }  
    
    template<typename T> void list<T>:: remove(const T & x)
    {
        ChainNode<T>* next ;
        if(first->data == x )
        {
            next = first->link ;
            delete first ;
            first = next ;
            len--;
            if(first==NULL)
                last==NULL ;
            return ; 
        }
        next = first ;
        while(next->link)
        {
            if(next->link->data == x)
            {
                delete next->link ;
                next->link = next->link->link;
                if(next->link == NULL)
                {
                    last = next;
                }
                
                len--;
                return  ;
            }
            else
                next=next->link ;
        }
    } 

    template<typename T> void list<T>::cons(const T& value)
    {
        ChainNode<T>* newnode = new ChainNode<T> ;
        if(first == NULL)
        {       
            newnode->data = value;
            newnode->link = NULL;
            first = newnode;
            last = newnode;
        }
        else
        {
            newnode->data = value;
            newnode->link = first;
            first = newnode ; 
        }
        len++;
    }  
    template<typename T> void list<T>::append(list<T>& x)
    {
        last->link = x.first;
        len+=x.length();
        last = x.last;

    }
    template<typename T> void list<T>::print()
    {
        ChainNode<T>* next ;
        next=first ;
        while(next)
        {
            cout<<next->data<<" ";
            next = next->link ;
        }
        cout<<endl;
    }
    template<typename T> ChainNode<T>* list<T>::getfirst()
    {
        return first ; 
    }
}
#endif