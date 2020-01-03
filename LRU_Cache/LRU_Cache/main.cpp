//
//  main.cpp
//  Leetcode #146: LRU_Cache
//
//  Created by Sharon He on 1/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
public:
    Node* next;
    Node* prev;
    int val;
    int key;
    Node(int k, int value):key(k),val(value){}
    Node(){}
};

class LRUCache{
    int cap;
    int count;
    Node* dummy_head;
    Node* dummy_tail;
    unordered_map<int,Node*> keyNodeMap;
    
    void printList(){
        Node* curNode = dummy_head;
        while(curNode!=NULL){
            cout<<curNode->val<<',';
            curNode = curNode->next;
        }
        cout<<endl;
    }
public:
    LRUCache(int capacity):cap(capacity),count(0){
        dummy_head = new Node;
        dummy_tail = new Node;
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }
    int get(int key){
        if(keyNodeMap.find(key)!=keyNodeMap.end()){
            if(dummy_head->next!=keyNodeMap[key]){
                Node* prevNode = keyNodeMap[key]->prev;
                Node* nextNode = keyNodeMap[key]->next;
                Node* secondNode = dummy_head->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                secondNode->prev = keyNodeMap[key];
                keyNodeMap[key]->next = secondNode;
                keyNodeMap[key]->prev = dummy_head;
                dummy_head->next = keyNodeMap[key];
            }
            printList();
            return keyNodeMap[key]->val;
        }
        return -1;
    }
    void put(int key, int value){
        int ifGetKey = get(key);
        if(ifGetKey>-1){
            keyNodeMap[key]->val = value;
        }
        else{
            if(count>=cap){
                Node* temp = dummy_tail->prev;
                temp->prev->next = dummy_tail;
                dummy_tail->prev = temp->prev;
                keyNodeMap.erase(temp->key);
                delete temp;
                count--;
            }
            Node* newNode = new Node(key,value);
            dummy_head->next->prev = newNode;
            newNode->next = dummy_head->next;
            dummy_head->next = newNode;
            newNode->prev = dummy_head;
            keyNodeMap[key] = newNode;
            count++;
            printList();
        }
    }
};

int main(int argc, const char * argv[]) {
    LRUCache* cache = new LRUCache(2);
    cache->get(2);
    cache->put(2,6);
    cache->get(1);       // returns 1
    cache->put(1, 5);    // evicts key 2
    cache->get(2);       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cache->get(1);       // returns -1 (not found)
    cache->get(3);       // returns 3
    cache->get(4);       // returns 4
    return 0;
}
