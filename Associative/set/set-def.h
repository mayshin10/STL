#ifndef _ITER_SET_
#define _ITER_SET_

template<typename T, typename Pred, typename Allocator> class set_t;
template<typename T> struct node;

template<typename T>
class iterator_set{
    public:
        iterator_set();
        iterator_set<T> operator++() ;
        struct node<T>* find_parent(T t, struct node<T>* set);
        T operator*();    
        bool operator!=(const iterator_set<T>& it) const;
        bool operator==(const iterator_set<T>& it) const;

    private:
        struct node<T>*ptr;
        struct node<T>* root;
        friend class set_t<T, std::less<T>, std::allocator<T>>;
};
#endif

#ifndef _SET_DEF_
#define _SEF_DEF_

template<typename T>
struct node{
    T value;
    struct node* left;
    struct node* right;  
};

//set container using BST
template<typename T, typename Pred=std::less<T>, typename Allocator=std::allocator<T>>
class set_t{
    public:
	typedef iterator_set<T> iterator;
        typedef struct node<T>* position;
        typedef struct node<T> node;

        set_t();
	set_t(const set_t& s);
	set_t& operator=(const set_t s);
        ~set_t();
	bool empty();
        size_t size();
        std::pair<iterator_set<T>, bool> insert(const T& t);
        iterator begin() const;
        iterator end() const;
        T erase(const T& t);
        iterator find(const T& t);
        size_t count(const T& t);
        void clear();
        
    private:
        position set;
        size_t num_elements;
	position copy_assist(const position& s);
	position insert_assist(T t, position& pos, iterator& iter);
        position erase_assist(T t, position& set);
        position find_assist(T t, position& set);
        void clear_assist(position& pos);
};

#endif
