//
//  JLStack.h
//  Box2D
//
//  Created by João Vitor dos Santos Schimmelpfeng on 19/06/17.
//
//  Stack to work in multithreaded environment

#ifndef JLStack_h
#define JLStack_h

template <typename T>
struct JLStackNode
{
    T value;
    JLStackNode<T> *next;
};


template <typename T>
class JLStack
{
    JLStackNode<T> *top;
    
public:
    JLStack() : top(NULL){};
    void push(T& toPush);
    int isEmpty();
    void pop(T& popTo);
    void peek(T& popTo);
};

#endif /* JLStack_h */
