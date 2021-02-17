#ifndef _PRI_QUEUE_DEF_
#define _PRI_QUEUE_DEF_
#include "../../Sequence/vector/vector.h"
template<typename T>
class pri_queue_t{
    public:
        pri_queue_t();
        pri_queue_t(const pri_queue_t& pq);

        bool empty() const;
        size_t size() const;
        void push(const std::string& t);
	void push(const int& t);
        T& top();
        void pop();

    private:
        class vector_t<T> vector;
};

#endif
