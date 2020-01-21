//
//  main.cpp
//  Swap_Nodes_in_Pairs
//
//  Created by Sharon He on 1/21/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *temp=head;
        for(int i=0; i<k; i++){
            if(temp==NULL) return head;
            temp=temp->next;
        }
        temp=head;
        int i = 0;
        ListNode *p=NULL , *current=head , *q=NULL;
        while(i<k){
            q = p;
            p = current;
            current = current->next;
            p->next = q;
            i++;
        }
        head=p;
        temp->next= reverseKGroup(current, k);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
