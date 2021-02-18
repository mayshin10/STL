#include <cstring>
#include <iostream>
#include "stack/stack.h"
#include "queue/queue.h"
#include "pri_queue/pri_queue.h"

using namespace std;

int main () {
    cout << endl;

    cout << " *** STACK *** " << endl;
    cout << endl;

    stack_t<string> s1;
 
    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << s1.size() << endl; 
    cout << endl;

    s1.push("1");
    s1.push("1");
    s1.push("2");
    s1.push("3");
    s1.push("5");
    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << s1.size() << endl; 
    cout << endl;

    cout << "top    : " << s1.top() << endl;

    stack_t<string> s2(s1);

    s1.pop();
    s1.pop();
    cout << "empty? : " << (s1.empty() ? "yes" : "no") << endl; 
    cout << "top    : " << s1.top() << endl;
    cout << "size   : " << s1.size() << endl; 
    cout << endl;

    s1.swap(s2);
    cout << "empty? : " << (s2.empty() ? "yes" : "no") << endl; 
    cout << "top    : " << s2.top() << endl;
    cout << "size   : " << s2.size() << endl; 
    cout << endl;

    cout << " *** QUEUE *** " << endl;
    cout << endl;

    queue_t<string> q1;

    cout << "empty? : " << (q1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << q1.size() << endl; 
    cout << endl;

    q1.push("8");
    q1.push("13");
    q1.push("21");
    q1.push("34");
    q1.push("55");
    cout << "empty? : " << (q1.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << q1.size() << endl; 
    cout << endl;

    cout << "back   : " << q1.back() << endl;

    queue_t<string> q2(q1);

    q1.pop();
    q1.pop();
    cout << "empty? : " << (q1.empty() ? "yes" : "no") << endl; 
    cout << "back   : " << q1.back() << endl;
    cout << "size   : " << q1.size() << endl; 
    cout << endl;

    q1.swap(q2);
    cout << "empty? : " << (q2.empty() ? "yes" : "no") << endl; 
    cout << "back   : " << q2.back() << endl;
    cout << "size   : " << q2.size() << endl; 
    cout << endl;



    cout << " *** PRIORITY QUEUE *** " << endl;
    cout << endl;

    pri_queue_t<string> q3;

    q3.push("100");
    q3.push("1");
    q3.push("10");
    q3.push("10000");
    q3.push("1000");
    q3.push("0");
    q3.push("100000");
    cout << "empty? : " << (q3.empty() ? "yes" : "no") << endl; 
    cout << "size   : " << q3.size() << endl; 
    cout << endl;

    cout << "top    : " << q3.top() << endl;
    cout << endl;

    q3.pop();
    cout << "empty? : " << (q3.empty() ? "yes" : "no") << endl; 
    cout << "top    : " << q3.top() << endl;
    cout << "size   : " << q3.size() << endl; 
    cout << endl;

    q3.pop();
    cout << "empty? : " << (q3.empty() ? "yes" : "no") << endl; 
    cout << "top    : " << q3.top() << endl;
    cout << "size   : " << q3.size() << endl; 
    cout << endl;

    q3.pop();
    cout << "empty? : " << (q3.empty() ? "yes" : "no") << endl; 
    cout << "top    : " << q3.top() << endl;
    cout << "size   : " << q3.size() << endl; 
    cout << endl;
}
