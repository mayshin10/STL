#ifndef _STACK_T_
#define _STACK_T_

#include "stack-def.h"

template<typename T>
stack_t<T>::stack_t(){
    position* sentinel;
    sentinel=new position[1];
    sentinel->right=NULL;
    stack=sentinel;
}

template<typename T>
stack_t<T>::stack_t(const stack_t &st){
    position* sentinel;
    sentinel=new position[1];
    position* p2=sentinel->right;

    if(st.stack->right==NULL){ 
        p2=NULL;
    }
    else
    {
        p2= new position[1];
        position* p1=st.stack->right;
        
        while(p1->right!=NULL){
            p2->value=p1->value;
            position* new_p2= new position[1];
            p2->right=new_p2;
            p2=new_p2;
            p1=p1->right;
        }
        p2->value=p1->value;
    }
    stack=sentinel;
}

template<typename T>
bool stack_t<T>::empty(){
    return stack->right==NULL? 1: 0;
}

template<typename T>
size_t stack_t<T>::size() const{
    size_t s=0;
    for(position* pos=stack->right; pos!=NULL; pos=pos->right)
        s++;  
    return s;
}

template<typename T>
void stack_t<T>::push(T t){
    position* pos=new position[1];
    pos->value=t;
    pos->right=stack->right;
    stack->right=pos;
}

template<typename T>
void stack_t<T>::pop(){
    position* pos=stack->right;
    stack->right=stack->right->right;
    delete[] pos;
}

template<typename T>
T stack_t<T>::top() const{
    return stack->right->value;
}

template<typename T>
void stack_t<T>::swap(stack_t& s2){
    position* temp;
    temp=stack->right;
    stack->right=s2.stack->right;
    s2.stack->right=temp;
}

#endif