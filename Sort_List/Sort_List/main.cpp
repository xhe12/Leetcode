//
//  main.cpp
//  Sort_List
//
//  Created by Sharon He on 1/22/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    ListNode* sortList(ListNode *head){
        if(head==nullptr||head->next==nullptr){return head;}
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head, *left,*right, *tail = dummy;
        int len = 0;
        while(cur){
            len++;
            cur=cur->next;
        }
        
        for(int step=1; step<=len; step<<=1){
            cur = dummy->next;
            tail = dummy;
            while(cur){
                left = cur;
                right = split(left,step);
                cur = split(right,step);
                tail = merge(left,right,tail);
            }
        }
        
        return dummy->next;
    }
    
    ListNode* split(ListNode *node,int step){
        if(node==nullptr){return nullptr;}
        for(int i = 1; node&&i<step; i++){
            node = node->next;
        }
        if(!node)return nullptr;
        
        return node->next;
    }
    ListNode* merge(ListNode* left, ListNode* right, ListNode* tail){
        
        return tail;
    }
};

/*
class List{
    
    ListNode *sortList(ListNode *head) {
        if(!head || !(head->next)) return head;
        
        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while(cur){
            length++;
            cur = cur->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < length; step <<= 1){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right,step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
private:
 
     // Divide the linked list into two lists,
     // while the first list contains first n ndoes
     // return the second list's head
 
    ListNode* split(ListNode *head, int n){
        //if(!head) return NULL;
        for(int i = 1; head && i < n; i++) head = head->next;
        
        if(!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
 
     // merge the two sorted linked list l1 and l2,
     // then append the merged sorted linked list to the node head
     // return the tail of the merged sorted linked list
 
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode *cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while(cur->next) cur = cur->next;
        return cur;
    }
};
*/

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
