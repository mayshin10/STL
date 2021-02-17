#ifndef _QUEUE_T_
#define _QUEUE_T_

#include "queue-def.h"

template<typename T>
queue_t<T>::queue_t(){
    queue=new position[1];
    queue->right=NULL;
}

template<typename T>
queue_t<T>::queue_t(const queue_t& que){
    position* sentinel;
    sentinel=new position[1];
    position* p2=sentinel->right;

    if(que.queue->right==NULL){ 
        p2=NULL;
    }
    else
    {
        p2= new position[1];
        position* p1=que.queue->right;
        
        while(p1->right!=NULL){
            p2->value=p1->value;
            position* new_p2= new position[1];
            p2->right=new_p2;
            p2=new_p2;
            p1=p1->right;
        }
        p2->value=p1->value;
    }
    queue=sentinel;
}

template<typename T>
bool queue_t<T>::empty() const{
    return queue->right==NULL? 1 : 0;
}

template<typename T>
size_t queue_t<T>::size() const{
    size_t s=0;
    for(position* pos=queue->right; pos!=NULL; pos=pos->right)
        s++;  
    return s;
}

template<typename T>
void queue_t<T>::push(const T& t){
    position* pos=new position[1];
    pos->value=t;
    pos->right=queue->right;
    queue->right=pos;
}

template<typename T>
T& queue_t<T>::back() {
    return queue->right->value;
} 
      
template<typename T>
void queue_t<T>::pop() {
    position* pos=queue;
    while(pos->right->right!=NULL)
        pos=pos->right;
    pos->right=NULL;
}

template<typename T>
void queue_t<T>::swap(const queue_t& que){
    position* temp;
    temp=queue->right;
    queue->right=que.queue->right;
    que.queue->right=temp;
}

#endif
            