/********************************************************************
* Iterator class
*
* Author: Paul Thompson
*
* Purpose: Custom Iterator class. The class handles overloads for
* --, ++, *, !=, and == so they can be used with pointers to nodes
* in the linked list.
*
********************************************************************/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T>
struct Iterator {
    Node<T> *iter;
public:
    Iterator(Node<T> *n):
        iter(n)
    {}

    Iterator(const Iterator& i):
        iter(i.iter)
    {}

    // Because the linked list is not contiguous, ++ must
    // point to the next node, not just the next region of
    // memory.
    Iterator& operator ++(){
        iter = iter->next;
        return *this;
    }

    // Same as ++, just in reverse
    Iterator& operator --(){
        iter = iter->prev;
        return *this;
    }

    // We want * to return the value stored in the node,
    // so the overload returns the value member variable
    T& operator *(){
        return iter->value;
    }

    bool operator ==(const Iterator& i){
        return (iter == i.iter);
    }

    bool operator != (const Iterator& i){
        return (iter != i.iter);
    }

};

#endif
