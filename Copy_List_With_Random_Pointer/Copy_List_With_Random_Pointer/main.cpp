//
//  main.cpp
//  Copy_List_With_Random_Pointer
//
//  Created by Sharon He on 1/21/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node() {}
    
    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){return nullptr;}
        unordered_map<Node*,Node*> nodesMap;
        Node* curNode = head;
        Node* dummyhead = new Node();
        Node* curCopy = dummyhead;
        while(curNode!=nullptr){
            Node* newNode = new Node();
            newNode->val = curNode->val;
            nodesMap[curNode] = newNode;
            curCopy->next = newNode;
            curCopy = curCopy->next;
            curNode = curNode->next;
        }
        curNode = head;
        while(curNode!=nullptr){
            curCopy = nodesMap[curNode];
            if(curNode->random!=nullptr){
                curCopy->random = nodesMap[curNode->random];
            }
            curNode = curNode->next;
        }
        Node* newHead = dummyhead->next;
        delete dummyhead;
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    Node* head = new Node();
    head->val = 1;
    head->next = new Node();
    head->random = head->next;
    Solution sol;
    Node* newHead = sol.copyRandomList(head);
    return 0;
}
