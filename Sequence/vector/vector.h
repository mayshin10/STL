#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>
#include "vector-def.h"
#include <algorithm>

////// iterator_v //////
template <typename T>
iterator_v<T>::iterator_v() : ptr(0) { }

template <typename T>
iterator_v<T>::iterator_v(const iterator_v<T>& it) { ptr = it.ptr; }

template <typename T>
iterator_v<T>::~iterator_v() {
    	ptr = 0;
}

template <typename T>
T& iterator_v<T>::operator*() const { return *ptr; }

template <typename T>
iterator_v<T> iterator_v<T>::operator+(size_t s) {
	ptr += s;
	return *this;
}

template <typename T>
iterator_v<T> iterator_v<T>::operator-(size_t s) {
        ptr -= s;
        return *this;
}

template <typename T>
iterator_v<T> iterator_v<T>::operator++() {
	ptr += 1;
	return *this;
}

template <typename T>
iterator_v<T> iterator_v<T>::operator++(int) {
	iterator_v<T> it(*this);
	this->ptr ++;

	return it;
}

template <typename T>
iterator_v<T> iterator_v<T>::operator--() {

	ptr -= 1;
	return *this;
}

template <typename T>
iterator_v<T> iterator_v<T>::operator--(int) {
	iterator_v<T> it(*this);
	this->ptr -= 1;
	return it;
}

template <typename T>
bool iterator_v<T>::operator!=(const iterator_v<T>& it) const { return ptr != it.ptr; }

template <typename T>
bool iterator_v<T>::operator==(const iterator_v<T>& it) const { return ptr == it.ptr; }


////// vector_t //////

template <typename T>
vector_t<T>::vector_t() :
	array(0),
	array_size(0),
	num_elements(0) {
}

template <typename T>
vector_t<T>::~vector_t() {
    clear();
    delete[] array;
}

template <typename T>
vector_t<T>::vector_t(const vector_t& v) {
	array = v.array;
	array_size = v.array_size;
	num_elements = v.num_elements;
}

template <typename T>
vector_t<T>& vector_t<T>::operator=(const vector_t v) {
	array = v.array;
	num_elements = v.num_elements;
	array_size = v.array_size;
	return *this;
}

template <typename T>
iterator_v<T> vector_t<T>::begin() const {
	vector_t<T>::iterator iter;
	iter.ptr = array;
	return iter;
}

template <typename T>
iterator_v<T> vector_t<T>::end() const {
	vector_t<T>::iterator iter;
	iter.ptr = array + (array_size - 1);
	return iter;
}

template <typename T>
size_t vector_t<T>::size() const { return num_elements; }

template <typename T>
bool vector_t<T>::empty() const { return num_elements ? 0 : 1; }

template <typename T>
size_t vector_t<T>::capacity() const { return array_size; }

template <typename T>
void vector_t<T>::reserve(size_t s) { array_size = s; array = new T[s]; }

template <typename T>
T& vector_t<T>::front() const { return array[0]; }

template <typename T>
T& vector_t<T>::back() const { return array[num_elements]; }

template <typename T>
T& vector_t<T>:: operator[](size_t s) const { return array[s]; }

template <typename T>
iterator_v<T> vector_t<T>::insert(const iterator& pos, const T& v) {
	if (pos == this->end()) {
		this->push_back(v);
	}
	else {
		T temp = this->end().ptr[0];
		pos.ptr[1] = v;
		for (vector_t<T>::iterator it(pos); (it.ptr + 1) != (this->end().ptr); it++)
		{
			it.ptr[2] = it.ptr[1];
		}
		this->push_back(temp);

	}
	return this->end();
}

template <typename T>
iterator_v<T> vector_t<T>::erase(const iterator pos) {
	for (vector_t<T>::iterator it(pos); (it.ptr) != (this->end().ptr); it++)
	{
		it.ptr[0] = it.ptr[1];
	}
	num_elements--;
	return this->end();

}

template <typename T>
void vector_t<T>::push_back(const T& v) {
	num_elements++;
	if (array_size < num_elements) {
		array_size++;
		T* temp_array = new T[array_size - 1];
		copy(array, array + array_size - 1, temp_array);
		array = new T[array_size];
		copy(temp_array, temp_array + array_size - 1, array);
		delete[] temp_array;
		array[num_elements - 1] = v;
	}
	else
		array[num_elements - 1] = v;
}
template <typename T>
void vector_t<T>::pop_back() {
	if (array_size == num_elements)
		num_elements--;
	array_size--;
	T* temp_array = new T[array_size];
	copy(array, array + array_size, temp_array);
	array = new T[array_size];
	copy(temp_array, temp_array + array_size, array);
	delete[] temp_array;
}

template <typename T>
void vector_t<T>::clear() {
	array = 0;
	array_size = 0;
	num_elements = 0;
}

#endif
