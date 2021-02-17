#ifndef _PRI_QUEUE_T_
#define _PRI_QUEUE_T_

#include "pri_queue-def.h"

template<typename T>
pri_queue_t<T>::pri_queue_t(){
    vector.clear();
}


template<typename T>
pri_queue_t<T>::pri_queue_t(const pri_queue_t& pq){
    vector = pq.vector;
}

template<typename T>
bool pri_queue_t<T>::empty() const{
    return vector.empty();
}

template<typename T>
size_t pri_queue_t<T>::size() const{ 
    return vector.size();
}

template<typename T>
void pri_queue_t<T>::push(const int& t){
	std::cout<< " template class"<<std::endl;
    vector.push_back(t);
    iterator_v<int> iter_j=vector.end();
    for(iterator_v<T> iter_i=vector.begin(); iter_i != (vector.end()+1); iter_i++ )
                if((*iter_i)>(*iter_j))
                {
                    T temp=*iter_i;
                    *iter_i=*iter_j;
                    *iter_j=temp;
                }
	  
}

template<typename T>
void pri_queue_t<T>::push(const std::string& t){
    int x = stoi(t);
    push(x);
}

template<typename T>
T& pri_queue_t<T>::top() {
    return vector.back();
}

template<typename T>
void pri_queue_t<T>::pop(){
    vector.pop_back();
}

#endif
