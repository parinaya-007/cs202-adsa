#ifndef STACK_HPP_
#define STACK_HPP_

#include "list.hpp"

using namespace cs202;
namespace sandq
{
    template<typename T>
    class stack
    {
        list<T> x;
        public:

             // Constructs a new stack.
            stack(){};
            /*
             * Pushes t to on the top of the stack.
             */
            void push(const T& t)
            {
                x.cons(t);
            }
            /*
             * Returns the element at the top of the stack.
             * Also removes the top element from the stack.
             */
            T pop()
            {
                Node<T>* head = x.gethead();
                T p = head->getdata();
                x.remove(p);
                return p;
            }
            void display()
            {
                x.print();
            }

            /*
             * Returns the element at the top of the stack.
             * Does not remove the top element.
             */
            T top()
            {
                Node<T>* head = x.gethead();
                return head->getdata();
            }
            /*
             * Returns the number of elements currently in the stack.
             */
            int size()
            {
                int p = x.length();
                return p;
            }
            /*
             * Returns a boolean indicating whether the stack is empty or not.
             */
            inline bool empty()
            {
                return x.empty();
            }
            /*
             * Destructor
             * Fress the memory occupied by the stack elements.
             */
            ~stack(){}
    };
}

#endif
