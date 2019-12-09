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
#include <unordered_set>
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
        unordered_set<Node*> processed;
        
        Node* nodeCopy = new Node(node->val,{});
        nodeCorr[node] = nodeCopy;
        correspondNodes(node,nodeCopy,nodeCorr,processed);
        
        return nodeCopy;
    }
    
    Node* cloneGraph_DFS_iterative(Node* node){
        
    }
    
    Node* cloneGraph_BFS_iterative(Node* node){
        
    }
    
    
private:
    void correspondNodes(Node* node,Node* nodeCopy,unordered_map<Node*,Node*> &nodeCorr,unordered_set<Node*> &processed)
    {
        if(processed.find(nodeCopy)!=processed.end())
        {
            return;
        }
        for(Node *x: node->neighbors)
        {
            if(nodeCorr.find(x)==nodeCorr.end())
            {
                Node* xCopy = new Node(x->val,{});
                nodeCorr[x] = xCopy;
            }
            nodeCopy->neighbors.push_back(nodeCorr[x]);
            //correspondNodes(x, xCopy, nodeCorr,processed);
        }
        processed.insert(nodeCopy);
        
        for(Node *x: node->neighbors)
        {
            correspondNodes(x, xCopy, nodeCorr,processed);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
