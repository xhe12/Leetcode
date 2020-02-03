//
//  main.cpp
//  Min_Stack
//
//  Created by Sharon He on 1/31/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <exception>
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node *prev;
    
    Node(int _val, Node *prevNode):val(_val), prev(prevNode),next(NULL){}
    Node():next(NULL),prev(NULL){}
};
class MinStack {
    Node *dummyTop;
    Node *dummyTail;
public:
    /** initialize your data structure here. */
    MinStack() {
        dummyTop = new Node();
        dummyTail = dummyTop;
    }
    
    ~MinStack(){
        Node *cur = dummyTop, *nextNode = cur->next;
        while(nextNode!=nullptr){
            delete cur;
            cur = nextNode;
            nextNode = cur->next;
        }
        delete cur;
    }
    
    void push(int x) {
        Node *newNode = new Node(x,dummyTail);
        dummyTail->next = newNode;
        dummyTail = newNode;
        return;
    }
    
    void pop() {
        if(dummyTail->prev!=nullptr){
            Node *curNode = dummyTail;
            dummyTail = dummyTail->prev;
            dummyTail->next = NULL;
            delete curNode;
        }
        return;
    }
    
    int top() {
        return dummyTail->val;
    }
    
    int getMin() {
        Node *curNode = dummyTop->next;
        int minVal;
        try{
            minVal = curNode->val;
        }
        catch(exception &e){
            cout<< e.what()<<endl;
        }
        while(curNode!=NULL){
            minVal = (minVal<curNode->val)?minVal:curNode->val;
            curNode = curNode->next;
        }
        return minVal;
    }
};

int main(int argc, const char * argv[]) {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(3);
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->top()<<endl;
    
    delete minStack;
    
    return 0;
}
