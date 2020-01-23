//
//  main.cpp
//  Partition_List
//
//  Created by Sharon He on 1/23/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

// 
#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
    ListNode(){}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *tail = dummyNode, *prev = head, *cur = head->next, *right;
        while(cur){
            if(prev->val>=x && cur->val < x){
                right = tail->next;
                tail->next = cur;
                prev->next = cur->next;
                cur->next = right;
                cur = prev->next;
                tail = tail->next;
            }
            else if(prev->val<x){
                if(cur->val<x){tail = cur;}
                else tail = prev;
                prev = cur;
                cur = cur->next;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }
};
int main(int argc, const char * argv[]) {
    ListNode* li0 = new ListNode(1);
    ListNode* li1 = new ListNode(4);
    ListNode* li2 = new ListNode(3);
    ListNode* li3 = new ListNode(2);
    ListNode* li4 = new ListNode(5);
    ListNode* li5 = new ListNode(2);
    li0->next = li1;
    li1->next = li2;
    li2->next = li3;
    li3->next = li4;
    li4->next = li5;
    
    Solution sol;
    ListNode* l = sol.partition(li0, 3);
    delete li0;
    delete li1;
    delete li2;
    delete li3;
    delete li4;
    delete li5;
    
    return 0;
}
