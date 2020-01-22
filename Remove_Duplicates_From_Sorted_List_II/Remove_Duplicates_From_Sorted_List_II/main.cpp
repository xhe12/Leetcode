//
//  main.cpp
//  Remove_Duplicates_From_Sorted_List_II
//
//  Created by Sharon He on 1/22/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr){return head;}
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* curNode = dummyHead, *slowPtr = head, *fastPtr;
        while(slowPtr!=nullptr){
            fastPtr = slowPtr->next;
            if(fastPtr==nullptr || (fastPtr!=nullptr && fastPtr->val!=slowPtr->val)){
                curNode->next = slowPtr;
                curNode = slowPtr;
                slowPtr = slowPtr->next;
            }
            else{
                while(fastPtr!=nullptr && fastPtr->val==slowPtr->val){
                    ListNode *temp = fastPtr;
                    fastPtr = fastPtr->next;
                    delete temp;
                }
                ListNode *temp = slowPtr;
                slowPtr = fastPtr;
                delete temp;
            }
        }
        
        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};
int main(int argc, const char * argv[]) {
    ListNode *N1 = new ListNode(1);
    ListNode *N2 = new ListNode(2);
    ListNode *N3 = new ListNode(2);
    N1->next = N2;
    N2->next = N3;
    Solution sol;
    sol.deleteDuplicates(N1);
    return 0;
}
