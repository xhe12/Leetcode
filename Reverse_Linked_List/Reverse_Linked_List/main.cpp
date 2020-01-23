//
//  main.cpp
//  Reverse_Linked_List
//
//  Created by Sharon He on 1/23/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
   int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        
        ListNode *pTo = nullptr, *prev = nullptr, *cur = head;
        while(cur){
            pTo = prev;
            prev = cur;
            prev->next = pTo;
            cur = cur->next;
        }
        return prev;
    }
    ListNode* arrToListNode(vector<int> &arr){
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        for(int i = 0; i<arr.size();i++){
            ListNode *newNode = new ListNode(arr[i]);
            cur->next = newNode;
            cur = cur->next;
        }
        ListNode *newHead = dummyHead->next;
        delete dummyHead;
        
        return newHead;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> arr = {1,2,3,4,5};
    Solution sol;
    ListNode* head = sol.arrToListNode(arr);
    ListNode* reversedHead = sol.reverseList(head);
    return 0;
}
