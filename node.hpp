/********************************************************************
* Node class
*
* Author: Paul Thompson
*
* Purpose: Node class for use in the linked list. Each Node<T> has a
* value, and pointers to the next and prev nodes. There is no
* destructor because a Node is destroyed with delete inside clear().
*
********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {
    T value;
    Node *next, *prev;

    Node():
        next(nullptr),
        prev(nullptr),
        value()
    {}

    Node<T>(T data):
            next(nullptr),
            prev(nullptr),
            value(data)
    {}

    Node&operator =(Node<T>& n){
        next = n.next;
        prev = n.prev;
    }

};

#endif
