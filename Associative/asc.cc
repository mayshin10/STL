#include <cstring>
#include <iostream>
#include "set/set.h"
#include "map/map.h"

using namespace std;

int main () {
    cout << endl;

    cout << " *** SET *** " << endl;
    cout << endl;

    set_t<string> s1;

    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << s1.size() << endl; 
    cout << endl;
    cout << "insert : " << (s1.insert("20").second ? "yes" : "no") << endl; 
    cout << "insert : " << (s1.insert("40").second ? "yes" : "no") << endl; 
  
    s1.insert("80");
    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << s1.size() << endl; 
    cout << endl;

    set_t<string>::iterator it1;
    for (it1 = s1.begin(); it1 != s1.end(); ++it1){

        cout << "*it1   : " << *it1 << endl;
    }

    cout << endl;

    cout << "insert : " << (s1.insert("20").second ? "yes" : "no") << endl; 
    cout << "insert : " << (s1.insert("40").second ? "yes" : "no") << endl; 
    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << s1.size() << endl; 
    cout << endl;



    s1.erase("40");
    s1.insert("4"); 
    for (it1 = s1.begin(); it1 != s1.end(); ++it1){
        cout << "*it1   : " << *it1 << endl;
    }
    cout << endl;

    it1 = s1.find("100");
    if ( it1 == s1.end() ) cout << "cannot find !!!" << endl;
    cout << endl;

    for(unsigned i = 10; i < 100; i += 10) {
        string tmp = to_string(i);
        if(s1.count(tmp)) cout << "here   : " << tmp << endl;
    }

    s1.clear();
    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << s1.size() << endl; 
    cout << endl;



    cout << " *** MAP *** " << endl;
    cout << endl;

    map_t<int, string> m1;
    map_t<int, string> m2;

    cout << "empty? : " << (m1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << m1.size() << endl; 
    cout << endl;

    // hello world
    m1[0] = "hel";
    m1[1] = "lo";
    m1[2] = " ";
    m1[3] = "wor";
    m1[4] = "ld";
    map_t<int, string>::iterator it2;
    for (it2 = m1.begin(); it2 != m1.end(); ++it2){
        cout << "*it2 k : " << it2->first << endl;
    }
    cout << endl;
    for (it2 = m1.begin(); it2 != m1.end(); ++it2){
        cout << "*it2 v : " << it2->second << endl;
    }
    cout << endl;
 
    m2 = m1;
    it2 = m2.find(2);
    m1.erase(2);
     m2.erase(it2);
    for (it2 = m1.begin(); it2 != m1.end(); ++it2){
        cout << it2->second;
    }
    cout << endl;
    for (it2 = m2.begin(); it2 != m2.end(); ++it2){
        cout << it2->second;
    }
    cout << endl;
    cout << endl;

    m1.clear();
    m2.clear();
    cout << "empty? : " << (m1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << m1.size() << endl; 
    cout << "empty? : " << (m2.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << m2.size() << endl; 
    cout << endl;

}
