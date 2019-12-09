//
//  main.cpp
//  Leetcode #133: Clone_Graph
//
//  Created by Xuan He on 12/8/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> nodeCorr;
        
        Node* nodeCopy = new Node(node->val,{});
        
        correspondNodes(node,nodeCopy,nodeCorr);
        
        return nodeCopy;
    }
    
private:
    void correspondNodes(Node* node,Node* nodeCopy,unordered_map<Node*,Node*> &nodeCorr)
    {
        if(nodeCorr.find(node)!=nodeCorr.end())
        {
            return;
        }
        for(Node *x: node->neighbors)
        {
            
            Node* nodeCopy = new Node(x->val,{});
            node->neighbors.push_back(nodeCopy);
            correspondNodes(x, nodeCopy, nodeCorr);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
