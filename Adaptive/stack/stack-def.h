#ifndef _STACK_T_DEF_
#define _STACK_T_DEF_

template<typename T>
struct position_s { 
    T value;
    struct position_s *right;
};

//implemented by linked list 
template<typename T>
class stack_t{
    public:
        stack_t();
        stack_t(const stack_t &st);

        typedef struct position_s<T> position;

        bool empty();
        size_t size() const;
        void push(T t);
        void pop();
        T top() const;
        void swap(stack_t& s2);

    private :
        position *stack;
};

#endif