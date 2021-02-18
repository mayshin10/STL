#ifndef _ITER_MAP_
#define _ITER_MAP_

template<typename Key, typename Value> class map_t;
template<typename Key, typename Value> struct node_map;

template<typename Key, typename Value>
class iterator_map{
    public:
        iterator_map();
        
        typedef struct node_map<Key, Value> node;
        typedef struct node_map<Key, Value>* position;

        iterator_map operator++();
        position find_parent(Key key, position map);
        position operator->() const;
        void operator=(const Value& v);
        bool operator!=(const iterator_map<Key, Value>& it) const;
    
    private:
        friend class map_t<Key, Value>;
        position ptr;
        position root;
};
#endif

#ifndef _MAP_DEF_
#define _MAP_DEF_

template<typename Key, typename Value>
struct node_map{
    Key first;
    Value second;
    struct node_map<Key, Value>* left;
    struct node_map<Key, Value>* right;
};

template<typename Key, typename Value>
class map_t{
    public:
        map_t();
        bool empty() const;
        size_t size() const;
        
        typedef iterator_map<Key, Value> iterator;
        typedef struct node_map<Key, Value> node;
        typedef struct node_map<Key, Value>* position;

        iterator operator[](const Key& key);
        position insert_assist(Key key, position& pos, iterator& iter);
        map_t& operator=(const map_t& m);
        iterator begin();
        iterator end();
        iterator find(const Key& key);
        Key erase(const Key& key);
        Key erase(iterator& iter);
        void clear();
        void copy_assist(position pos);
        position find_assist(Key key, position& map);
        position erase_assist(Key key, position& map);
        position erase_iter_assist(iterator& iter);
        void clear_assist(position& pos);

    private:
        position map;
        size_t num_elements;
};

#endif