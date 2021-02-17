#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>
#include "list-def.h"
#include <stdlib.h>

////// iterator_L //////

template <typename T>
iterator_L<T>::iterator_L() : ptr(0) { }

template <typename T>
iterator_L<T>::iterator_L(const iterator_L<T>& it) { ptr = it.ptr; }

template <typename T>
iterator_L<T>::~iterator_L() {}

template <typename T>
T& iterator_L<T>::operator*() const { return ptr->value; }

template <typename T>
iterator_L<T> iterator_L<T>::operator+(size_t s) {
	iterator_L<T> iter;
	iter.ptr = ptr + 1;
	return iter;
}

template <typename T>
iterator_L<T> iterator_L<T>::operator-(size_t s) {
	iterator_L<T> iter;
	iter.ptr = ptr - 1;
	return iter;
}

template <typename T>
iterator_L<T> iterator_L<T>::operator++() {
	ptr += 1;
	return *this;
}

template <typename T>
iterator_L<T> iterator_L<T>::operator++(int) {
	iterator_L<T> it(*this);
	this->ptr++;
	return it;
}

template <typename T>
iterator_L<T> iterator_L<T>::operator--() {

	ptr -= 1;
	return *this;
}

template <typename T>
iterator_L<T> iterator_L<T>::operator--(int) {
	iterator_L<T> it(*this);
	this->ptr -= 1;
	return it;
}

template <typename T>
bool iterator_L<T>::operator!=(const iterator_L<T>& it) const { return ptr != it.ptr; }

template <typename T>
bool iterator_L<T>::operator==(const iterator_L<T>& it) const { return ptr == it.ptr; }


////// list_element //////

template<typename T>
list_element<T>::list_element() : left(0), right(0), value(""){}


////// list_t //////

template<typename T>
list_t<T>::list_t(): num_elements(0) {
	array = new list_element<T>[array_size];
}

template<typename T>
list_t<T>::list_t(const list_t& v) {
	num_elements = v.num_elements;
	array = v.array;
}

template<typename T>
list_t<T>::~list_t() {}

template<typename T>
list_t<T>& list_t<T>::operator=(const list_t& v) {
	num_elements = v.num_elements;
	array = v.array;
	return *this;

}

template<typename T>
iterator_L<T> list_t<T>::begin() const {
	list_t<T>::iterator iter;
	iter.ptr = array;
	return iter;
}

template<typename T>
iterator_L<T> list_t<T>::end() const {
	list_t<T>::iterator iter;
	iter.ptr = &(array[num_elements]);
	return iter;

}

template<typename T>
size_t list_t<T>::size() const { return num_elements; }

template<typename T>
bool list_t<T>::empty() const { return num_elements == 0 ? 1 : 0; }

template<typename T>
T& list_t<T>::front() const {}

template<typename T>
T& list_t<T>::back() const {}

template<typename T>
iterator_L<T> list_t<T>::insert(const iterator& pos, const T& d) {
	for (iterator it = (this->end()); it != pos; it=it-1)
		it.ptr->value = (it - 1).ptr->value;
	((this->end()).ptr)->left = &array[num_elements - 1];
	pos.ptr->value = d;
	num_elements++;
	return pos;
}

template<typename T>
iterator_L<T> list_t<T>::erase(const iterator pos) {
	iterator temp = pos;
	for (iterator it = (temp+1); it != this->end(); it = it + 1)
		it.ptr->value = (it + 1).ptr->value;
	num_elements--;
	return pos;

}

template<typename T>
void list_t<T>::push_back(const T& d) {
	array[num_elements].value = d;
	if (num_elements != 0) {
		array[num_elements].left = &array[num_elements - 1];
		array[num_elements - 1].right = &array[num_elements];
	}
	num_elements++;
	
}

template<typename T>
void list_t<T>::pop_back() {
	num_elements--;
}

template<typename T>
void list_t<T>::push_front(const T& d) {
	for (int i = num_elements; i > 0; i--)
		array[i].value = array[i - 1].value;
	array[num_elements].left = &array[num_elements - 1];
	array[0].value = d;
	num_elements++;
}

template<typename T>
void list_t<T>::pop_front() {
	for (iterator it = this->begin(); it != this->end(); it = it + 1)
		it.ptr->value = (it + 1).ptr->value;
	num_elements--;
}

template<typename T>
void list_t<T>::sort() {
	
	for (size_t i = 0; i < num_elements; i++) {
		int first = (int) (array[i].value[0])-48;
		for (size_t j = i + 1; j < num_elements; j++) {
			int second = (int)(array[j].value[0]) - 48;
			if (first > second) {
				first = second;
				T temp = array[i].value;
				array[i].value = array[j].value;
				array[j].value = temp;
			}
				
		}
	}
}

template<typename T>
void list_t<T>::merge(const list_t& v) {
	for (size_t i = 0; i < v.num_elements; i++){
		array[num_elements + i].value = v.array[i].value;
		array[num_elements + i].left = &v.array[i];
		v.array[i].right = &array[num_elements + i];
	}
	num_elements += v.num_elements;
}

template<typename T>
void list_t<T>::reverse() {
	for (size_t i = 0; i < (num_elements) / 2; i++) {
		T temp = array[i].value;
		array[i].value = array[num_elements - 1 - i].value;
		array[num_elements - 1 - i].value = temp;
	}
}

template<typename T>
void list_t<T>::remove(const T d) {
	for (size_t i = 0; i < (num_elements); i++) {
		if (array[i].value == d)
			erase_by_index(i);
	}
}

template<typename T>
void list_t<T>::erase_by_index(size_t s) {
	for (size_t i = s; i < (num_elements); i++) {
		array[i].value = array[i + 1].value;
	}
	num_elements--;
}

template<typename T>
void list_t<T>::unique() {
	for (size_t i = 0; i < (num_elements); i++) {
		T first;
		T second;
		first = array[i].value;
		for (size_t j = i + 1; j < num_elements; j++) {
			second = array[j].value;
			if (second == first)
				erase_by_index(j);
		}
	}
}

template<typename T>
void list_t<T>::clear() {
	num_elements = 0;
}

#endif