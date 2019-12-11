//
//  main.cpp
//  Leetcode #138: Copy_List_With_Random_Pointer
//
//  Created by Sharon He on 12/10/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
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
        if(head==NULL)
        {
            return NULL;
        }
        Node* headCopy = new Node(head->val,NULL,NULL);
        Node* curCopy = headCopy;
        Node* curNode = head;
        Node* nextNode;
        while(curNode!=NULL)
        {
            nextNode = curNode->next;
            curNode->next = curCopy;
            curCopy->next = nextNode;
            if(nextNode!=NULL)
            {
                curCopy = new Node(nextNode->val,NULL,NULL);
            }
            curNode = nextNode;
        }
        
        curNode = head;
        curCopy = head;
        while(curNode!=NULL)
        {
            curCopy = curNode->next;
            
            if(curNode->random!=NULL)
            {
                curCopy->random = curNode->random->next;
            }
            else
            {
                curCopy->random = NULL;
            }
            if(curCopy->next!=NULL)
            {
                curNode->next = curCopy->next;
                curCopy->next = curCopy->next->next;
            }
            else
            {
                curNode->next = NULL;
            }
            
            curNode = curNode->next;
        }
            
        return headCopy;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Node* node1 = new Node(1,NULL,NULL);
    Node* node2 = new Node(2,NULL,NULL);
    Node* node3 = new Node(3,NULL,NULL);
    node1->next = node2;
    node2->next = node3;
    node2->random = node1;
    node3->random = node1;
    
    Solution sol;
    Node* node1Copy = sol.copyRandomList(node1);
    cout<<node1Copy->val<<endl;
    cout<<node1Copy->next->val<<endl;
    cout<<node1Copy->next->next->val<<endl;
    return 0;
}
