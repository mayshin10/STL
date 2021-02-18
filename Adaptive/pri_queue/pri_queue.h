#ifndef _PRI_QUEUE_T_
#define _PRI_QUEUE_T_

#include "pri_queue-def.h"
#include <algorithm> 

template<typename T>
pri_queue_t<T>::pri_queue_t(){
    vec.clear();
}


template<typename T>
pri_queue_t<T>::pri_queue_t(const pri_queue_t& pq){
    vec = pq.vec;
}

template<typename T>
bool pri_queue_t<T>::empty() const{
    return vec.empty();
}

template<typename T>
size_t pri_queue_t<T>::size() const{ 
    return vec.size();
}

template<typename T>
void pri_queue_t<T>::Heapify(unsigned n, vector_t<int> vector){
   unsigned len = vector.size();
   if(len==0)
	 return;
   unsigned int c = 2 * n +1;
   if(c +1 < len && vector[c] < vector[c+1])
	 c++;
   if(vector[n] < vector[c] && c < len){
	 std::swap(vector[n], vector[c]);
	 if(c <= len /2 -1)
  	     Heapify(c, vector);
   }
} 

template<typename T>
void pri_queue_t<T>::Heapify(unsigned n, vector_t<std::string> vector){
   unsigned len = vector.size();
   if(len==0)
         return;
   unsigned int c = 2 * n +1;
   if(c +1 < len && stoi(vector[c]) < stoi(vector[c+1]))
         c++;
   if(stoi(vector[n]) < stoi(vector[c]) && c < len){
	 std::swap(vector[n], vector[c]);
         if(c <= len /2 -1)
             Heapify(c, vector);
   }
}


template<typename T>
void pri_queue_t<T>::push(const int& t){
    vec.push_back(t);
    unsigned int n = vec.size() - 1;
    unsigned int c = (n-1) / 2;
    while(1){
       if(vec[c] >= vec[n] || n < 1 )
	       break;
       std::swap(vec[c], vec[n]);
       n = c;
       c = (n-1) /2;
    }   
}

template<typename T>
void pri_queue_t<T>::push(const std::string& t){
    vec.push_back(t);
    int n = vec.size() - 1;
    int c= (n-1) / 2;
    while(1){
        int pa = stoi(vec[c]);
	int ch = stoi(vec[n]);
	if(pa >= ch || n <1 )
		break;
	std::swap(vec[c], vec[n]);
 	n = c;
	c = (n-1)/2;	
    }
}

template<typename T>
T& pri_queue_t<T>::top() {
    return vec.front();
}

template<typename T>
void pri_queue_t<T>::pop(){
   std::swap(vec[0], vec[vec.size()-1]);
   vec.pop_back();
   Heapify(0, vec);
}

#endif
