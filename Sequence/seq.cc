#include <cstring>
#include <iostream>
#include "vector/vector.h"
#include "deque/deque.h"
#include "list/list.h"

using namespace std;

int main () {
    cout << endl;

    cout << " *** VECTOR *** " << endl;
    cout << endl;

    vector_t<string> v1;
    vector_t<string> v2;

    cout << "empty? : " << (v1.empty() ? "yes" : "no") << endl; 
    cout << "cap    : " << v1.capacity() << endl; 
    cout << "size   : " << v1.size() << endl; 
    cout << endl;

    v1.reserve(2);
    cout << "empty? : " << (v1.empty() ? "yes" : "no") << endl; 
    cout << "cap    : " << v1.capacity() << endl; 
    cout << "size   : " << v1.size() << endl;
    cout << endl;

    v1.push_back("16");
    v1.push_back("32");
    v1.push_back("64");
    cout << endl;

    v1.pop_back();
    for (size_t i = 0; i < v1.size(); i++) {
        cout << "v1[" << i << "]  : " << v1[i] << endl;
    }
    cout << endl;

    v1.insert(v1.end(), "128");
    v1.insert(--v1.end(), "256");
    v1.erase(v1.begin()+2);
    for (size_t i = 0; i < v1.size(); i++) {
        cout << "v1[" << i << "]  : " << v1[i] << endl;
    }
    cout << endl;

    v2 = v1;
    vector_t<string> v3(v1);

    v1.clear();
    cout << "cap    : " << v1.capacity() << endl; 
    cout << "size   : " << v1.size() << endl;
    cout << endl;

    cout << "front  : " << (v2.front() == v3.front() ? "yes" : "no") << endl; 
    cout << "back   : " << (v2.back() == v3.back() ? "yes" : "no") << endl; 
    cout << endl;

    for(vector_t<string>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    v2.clear();
    v3.clear();

    cout << " *** DEQUE *** " << endl;
    cout << endl;

    deque_t<string> d1;
    deque_t<string> d2;

    d1.push_back("16");
    d1.push_back("32");
    d1.push_front("128");
    d1.push_front("256");
    cout << "empty? : " << (d1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << d1.size() << endl; 
    cout << endl;

    d1.pop_back();
    d1.pop_front();
    cout << "size   : " << d1.size() << endl; 
    cout << endl;

    d1.insert(d1.end(), "512");
    d1.insert(d1.begin()+1, "1024");
    d1.insert(d1.begin()+2, "2048");
    d1.erase(d1.begin());
    for (size_t i = 0; i < d1.size(); i++) {
        cout << "d1[" << i << "]  : " << d1[i] << endl;
    }
    cout << endl;

    for(deque_t<string>::iterator it = d1.begin(); it != d1.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    d2 = d1;
    d1.clear();
    d2.erase(d2.begin());
        for (size_t i = 0; i < d2.size(); i++) {
        cout << "d2[" << i << "] : " << d2[i] << endl;
    }
    cout << endl;

    cout << "front : " << d2.front() << endl;
    cout << "back  : " << d2.back() << endl;
    cout << endl;

    d2.clear();

    cout << " *** LIST *** " << endl;
    cout << endl;

    list_t<string> l1;
    list_t<string> l2;

    cout << "empty? : " << (l1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << l1.size() << endl; 
    cout << endl;

    l1.push_back("2");
    l1.push_back("4");
    l1.push_front("8");
    l1.push_front("16");
    l1.push_front("32");
    l1.push_front("64");

    for(list_t<string>::iterator it = l1.begin(); it != l1.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    list_t<string>::iterator temp_it;
    temp_it = l1.begin();

    l1.insert(temp_it++, "100");
    l1.erase(temp_it);
    l1.pop_front();
    l1.pop_back();
    l2 = l1;
    l1.clear();

    for(list_t<string>::iterator it = l2.begin(); it != l2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    list_t<string> l3(l2);

    l2.sort();

    for(list_t<string>::iterator it = l2.begin(); it != l2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    l2.merge(l3);

    for(list_t<string>::iterator it = l2.begin(); it != l2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    l2.reverse();

    for(list_t<string>::iterator it = l2.begin(); it != l2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    l2.remove("16");

    for(list_t<string>::iterator it = l2.begin(); it != l2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

    l2.sort();
    l2.unique();

    for(list_t<string>::iterator it = l2.begin(); it != l2.end(); it++) {
        cout << "*it    : " << *it << endl;
    }
    cout << endl;

}
