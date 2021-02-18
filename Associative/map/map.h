#ifndef _MAP_
#define _MAP

#include "map-def.h"

////// Iterator //////

template<typename Key, typename Value>
iterator_map<Key, Value>::iterator_map(){}

template<typename Key, typename Value>
iterator_map<Key, Value> iterator_map<Key, Value>::operator++(){
    position parent=find_parent(ptr->first, root);
    if(parent){
        if(parent->left){
            if((ptr->first)==(parent->left->first))
                ptr=parent;
            else{
                position grand_parent=find_parent(parent->first, root);
                if(grand_parent){
                    if(grand_parent->left==parent)
                        ptr=grand_parent;
                    else
                        ptr=NULL;
                }
                else
                    ptr=NULL;
            }
        }
        else{
            if(ptr->right)
                ptr=ptr->right;
            else{
                position grand_parent=find_parent(parent->first, root);
                if(grand_parent->left==parent)
                    ptr=grand_parent;
                else
                    ptr=NULL;
            }    
        }
    }
    else
        ptr=ptr->right;
    return *this;
}

template<typename Key, typename Value>
struct node_map<Key, Value>* iterator_map<Key, Value>::find_parent(Key key, position map){
    if(key==map->first) return 0;
        position temp_node=map;
        while((temp_node->left!=NULL)  || (temp_node->right!=NULL)){
            if(key<temp_node->first){
                if(key==temp_node->left->first) return temp_node;
                else temp_node=temp_node->left;
            }
            else{
                if(key==temp_node->right->first) return temp_node;
                else temp_node=temp_node->right;
            }
        }
    return 0;
}

template<typename Key, typename Value>
struct node_map<Key, Value>* iterator_map<Key, Value>::operator->() const{
    return ptr;
}

template<typename Key, typename Value>
void iterator_map<Key, Value>::operator=(const Value& v){
    ptr->second=v;
}

template<typename Key, typename Value>
bool iterator_map<Key, Value>::operator!=(const iterator_map<Key, Value>& it) const{
    return ptr!=it.ptr;
}


////// MAP //////

template<typename Key, typename Value>
map_t<Key, Value>::map_t(){
    map=NULL;
    num_elements=0;
}

template<typename Key, typename Value>
struct node_map<Key, Value>* map_t<Key, Value>::copy_assist(const position& mm){
    position pos = new node;
    pos-> first = mm->first;
    pos-> second = mm->second;
    if(mm->left != NULL)
        pos->left = copy_assist(mm->left);
    if(mm->right != NULL)
        pos->right = copy_assist(mm->right);
    return pos;
}

template<typename Key, typename Value>
map_t<Key, Value>::map_t(const map_t& m){
    num_elements = m.num_elements;
    map = copy_assist(m.map);
}

template<typename Key, typename Value>
map_t<Key, Value> map_t<Key, Value>::operator=(const map_t m){
    num_elements = m.num_elements;
    map = copy_assist(m.map);
    return *this;
}

template<typename Key, typename Value>
map_t<Key, Value>::~map_t(){
    clear();
}


template<typename Key, typename Value>
bool map_t<Key, Value>::empty() const{
    return map==NULL;
}

template<typename Key, typename Value>
size_t map_t<Key, Value>::size() const{
    return num_elements;
}

template<typename Key, typename Value>
std::pair<iterator_map<Key, Value>, bool> map_t<Key, Value>::insert(std::pair<Key, Value> pr){
   iterator iter;
   iter.root = map;
   insert_assist(pr.first, map, iter);
   if(iter.ptr == NULL)
       return {NULL, 0};
   else{
       iter.ptr->second = pr.second;	   
       return {iter, 1};
   }
}

template<typename Key, typename Value>
iterator_map<Key, Value> map_t<Key, Value>::operator[](const Key& key){
    iterator iter;
    iter.root=map;
    insert_assist(key, map, iter);
    num_elements++;
    return iter;
}

template<typename Key, typename Value>
struct node_map<Key, Value>* map_t<Key, Value>::insert_assist(Key key, position& pos, iterator& iter){
    if( pos == NULL ){
        pos = new node[1];
        pos->first=key;
        pos->left=pos->right=NULL;
        iter.ptr=pos;
    }
    else 
    if(key == pos->first)
        iter.ptr = NULL;
    else
    if( key < pos->first)
        pos->left=insert_assist(key, pos->left, iter);
    else
    if( key > pos->first)
        pos->right=insert_assist(key, pos->right, iter);

    return pos;
}

template<typename Key, typename Value>
iterator_map<Key, Value> map_t<Key, Value>::begin(){
    position temp_pos=map;
    while(temp_pos->left!=NULL){
        temp_pos=temp_pos->left;
    }
    iterator iter;
    iter.ptr=temp_pos;
    iter.root=map;
    return iter;
}

template<typename Key, typename Value>
iterator_map<Key, Value> map_t<Key, Value>::end(){
    position temp_pos=map;
    while(temp_pos->right!=NULL){
        temp_pos=temp_pos->right;
    }
    iterator iter;
    iter.ptr=temp_pos->right;
    iter.root=map;
    return iter;

}

template<typename Key, typename Value>
iterator_map<Key, Value> map_t<Key, Value>::find(const Key& key){

    position finded=find_assist(key, map);
    iterator iter;
    if(finded==NULL){
        iter.ptr=NULL;
        iter.root=map;
    }
    else{
        iter.ptr=finded;
        iter.root=map;
    }
    return iter;

}

template<typename Key, typename Value>
struct node_map<Key, Value>* map_t<Key, Value>::find_assist(Key key, position& map){
    position temp_map=map;
    if( temp_map == NULL )
        return NULL;
    if( key< temp_map->first )
         return find_assist( key, temp_map->left );
    else
    if( key > temp_map->first  )
        return find_assist( key, temp_map->right );
    else
    return temp_map;
}

template<typename Key, typename Value>
Key map_t<Key, Value>::erase(const Key& key){
    position erased;
    erased=erase_assist(key, map);
    num_elements--;
    return erased->first;
}

template<typename Key, typename Value>
struct node_map<Key, Value>* map_t<Key, Value>::erase_assist(Key key, position& map){
    position temp_pos;
    position temp_map=map;
    if( key < temp_map->first)  /* Go left */
        temp_map->left = erase_assist(key, temp_map->left);
    else
    if( key > temp_map->first)  /* Go right */
        temp_map->right = erase_assist(key, temp_map->right);
    else  /* Found element to be deleted */
    if( temp_map->left && temp_map->right ){
        temp_pos=temp_map->right;
        while(temp_pos->left!=NULL){
            temp_pos=temp_pos->left;
        }
        temp_map->first = temp_pos->first;
        temp_map->right = erase_assist( temp_map->first, temp_map->right );
    }
    else{
        temp_pos = temp_map;
        if( temp_map->left == NULL ) /* Also handles 0 children */
            temp_map = temp_map->right;
        else if( temp_map->right == NULL )
            temp_map = temp_map->left;
            //delete temp_pos;
        }
    return temp_map;
}

template<typename Key, typename Value>
Key map_t<Key, Value>::erase(iterator& iter){
    position erased;
    erased=erase_iter_assist(iter);
    num_elements--;
    return erased->first;
}

template<typename Key, typename Value>
struct node_map<Key, Value>* map_t<Key, Value>::erase_iter_assist(iterator& iter){
    if( iter->left && iter->right ){
        iterator temp_pos;
        temp_pos.ptr=iter->right;
        while(temp_pos->left!=NULL){
            temp_pos.ptr=temp_pos->left;
        }
        iter->first = temp_pos->first;
        iter->right = erase_iter_assist(temp_pos);
    }
    else{
        if( iter->left == NULL ){ /* Also handles 0 children */
            iter.ptr->first = iter->right->first;
            iter.ptr->second=iter->right->second;
            if(iter->right->right)
                iter.ptr->right=iter->right->right;
            if(iter->right->left)
            iter.ptr->left=iter->right->left;
        }
        else if( iter->right == NULL ){ /* Also handles 0 children */
            iter.ptr->first = iter->left->first;
            iter.ptr->second=iter->left->second;
            if(iter->left->right)
                iter.ptr->right=iter->left->right;
            if(iter->left->left)
            iter.ptr->left=iter->left->left;
        }
    }
    return iter.ptr;
}

template<typename Key, typename Value>
size_t map_t<Key, Value>::count(Key& key){
    position finded=find_assist(key, map);
    if(finded==NULL)
        return 0;
    else
        return 1;
}

template<typename Key, typename Value>
void map_t<Key, Value>::clear(){
    clear_assist(map);
    num_elements=0;
}

template<typename Key, typename Value>
void map_t<Key, Value>::clear_assist(position& pos){
    if(pos!=NULL){
        clear_assist(pos->left);
        clear_assist(pos->right);
        pos=NULL;
    }
}

#endif
