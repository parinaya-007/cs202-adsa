#ifndef LIST_HPP
#define LIST_HPP 1

#include <iostream>
using namespace std;
namespace cs202
{
    template<class T>
    class Node
    {
        T data;
        Node<T>* next;
        
        public:
            Node(){}            //Default Constructor
            T getdata(){
                return data;
            }

            void setdata(const T &r){
                data = r;
            }

            void setnext(Node* next){
                this->next = next;
            }

            Node* getnext(){
                return next;
            }
    };
    /*
template<class Item>
Node<T> ::getdata()
{
    return data;
}
template<class T>
void Node<T>::setdata(const T & r)
{
    data=r;
}
template<class T>
void Node<T> ::setnext(Node * next)
{
    this->next=next;
}
template<class T>
Node* Node<T>::getnext()
{
    return next;
}  */
    template<class T>
    class list
    {
        Node<T>* head;
        int len;
        /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */
        public:

            list(){
                head = NULL;
                len = 0;
            }

            Node<T>* gethead(){
                return head;
            }
            /*
             * Seondary constructor.
             * Creates a new list which is a copy of the provided list.
             */
            list(list<T> &x)                //given is const list<T> &x_______________________________________________________
            {
                Node<T> *ptr, *ptr1, *ptr2;
                int i = 0;
                head = x.gethead();
                len = 0;
                ptr = head;

                if(head==NULL)
                    len=0;

                else{
                    while(ptr!=NULL)
                    {
                        ptr2 = new Node<T>();
                        len++;
                        int r = ptr->getdata();
                        ptr2->setdata(r);
                        ptr = ptr->getnext();
                        if(i==0){
                            head = ptr1 = ptr2;
                            i++;
                        }
                        else{
                            ptr1->setnext(ptr2);
                            ptr1 = ptr1->getnext();
                        }
                    }
                    ptr1->setnext(ptr);
                }
             }
            /*
             * Destructor.
             * Frees all the memory acquired by the list.
             */
            ~list()
            {
                //std::cout<<"\nList Object Destroyed\n";
            }
            /*
             * adds value at the end of the list.
             */
            void append(const T& value)
            {
                Node<T> *ptr, *ptr1;
                ptr = new Node<T>();
                ptr->setdata(value);
                ptr->setnext(NULL);
                ptr1 = head;
                if(ptr1==NULL)
                    head = ptr;
                else{
                    while(ptr1->getnext()!=NULL)
                        ptr1 = ptr1->getnext();
                    ptr1->setnext(ptr);
                }
                len++;
            }

            void print()
            {
                Node<T>* ptr;
                ptr = head;
                while(ptr!=NULL){
                    std::cout<<ptr->getdata()<<"\n";
                    ptr=ptr->getnext();
                }
                cout << '/';
            }

            //Returns the length of the list.
            int length(){
                return len;
            }

            // Returns a boolean indicating whether the list is empty.
            inline bool empty(){
                return !len;
            }

            // Adds a value to the front of the list.
            void cons(const T& value)
            {
                Node<T>* ptr;
                ptr = new Node<T>();
                ptr->setdata(value);
                ptr->setnext(head);
                head = ptr;
                len++;
            }

            // Removes the first occurrence of the value from list.
            void remove(const T &x)
            {
                Node<T> *ptr, *ptr1;
                ptr = head;
                if(head->getdata()==x){
                    head = head->getnext();
                    delete(ptr);
                    len--;
                }
                else{
                    while(ptr->getdata()!=x){
                        ptr1 = ptr;
                        ptr = ptr->getnext();
                    }
                    ptr1->setnext(ptr->getnext());
                    delete ptr;
                    len--;
                }
            }

            // Appends the given list x at the end of the current list.
            //function overloading
            // void append(list<T>& x){
            //     Node<T>* ptr;
            //     ptr = head;
            //     while(ptr->getnext()!=NULL)
            //         ptr = ptr->getnext();
            //     ptr->setnext(x.gethead());
            //     len = len+x.length();
            // }

    };
}

#endif
