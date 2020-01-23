//
//  main.cpp
//  Reverse_Linked_List_II
//
//  Created by Sharon He on 1/23/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(head==nullptr||head->next==nullptr)return head;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *prev = dummyHead, *cur = head, *tail, *q, *last;
        
        int i;
        for(i = 0; cur&&i<m-1; i++){
            prev = cur;
            cur = cur->next;
        }
        last = cur;
        tail = prev;
        while(cur&&i<n){
            q = prev;
            prev = cur;
            cur = cur->next;
            prev->next = q;
            i++;
        }
        last->next = cur;
        tail->next = prev;
        
        ListNode *newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
