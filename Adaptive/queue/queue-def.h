#ifndef _QUEUE_T_DEF_
#define _QUEUE_t_DEF_

template<typename T>
struct position_q { 
    T value;
    struct position_q *right;
};

template<typename T>
class queue_t{
    public:
        queue_t();
        queue_t(const queue_t& que);
        
        bool empty() const;
        size_t size() const;
        void push(const T& t);
        T& back();
        void pop();
        void swap(const queue_t& que);

        typedef struct position_q<T> position;
            
    private:
        position* queue;
};

#endif