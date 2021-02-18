#ifndef _SET_
#define _SET_

#include <stdlib.h>
#include "set-def.h"


//////iterator_set///////

template<typename T>
iterator_set<T>::iterator_set() : ptr(0), root(0) {}

template<typename T>
iterator_set<T> iterator_set<T>::operator++() {
    struct node<T>* parent=find_parent(ptr->value, root);
    if(parent){
        if(parent->left){
            if((ptr->value)==(parent->left->value))
                ptr=parent;
            else{
                struct node<T>* grand_parent=find_parent(parent->value, root);
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
                struct node<T>* grand_parent=find_parent(parent->value, root);
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

template<typename T>
struct node<T>* iterator_set<T>::find_parent(T t, struct node<T>* set){
    if(atoi(t.c_str())==atoi(set->value.c_str())) return 0;
        struct node<T>* temp_node=set;
        while((temp_node->left!=NULL)  || (temp_node->right!=NULL)){
            if(atoi(t.c_str())<atoi(temp_node->value.c_str())){
                if(t==temp_node->left->value) return temp_node;
                else temp_node=temp_node->left;
            }
            else{
                if(t==temp_node->right->value) return temp_node;
                else temp_node=temp_node->right;
            }
        }
    return 0;
}

template<typename T>
T iterator_set<T>::operator*(){
    return ptr->value;
}

template<typename T>    
bool iterator_set<T>::operator!=(const iterator_set<T>& it) const { 
    return ptr != it.ptr; 
}

template<typename T>    
bool iterator_set<T>::operator==(const iterator_set<T>& it) const { 
    return ptr == it.ptr; 
}

///////set_t//////

template<typename T, typename Pred, typename Allocator>
set_t<T, Pred, Allocator>::set_t() {
    set=NULL;
    num_elements=0;
}

template<typename T, typename Pred, typename Allocator>
struct node<T>* set_t<T, Pred, Allocator>::copy_assist(const position& s){
    position p = new node;
    p->value = s->value;
    p->left = p->right = NULL;
    if(s->left != NULL)
        p->left = copy_assist(s->left);
    if(s->right !=NULL)
        p->right = copy_assist(s->right);
    return p;
}

template<typename T, typename Pred, typename Allocator>
set_t<T, Pred, Allocator>::set_t(const set_t& s){
    num_elements = s.num_elements;
    set = copy_assist(s.set); 
}

template<typename T, typename Pred, typename Allocator>
set_t<T, Pred, Allocator>& set_t<T, Pred, Allocator>::operator=(const set_t s){
    num_elements = s.num_elements;
    set = copy_assist(s.set);
    return *this;
}

template<typename T, typename Pred, typename Allocator>
set_t<T, Pred, Allocator>::~set_t(){
    clear();
}

template<typename T, typename Pred, typename Allocator>
bool set_t<T, Pred, Allocator>::empty(){ 
    return set==NULL;
}

template<typename T, typename Pred, typename Allocator>
size_t set_t<T, Pred, Allocator>::size(){
    return num_elements;
}


template<typename T, typename Pred, typename Allocator>
std::pair<iterator_set<T>, bool> set_t<T, Pred, Allocator>::insert(const T& t){
    std::pair<iterator_set<T>, bool>  pr;
    iterator iter;
    size_t temp=num_elements;
    insert_assist(t, set, iter);
    if(temp!=num_elements){
        pr.first=iter;
        pr.second=1;}
    else
        pr.second=0;
    return pr;
}

template<typename T, typename Pred, typename Allocator>
struct node<T>* set_t<T, Pred, Allocator>::insert_assist(T t, position& pos, iterator& iter){
    if( pos == NULL ){
        pos = new node[1];
        pos->value=t;
        pos->left=pos->right=NULL;
        iter.ptr=pos;
        num_elements++;
    }
    else
    if( atoi(t.c_str()) < atoi((pos->value).c_str()))
        pos->left=insert_assist(t, pos->left, iter);
    else
    if( atoi(t.c_str()) > atoi(pos->value.c_str()))
        pos->right=insert_assist(t, pos->right, iter);//    
       
    return pos;
}

template<typename T, typename Pred, typename Allocator> 
iterator_set<T> set_t<T, Pred, Allocator>::begin() const{
    position temp_pos=set;
    while(temp_pos->left!=NULL){
        temp_pos=temp_pos->left;
    }
    iterator iter;
    iter.ptr=temp_pos;
    iter.root=set;
    return iter;
}

template<typename T, typename Pred, typename Allocator>
iterator_set<T> set_t<T, Pred, Allocator>::end() const{
    position temp_pos=set;
    while(temp_pos->right!=NULL){
        temp_pos=temp_pos->right;
    }
    iterator iter;
    iter.ptr=temp_pos->right;
    iter.root=set;
    return iter;
}

template<typename T, typename Pred, typename Allocator>
T set_t<T, Pred, Allocator>::erase(const T& t){
    position erased;
    erased=erase_assist(t, set);
    num_elements--;
    return erased->value;
}

template<typename T, typename Pred, typename Allocator>
struct node<T>* set_t<T, Pred, Allocator>::erase_assist(T t, position& set){

    position temp_pos;
    position temp_set=set;
    if( atoi(t.c_str()) < atoi(temp_set->value.c_str()))  /* Go left */
        temp_set->left = erase_assist(t, temp_set->left);
    else
    if( atoi(t.c_str()) > atoi(temp_set->value.c_str()))  /* Go right */
        temp_set->right = erase_assist(t, temp_set->right);
    else  /* Found element to be deleted */
    if( temp_set->left && temp_set->right ){
        temp_pos=temp_set->right;
        while(temp_pos->left!=NULL){
            temp_pos=temp_pos->left;
        }
        temp_set->value = temp_pos->value;
        temp_set->right = erase_assist( temp_set->value, temp_set->right );
    }
    else{
        temp_pos = temp_set;
        if( temp_set->left == NULL ) /* Also handles 0 children */
            temp_set = temp_set->right;
        else if( temp_set->right == NULL )
            temp_set = temp_set->left;
            //delete temp_pos;
        }
    return temp_set;
}

template<typename T, typename Pred, typename Allocator>
iterator_set<T> set_t<T, Pred, Allocator>::find(const T& t){
    position finded=find_assist(t, set);
    iterator iter;
    if(finded==NULL){
        iter.ptr=NULL;
        iter.root=set;
    }
    else{
        iter.ptr=finded;
        iter.root=set;
    }
    return iter;
}

template<typename T, typename Pred, typename Allocator>
struct node<T>* set_t<T, Pred, Allocator>::find_assist(T t, position& set){
    position temp_set=set;
    if( temp_set == NULL )
        return NULL;
    if( atoi(t.c_str()) < atoi(temp_set->value.c_str()) )
         return find_assist( t, temp_set->left );
    else
    if( atoi(t.c_str()) > atoi(temp_set->value.c_str()) )
        return find_assist( t, temp_set->right );
    else
    return temp_set;
}

template<typename T, typename Pred, typename Allocator>
size_t set_t<T, Pred, Allocator>::count(const T& t){
    if(find_assist(t,set))
        return 1;
    else
        return 0;
}

template<typename T, typename Pred, typename Allocator>
void set_t<T, Pred, Allocator>::clear(){
    clear_assist(set);
    num_elements=0;
}

template<typename T, typename Pred, typename Allocator>
void set_t<T, Pred, Allocator>::clear_assist(position& pos){
    if(pos!=NULL){
        clear_assist(pos->left);
        clear_assist(pos->right);
        pos=NULL;
    }
}        
#endif
