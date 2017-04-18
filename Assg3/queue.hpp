#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"
using namespace cs202;

namespace sandq
{
    template <class T>
    class queue
    {
        list<T> x;
        public:
            /*
             * Constructs a new queue.
             */
            queue(){}
            /*
             * Pushes t to at the back of the queue.
             */
            void enqueue(const T &t)
            {
                x.append(t);
            }
            /*
             * Returns the element at the front of the queue.
             * Also removes the front element from the queue.
             */
            T dequeue()
            {
                Node<T>* head = x.gethead();
                T p = head->getdata();
                x.remove(p);
                return p;
            }
            /*
             * Returns the element at the front of the queue.
             * Does not remove the front element.
             */
            T front()
            {
                Node<T>* head = x.gethead();
                return head->getdata();
            }
            /*
             * Returns the number of elements currently in the queue.
             */
            inline int size()
            {
                return x.length();
            }
            /*
             * Returns a boolean indicating whether the queue is empty or not.
             */
            inline bool empty()
            {
                return x.empty();
            }

            void deleteQ(){
                Node<T> *head = x.gethead();
                Node<T> *ptr = head;
                Node<T> *ptr1 = head;
                while(ptr!=NULL){
                    ptr1 = ptr->getnext();
                    delete ptr;
                    ptr = ptr1;
                }
            }

            void display()
            {
                x.print();
            }
            /*
             * Destructor
             * Fress the memory occupied by the queue elements.
             */
            ~queue(){}
    };
}
#endif
