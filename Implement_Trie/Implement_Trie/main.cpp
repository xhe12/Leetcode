//
//  main.cpp
//  Implement_Trie
//
//  Created by Sharon He on 2/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode{
public:
    unordered_map<char,TrieNode*> nodeMap;
    bool EOW;//indicates if this TrieNode is the end of the word
    TrieNode():EOW(false){}
};

class Trie {
    TrieNode *root;
    /** Initialize your data structure here. */
public:
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(char c:word){
            if((cur->nodeMap).find(c)==(cur->nodeMap).end()){
                TrieNode *newNode = new TrieNode();
                cur->nodeMap[c] = newNode;
                cur = newNode;
            }
            else{
                cur = (cur->nodeMap).at(c);
            }
        }
        cur->EOW = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for(char c:word){
            if((cur->nodeMap).find(c)==(cur->nodeMap).end()){
                return false;
            }
            else{
                cur = (cur->nodeMap).at(c);
            }
        }
        return cur->EOW;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(char c: prefix){
            if((cur->nodeMap).find(c)==(cur->nodeMap).end()){
                return false;
            }
            else{
                cur = (cur->nodeMap).at(c);
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Trie trie;
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;
    cout<<trie.startsWith("app")<<endl;
    return 0;
}
