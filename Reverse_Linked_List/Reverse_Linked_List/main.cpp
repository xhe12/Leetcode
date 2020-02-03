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
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return;
        // find the middle;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *slow = dummyHead, *fast = dummyHead, *mid;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
        // reverse the order of ListNodes from slow->next;
        slow = NULL;
        fast = NULL;
        ListNode *cur = mid->next;
        mid->next = nullptr;
        
        while(cur!=nullptr){
            slow = fast;
            fast = cur;
            cur = cur->next;
            fast ->next = slow;
        }
        //merge the lists headed by head and fast;
        ListNode *l1 = head, *l2 = fast, *nextNode = head->next;
        while(nextNode!=nullptr){
            l1->next = l2;
            l1 = l2;
            l2 = nextNode;
            nextNode = l1->next;
        }
        l1->next = l2;
        delete dummyHead;
    }
    
    ListNode* findLocation(ListNode* &head, ListNode *prev, ListNode* node){
        if(node->val<=head->val){
            node->next = head;
            head = node;
            return prev;
        }
        ListNode *cur = head, *nextNode = head->next;
        while(nextNode!=nullptr){
            if(node->val<=nextNode->val){
                cur->next = node;
                node->next = nextNode;
                return prev;
            }
            else{
                cur = nextNode;
                nextNode = nextNode->next;
            }
        }
        cur->next = node;
        return node;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *prev = head, *cur = head->next, *nextNode = cur;
        while(nextNode!=nullptr){
            nextNode = cur->next;
            prev->next = NULL;
            cur->next = NULL;
            prev = findLocation(head,prev,cur);
            prev->next = nextNode;
            cur = nextNode;
        }
        
        return head;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> arr = {4,2,1,3};
    Solution sol;
    ListNode* head = sol.arrToListNode(arr);
    sol.insertionSortList(head);
    //ListNode* reversedHead = sol.reverseList(head);
    
    return 0;
}
