//
//  JLStack.cpp
//  Box2D
//
//  Created by João Vitor dos Santos Schimmelpfeng on 19/06/17.
//
//

#include <stdio.h>
#include <mutex>
#include "JLStack.h"

std::mutex m;

template <typename T>
void JLStack<T>::push(T& toPush)
{
    JLStackNode<T> *node = new JLStackNode<T>;
    node->value = toPush;
    
    //Thread Safe.
    m.lock();
    node->next = top;
    m.unlock();
}

template <typename T>
void JLStack<T>::pop(T& popTo)
{
    if(NULL == top)
        return;
    
    JLStackNode<T> *topNode = top->next;
    popTo->value = top->value;
    
    free(top);
    m.lock();
    top = topNode;
    m.unlock();
}

template <typename T>
void JLStack<T>::peek(T& popTo)
{
    if(NULL == top)
        return;
    
    popTo = top->value;
}

template <typename T>
int JLStack<T>::isEmpty()
{
    if (NULL == top)
        return 1;
    else
        return 0;
}
