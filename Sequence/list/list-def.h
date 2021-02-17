#ifndef _ITER_L_
#define _ITER_L_

template <typename T> class list_t;
template <typename T> class list_element;

template <typename T>
class iterator_L {
public:
    iterator_L();
    iterator_L(const iterator_L<T> &it);
    ~iterator_L();

    T& operator*() const;
	iterator_L<T> operator+(size_t s);
	iterator_L<T> operator-(size_t s);
    iterator_L<T> operator++();
    iterator_L<T> operator++(int);
    iterator_L<T> operator--();
    iterator_L<T> operator--(int);
    bool operator!=(const iterator_L<T> &it) const;
    bool operator==(const iterator_L<T> &it) const;

private:
	class list_element<T>* ptr;
    friend class list_t<T>;
};

#endif

#ifndef _LIST_DEF_H_
#define _LIST_DEF_H_

template <typename T>
class list_element {
public:
    list_element();
    list_element * left;
    list_element * right;
    T value;
};

template <typename T>
class list_t {
public:
    list_t();
    list_t(const list_t &v);
    ~list_t();
    list_t& operator=(const list_t& v);

    typedef iterator_L<T> iterator;

    iterator begin() const;
    iterator end() const;
    size_t size() const;
    bool empty() const;
    T& front() const;
    T& back() const;
    iterator insert(const iterator &pos, const T &d);
    iterator erase(const iterator pos);
    void push_back(const T &d);
    void pop_back();
    void push_front(const T &d);
    void pop_front();
	void sort();
	void merge(const list_t& v);
	void reverse();
	void remove(const T d);
	void erase_by_index(size_t s);
	void unique();
    void clear();

private:
    class list_element<T> *array;
    size_t num_elements;
};

#endif