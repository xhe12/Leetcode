//
//  main.cpp
//  Rotate_List
//
//  Created by Sharon He on 1/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>


 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k<=0){
            return head;
        }
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curNode = head;
        int count = 0;
        while(curNode!=NULL){
            curNode = curNode->next;
            count++;
        }
        int rotate = k%count;
        
        ListNode* secLastNode;
        ListNode* lastNode;
        
        for(int i = 0; i<rotate; i++){
            curNode = head;
            while(curNode->next->next != NULL){
                curNode = curNode->next;
            }
            secLastNode = curNode;
            lastNode = curNode->next;
            
            secLastNode->next = NULL;
            lastNode->next = head;
            head = lastNode;
        }
        return head;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
