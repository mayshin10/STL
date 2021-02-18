#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <cstdlib>
#include "deque-def.h"
#include <algorithm>

#define array_size 10

////// iterator_d //////

template <typename T>
iterator_d<T>::iterator_d() : ptr(0) { }

template <typename T>
iterator_d<T>::iterator_d(const iterator_d<T>& it) { 
	ptr = it.ptr; 
}

template <typename T>
iterator_d<T>::~iterator_d(){
   	ptr = 0;
}

template <typename T>
T& iterator_d<T>::operator*() const { return *ptr; }

template <typename T>
iterator_d<T> iterator_d<T>::operator+(size_t s) {
	ptr += s;
	return *this;
}

template <typename T>
iterator_d<T> iterator_d<T>::operator-(size_t s) {
        ptr -= s;
        return *this;
}

template <typename T>
iterator_d<T> iterator_d<T>::operator++() {
	ptr += 1;
	return *this;
}

template <typename T>
iterator_d<T> iterator_d<T>::operator++(int) {
	iterator_d<T> it(*this);
	this->ptr ++;

	return it;
}

template <typename T>
iterator_d<T> iterator_d<T>::operator--() {
	ptr -= 1;
	return *this;
}

template <typename T>
iterator_d<T> iterator_d<T>::operator--(int) {
	iterator_d<T> it(*this);
	this->ptr -= 1;
	return it;
}

template <typename T>
bool iterator_d<T>::operator!=(const iterator_d<T>& it) const { return ptr != it.ptr; }

template <typename T>
bool iterator_d<T>::operator==(const iterator_d<T>& it) const { return ptr == it.ptr; }


////// deque_t //////

template<typename T>
deque_t<T>::deque_t() {
	num_elements = 0;
	array = new T[array_size];
}

template<typename T>
deque_t<T>::deque_t(const deque_t& v) {  
	num_elements = v.num_elements;
	array = new T[num_elements+array_size];
}

template<typename T>
deque_t<T>::~deque_t() {
	clear();
	delete[] array;
}

template<typename T>
deque_t<T>& deque_t<T>::operator=(const deque_t& v) {
	num_elements = v.num_elements;
	array = v.array;
	return *this;
}

template<typename T>
iterator_d<T> deque_t<T>::begin() const {
	deque_t<T>::iterator iter;
	iter.ptr = array;
	return iter;
}

template<typename T>
iterator_d<T> deque_t<T>::end() const {
	deque_t<T>::iterator iter;
	iter.ptr = array + num_elements;
	return iter;
}

template<typename T>
size_t deque_t<T>::size() const { return num_elements; }

template<typename T>
bool deque_t<T>::empty() const { return num_elements==0? 1: 0; }

template<typename T>
T& deque_t<T>::front() const { return array[0]; }

template<typename T>
T& deque_t<T>::back() const { return array[num_elements - 1]; }

template<typename T>
T& deque_t<T>::operator[](size_t s) const { return array[s]; }

template<typename T>
iterator_d<T> deque_t<T>::insert(const iterator& pos, const T& d) {
	for (deque_t<T>::iterator iter = this->end(); iter.ptr != (pos.ptr-1); iter--)
		iter.ptr[1] = iter.ptr[0];
	num_elements++;
	pos.ptr[0] = d;
	return pos;

}

template<typename T>
iterator_d<T> deque_t<T>::erase(const iterator pos) {
	for (deque_t<T>::iterator iter = pos; iter!= this->end();iter ++)
		iter.ptr[0] = iter.ptr[1];
	num_elements--;
	return pos;
}

template<typename T>
void deque_t<T>::push_back(const T& d) {array[num_elements++] = d;}

template<typename T>
void deque_t<T>::pop_back() { num_elements--; }

template<typename T>
void deque_t<T>::push_front(const T& d) {
	for (size_t i = num_elements; i > 0; i--)
		array[i] = array[i - 1];
	array[0] = d;
	num_elements ++;
}

template<typename T>
void deque_t<T>::pop_front() {
	num_elements--;
	for (size_t i = 0; i < num_elements; i++)
		array[i] = array[i + 1];

}

template<typename T>
void deque_t<T>::clear() {
	array = 0; 
	num_elements = 0;
}

#endif
